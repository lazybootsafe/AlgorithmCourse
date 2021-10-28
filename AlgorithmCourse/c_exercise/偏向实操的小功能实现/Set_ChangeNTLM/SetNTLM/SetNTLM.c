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
	DWORD dwUserAccess = USER_FORCE_PASSWORD_CHANGE;
	NTSTATUS status = STATUS_INVALID_ACCOUNT_NAME, enumDomainStatus;
	DWORD i, domainEnumerationContext = 0, domainCountRetourned, * pRid, * pUse;
	PSAMPR_RID_ENUMERATION pEnumDomainBuffer;
	PSID domainSid;
	SAMPR_HANDLE hServerHandle, hDomainHandle, hUserHandle;

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

				NTSTATUS status = SamSetInformationUser(hUserHandle, UserInternal1Information, (PSAMPR_USER_INFO_BUFFER)pvArg);
				if (NT_SUCCESS(status))
					wprintf(L"\n[*] SetNTLM success!\n");
				else
					wprintf(L"[!] SamSetInformationUser: %08x\n", status);

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
	SAMPR_USER_INFO_BUFFER infos = { {{0x60, 0xba, 0x4f, 0xca, 0xdc, 0x46, 0x6c, 0x7a, 0x03, 0x3c, 0x17, 0x81, 0x94, 0xc0, 0x3d, 0xf6}, {0x7c, 0x1c, 0x15, 0xe8, 0x74, 0x11, 0xfb, 0xa2, 0x1d, 0x91, 0xa0, 0x81, 0xd4, 0xb3, 0x78, 0x61}, TRUE, FALSE, FALSE, FALSE,} };


	PCWCHAR szServer = L"TESTDC1.TESTAD.LOCAL";
	PCWCHAR szUser = L"test2";
	DWORD rid = 2106;
	RtlInitUnicodeString(&userName, szUser);
	RtlInitUnicodeString(&serverName, szServer);

	PCWCHAR newNTLM = L"ab29f733bf5e082d38cdca74f4c1c467";
	StringToHex(newNTLM, infos.Internal1.NTHash, sizeof(infos.Internal1.NTHash));

	ChangeNTLM(&serverName, &userName, rid, &infos);

	return 0;
}

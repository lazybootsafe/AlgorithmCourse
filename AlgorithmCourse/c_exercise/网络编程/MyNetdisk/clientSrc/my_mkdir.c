#include "../HeaderFile/client.h"
#include "../HeaderFile/unixhead.h"
#include "../HeaderFile/ctlno.h"
int my_mkdir(int sock_fd,int file_id,int user_id,const char* file_name)
{
    int ctl_num = CTL_MKDIR;
    send(sock_fd,&ctl_num,sizeof(int),0);
    send(sock_fd,&file_id,sizeof(int),0);
    send(sock_fd,&user_id,sizeof(int),0);
    int len = strlen(file_name);
    send(sock_fd,&len,sizeof(int),0);
    send(sock_fd,file_name,len,0);
    recv(sock_fd,&ctl_num,sizeof(int),0);
    if(ctl_num == FILE_NAME_AVAIABLE)
    {
        puts("mkdir success!");
    }
    else
    {
        puts("mkdir fail!");
    }
    return 0;
}

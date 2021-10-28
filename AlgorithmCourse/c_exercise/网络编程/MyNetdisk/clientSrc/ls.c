#include "../HeaderFile/client.h"
#include "../HeaderFile/unixhead.h"
#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/pthread_pool.h"

int ls(int sock_fd,int file_id)
{
    int ctl_num = CTL_LS;
    send(sock_fd,&ctl_num,sizeof(int),0);
    send(sock_fd,&file_id,sizeof(int),0);
    int len;
    char buf[4096];
    while(1)
    {
        memset(buf,0,sizeof(buf));
        recv(sock_fd,&len,sizeof(int),0);
        if(len == LS_FIN)
            break;
        recv_n_bytes(sock_fd,buf,len);
        char file_type = buf[0];
        int file_size = *(int*)(buf + 1);
        printf("%-32s",buf + 5);
        switch(file_type)
        {
        case 'd':
            printf("%-30s"," ");
            puts("directory");
            break;
        case 'f':
            printf("%20s%-10d"," ",file_size);
            puts("regular file");
            break;
        }
    }
    return 0;
}


#include "../HeaderFile/pthread_pool.h"
#include "../HeaderFile/unixhead.h"

int recv_n_bytes(int fd,void* buf,int len)
{
    int total = 0;
    int ret;
    while(total < len)
    {
        ret = recv(fd,(char*)buf + total,len - total,MSG_WAITALL);
        if(ret == 0)
        {
            printf("server disconnected!\n");
            return -1;
        }
        total += ret;
    }
    return 0;
}

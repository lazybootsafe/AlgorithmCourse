#include "../HeaderFile/pthread_pool.h"
int recv_client_all(int fd,void* buf,int len)
{
    int total = 0;
    int ret;
    while(total < len)
    {
        ret = recv(fd,(char*)buf + total,len - total,MSG_WAITALL);
        if(ret == 0)
        {
            return -1;
        }
        total += ret;
    }
    return 0;
}

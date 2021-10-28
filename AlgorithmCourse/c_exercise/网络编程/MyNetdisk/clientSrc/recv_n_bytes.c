#include "../HeaderFile/pthread_pool.h"

int recv_n_bytes(int sock_fd,void* buf,int len)
{
    int total = 0;
    while(total < len)
    {
        int ret = recv(sock_fd,buf,len - total,0);
        if(ret == 0)
        {
            return -1;
        }
        total += ret;
    }
    return 0;
}

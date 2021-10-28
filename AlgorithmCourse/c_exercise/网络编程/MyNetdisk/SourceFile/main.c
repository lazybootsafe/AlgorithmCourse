#include "../HeaderFile/unixhead.h"
#include "../HeaderFile/factory.h"
#include "../HeaderFile/tcp_link.h"
#include "../HeaderFile/pthread_pool.h"
#include "../HeaderFile/epoll_operation.h"
#include "../HeaderFile/database.h"
#include "../HeaderFile/queue.h"
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,5);
    factory_t fact;
    int epoll_fd = epoll_create(1);
    int ret = factory_init(&fact,atoi(argv[3]),atoi(argv[4]),epoll_fd);
    if(ret == -1) return -1;
    factory_start(&fact);

    int sfd = socket(AF_INET,SOCK_STREAM,0);
    ret = bind_sfd(argv + 1,sfd);
    ERROR_CHECK(ret,-1,"bind_sfd");

    add_fd_to_epoll(epoll_fd,sfd,EPOLLIN);
    struct epoll_event evs[10];

    listen(sfd,10);
    int ctl_num;
    while(1)
    {
        int readyNum = epoll_wait(epoll_fd,evs,10,-1);
        for(int i = 0; i < readyNum; ++i)
        {
            if(evs[i].data.fd == sfd)
            {
                int client_fd = accept(sfd,NULL,NULL);
                add_fd_to_epoll(epoll_fd,client_fd,EPOLLIN);
            }
            else
            {
                int client_fd = evs[i].data.fd;
                ret = recv(client_fd,&ctl_num,sizeof(int),MSG_WAITALL);
                if(ret == 0)
                {
                    printf("%d disconnected!\n",client_fd);
                    close(client_fd);
                    continue;
                }
                pthread_mutex_lock(&fact.mutex);
                que_push(&fact.que,client_fd,ctl_num);
                epoll_ctl(epoll_fd,EPOLL_CTL_DEL,client_fd,NULL);
                pthread_mutex_unlock(&fact.mutex);
                pthread_cond_signal(&fact.cond);
            }
        }
    }

    que_free(&fact.que);
    close(sfd);
    close(epoll_fd);
    return 0;
}

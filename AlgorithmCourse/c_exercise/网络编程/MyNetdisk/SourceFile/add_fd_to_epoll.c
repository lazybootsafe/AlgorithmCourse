#include "../HeaderFile/epoll_operation.h"
#include "../HeaderFile/unixhead.h"

void add_fd_to_epoll(int epoll_fd,int fd,enum EPOLL_EVENTS EVENT)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EVENT;
    epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd,&event);
}

#ifndef __EPOLL__OPER__PH
#define __EPOLL__OPER__PH
#include "unixhead.h"
// add fd to epoll 
void add_fd_to_epoll(int epoll_fd,int fd,enum EPOLL_EVENTS EVENT);

#endif

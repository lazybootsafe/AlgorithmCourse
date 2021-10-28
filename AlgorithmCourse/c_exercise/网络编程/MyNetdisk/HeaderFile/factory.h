#ifndef __FACTORY__H
#define __FACTORY__H
#include "unixhead.h"
#include "queue.h"
#include "database.h"
typedef void*(*function_t)(void*);

typedef struct
{
    int start_flag;
    int pthread_num;
    int epoll_fd;
    pthread_t* pthId_arr;
    function_t pthread_func;
    que_t que;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}factory_t;


int factory_init(factory_t *,int pthread_num,int que_capacity,int epoll_fd);
int factory_start(factory_t* p_fact);
#endif

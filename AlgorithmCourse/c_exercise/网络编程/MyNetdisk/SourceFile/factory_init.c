#include "../HeaderFile/factory.h"
#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/epoll_operation.h"
#include "../HeaderFile/queue.h"

void* thread_func(void*);

int factory_init(factory_t *p_fact,int pthread_num,int que_capacity,int epoll_fd)
{
    if(pthread_num < 1 || que_capacity < 1)
    {
        puts("pthread_num or que_capacity error!\n");
        return -1;
    }
    que_init(&p_fact->que,que_capacity);
    pthread_cond_init(&p_fact->cond,NULL);
    pthread_mutex_init(&p_fact->mutex,NULL);
    p_fact->epoll_fd = epoll_fd;
    p_fact->pthread_num = pthread_num;
    p_fact->pthId_arr = (pthread_t*)malloc(sizeof(pthread_t) * pthread_num);
    p_fact->pthread_func = thread_func;
    p_fact->start_flag = 0;
    return 0;
}

void* thread_func(void* p)
{
    factory_t *p_fact = (factory_t*)p;
    struct Queue_node* node = NULL;
    int client_fd = 0;
    int ctl_no;
    int epoll_fd = p_fact->epoll_fd;
    while(1)
    {
        pthread_mutex_lock(&p_fact->mutex);
        if(p_fact->que.que_size == 0)
        {
            pthread_cond_wait(&p_fact->cond,&p_fact->mutex);
        }
        int ret = que_pop(&p_fact->que,&node);
        pthread_mutex_unlock(&p_fact->mutex);
        if(ret == 0)
        {
            client_fd = node->client_fd;
            ctl_no = node->ctl_no;
            printf("client_fd = %d, ctl_No = %d\n",client_fd,ctl_no);
            free(node);
            switch(ctl_no)
            {
            case CTL_REGISTER:
                puts("sign up!");
                ret = client_register(client_fd);
                break;
            case CTL_LOGIN:
                ret = client_login(client_fd);
                break;
            case CTL_LS:
                ret = client_ls(client_fd);
                break;
            case CTL_CD:
                ret = client_cd(client_fd);
                break;
            case CTL_PWD:
                ret = client_pwd(client_fd);
                break;
            case CTL_PUT:
                ret = client_put(client_fd);
                break;
            case CTL_GET:
                ret = client_get(client_fd);
                break;
            case CTL_RM:
                ret = client_rm(client_fd);
                break;
            case CTL_MKDIR:
                ret = client_mkdir(client_fd);
                break;
            }
            if(ret != -1 && ctl_no != CTL_GET && ctl_no != CTL_PUT)
                add_fd_to_epoll(epoll_fd,client_fd,EPOLLIN);
        }
    }
    pthread_exit(NULL);
}

#include "../HeaderFile/unixhead.h"
#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/client.h"
#include "../HeaderFile/pthread_pool.h"

void* pthread_upload_func(void* arg)
{
    int sock_fd = *(int*)arg;
    int parent_id = *((int*)arg + 1);
    char* path = (char*)arg + sizeof(int) * 2;
    upload(sock_fd,path,parent_id);
    int ctl_num = NO_MORE_FILE;
    send(sock_fd,&ctl_num,sizeof(int),0);
    free(arg);
    pthread_exit(NULL);
}

int put(int sock_fd,char* path,int user_id,int file_id)
{
    
    char file_name[128] = {0};
    get_file_name(file_name,path);
    int ctl_num = CTL_PUT;
    send(sock_fd,&ctl_num,sizeof(int),0);
    int len = strlen(file_name);
    send(sock_fd,&user_id,sizeof(int),0);
    send(sock_fd,&file_id,sizeof(int),0);
    send(sock_fd,&len,sizeof(int),0);
    send(sock_fd,file_name,len,0);
    recv(sock_fd,&ctl_num,sizeof(int),0);
    if(ctl_num == PUT_FAIL)
    {
        puts("在当前目录有同名文件，不可上传");
        close(sock_fd);
        return -1;
    }
    char* buf = (char*)malloc(4096);
    memset(buf,0,4096);
    memcpy(buf,&sock_fd,sizeof(int));
    memcpy(buf + sizeof(int),&file_id,sizeof(int));
    strcpy(buf + sizeof(int) * 2,path);
    pthread_t id;
    pthread_create(&id,NULL,pthread_upload_func,(void*)buf);
    return 0;
}


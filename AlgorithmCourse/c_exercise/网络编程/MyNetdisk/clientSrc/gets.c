#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/client.h"
#include "../HeaderFile/unixhead.h"
#include "../HeaderFile/pthread_pool.h"

void* pthread_download_file(void* arg)
{
    int sock_fd = *(int*)arg;
    char buf[4096];
    while(1)
    {
        memset(buf,0,sizeof(buf));
        int len;
        int ret = recv(sock_fd,&len,sizeof(int),0);
        if(ret == 0)
            break;
        ret = recv_client_all(sock_fd,buf,len);
        if(ret == -1)
            break;
        char file_type = '\0';
        ret = recv(sock_fd,&file_type,sizeof(char),0);
        if(ret == 0)
            break;
        if(file_type == 'd')
        {
            puts(buf);
            struct stat st;
            ret = stat(buf,&st);
            if(ret == -1)
            {
                mkdir(buf,0777);
            }
            else if((st.st_mode & S_IFMT) != S_IFDIR)
            {
                unlink(buf);
                mkdir(buf,0777);
            }
        }
        else
        {
            ret = recv_server_file(sock_fd,buf);
            if(ret == -1)
                break;
        }
    }
    close(sock_fd);
    free(arg);
    pthread_exit(NULL);
}

int gets(int sock_fd,const char* file_name,const char* path,int file_id)
{
    int ctl_num = CTL_GET;
    send(sock_fd,&ctl_num,sizeof(int),0);
    char buf[4096];
    int file_name_len = strlen(file_name);
    int path_len = strlen(path);
    memcpy(buf ,&file_id,sizeof(int));
    memcpy(buf + sizeof(int),&file_name_len,sizeof(int));
    memcpy(buf + sizeof(int) * 2,&path_len,sizeof(int));
    memcpy(buf + sizeof(int) * 3,file_name,file_name_len);
    memcpy(buf + sizeof(int) * 3 + file_name_len,path,path_len);
    send(sock_fd,buf,sizeof(int) * 3 + file_name_len + path_len,0);

    pthread_t id;
    int * arg = (int*)malloc(sizeof(int));
    *arg = sock_fd;
    pthread_create(&id,NULL,pthread_download_file,arg);
    return 0;
}

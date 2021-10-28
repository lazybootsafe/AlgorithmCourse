#ifndef  __PTHREAD__POOL__
#define  __PTHREAD__POOL__

#include "queue.h"
#include "unixhead.h"

#define FILE_STORE_PATH "/home/vecpan/MyNetdisk"
typedef struct
{
    char file_type;
    int file_id;
    char md5[33];
    char file_name[128];
}download_file_t;

int recv_n_bytes(int fd,void* buf,int len);
int recv_file(int sock_fd,int file_fd, int file_size);
int recv_file_from_offset(int sock_fd,int file_fd,int file_size,int offset);
int recv_client_all(int fd,void* buf,int len);
int send_file_to_client(int client_fd,int parent_id,char* file_name,char* path,MYSQL* connect);
int send_file(int client_fd,int file_fd);

#endif

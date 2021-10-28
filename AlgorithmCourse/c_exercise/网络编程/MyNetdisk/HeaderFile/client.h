#ifndef __PH__CLIENT
#define __PH__CLIENT
#include "../HeaderFile/unixhead.h"
#define GETS_EXIST 0
#define GETS_NOT_EXIST 1
#define GETS_START_RECV 2
#define GETS_STOP_RECV 3
#define GETS_OVER 4

void show_menu1();
void show_menu2();
int sign_up(int sock_fd);
int login(int sock_fd);
int my_mkdir(int sock_fd,int file_id,int user_id,const char* file_name);
int ls(int sock_fd,int file_id);
int cd(int sock_fd,char* file_name,char* path,int* file_id);
int put(int newsfd,char* file_name,int user_id,int file_id);
int upload(int sock_fd,char* path,int parent_id);
int get_file_name(char* file_name,char* path);
int upload_file(int sock_fd,int file_fd,off_t size);
int gets(int sock_fd,const char* file_name,const char* path,int file_id);
int get_absolute_path(char* buf,int size);
int recv_server_file(int sock_fd,char* path);

#endif

#include "../HeaderFile/pthread_pool.h"
#include "../HeaderFile/ctlno.h"

int client_get(int client_fd)
{
    MYSQL* connect;
    connect_mysql(&connect);
    int file_id;
    int ret = recv(client_fd,&file_id,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    int file_name_len;
    ret = recv(client_fd,&file_name_len,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    int path_len;
    ret = recv(client_fd,&path_len,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    char file_name[128] = {0};
    ret = recv_client_all(client_fd,file_name,file_name_len);
    DISCON_CHECK(ret,-1,client_fd);
    char path[4096] = {0};
    ret = recv_client_all(client_fd,path,path_len);
    DISCON_CHECK(ret,-1,client_fd);
    printf("%s\n%s\n",file_name,path);
    send_file_to_client(client_fd,file_id,file_name,path,connect);
    close(client_fd);
    mysql_close(connect);
    return 0;
}

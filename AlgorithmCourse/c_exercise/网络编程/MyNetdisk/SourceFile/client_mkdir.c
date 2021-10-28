#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/pthread_pool.h"
#include "../HeaderFile/unixhead.h"

int client_mkdir(int client_fd)
{
    MYSQL* connect;
    connect_mysql(&connect);
    int file_id;
    int ret = recv(client_fd,&file_id,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    int user_id;
    ret = recv(client_fd,&user_id,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    char file_name[32] = {0};
    int len;
    ret = recv(client_fd,&len,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    ret = recv_client_all(client_fd,file_name,len);
    DISCON_CHECK(ret,-1,client_fd);
    char mysql_oper[256];
    sprintf(mysql_oper,"select * from File where user_id=%d and parent_id=%d and file_name='%s'",user_id,file_id
            ,file_name);
    unsigned int queryRet = mysql_query(connect,mysql_oper);
    if(queryRet)
    {
        printf("Mysql query error: %s\n",mysql_error(connect));
        return -1;
    }
    MYSQL_RES* res;
    res = mysql_store_result(connect);
    if(mysql_num_rows(res) == 0)
    {
        int flag = FILE_NAME_AVAIABLE;
        ret = send(client_fd,&flag,sizeof(int),MSG_NOSIGNAL);
        DISCON_CHECK(ret,-1,client_fd);
    }
    else
    {
        int flag= FILE_NAME_NO_AVAIABLE;
        ret = send(client_fd,&flag,sizeof(int),MSG_NOSIGNAL);
        DISCON_CHECK(ret,-1,client_fd);
        return 0;
    }
    mysql_free_result(res);
    sprintf(mysql_oper,"insert into File(parent_id,file_name,user_id,file_type) values(%d,'%s',%d,'d');"
            ,file_id,file_name,user_id);
    insert_to_mysql(mysql_oper,connect);
    mysql_close(connect);
    return 0;
}

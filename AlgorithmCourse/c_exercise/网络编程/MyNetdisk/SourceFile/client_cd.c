#include "../HeaderFile/pthread_pool.h"
#include "../HeaderFile/ctlno.h"

int client_cd(int client_fd)
{
    MYSQL* connect;
    connect_mysql(&connect);
    int file_id;
    int ret = recv(client_fd,&file_id,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    int ctl_num;
    ret = recv(client_fd,&ctl_num,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    char mysql_oper[256];
    if(ctl_num == CD_BACK)
    {
        sprintf(mysql_oper,"select parent_id from File where file_id=%d;",file_id);
    }
    else
    {
        int len;
        ret = recv(client_fd,&len,sizeof(int),0);
        DISCON_CHECK(ret,0,client_fd);
        char file_name[32] = {0};
        ret = recv_client_all(client_fd,file_name,len);
        DISCON_CHECK(ret,-1,client_fd);
        sprintf(mysql_oper,"select file_id from File where parent_id=%d and file_name='%s' and file_type='d';",file_id,file_name);
    }
    int queryResult = mysql_query(connect,mysql_oper);
    if(queryResult)
    {
        printf("%s\n",mysql_error(connect));
        return -1;
    }
    MYSQL_ROW row;
    MYSQL_RES* res;
    res = mysql_use_result(connect);
    row = mysql_fetch_row(res);
    if(row == NULL)
    {
        ctl_num = CD_FAIL;
    }
    else
    {
        ctl_num = CD_SUCCESS;
    }
    ret = send(client_fd,&ctl_num,sizeof(int),MSG_NOSIGNAL);
    DISCON_CHECK(ret,-1,client_fd);
    if(ctl_num == CD_SUCCESS)
    {
        file_id = atoi(row[0]);
        ret = send(client_fd,&file_id,sizeof(int),MSG_NOSIGNAL);
        DISCON_CHECK(ret,-1,client_fd);
    }
    mysql_free_result(res);
    mysql_close(connect);
    return 0;
}

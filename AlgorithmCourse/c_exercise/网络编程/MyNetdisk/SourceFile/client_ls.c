#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/pthread_pool.h"

int client_ls(int client_fd)
{
    int file_id;
    MYSQL* connect;
    connect_mysql(&connect);
    int ret = recv(client_fd,&file_id,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    char mysql_oper[256];
    sprintf(mysql_oper,"select file_type,file_size,file_name from File where parent_id=%d;",file_id);
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
    char buf[256];
    while(row != NULL)
    {
        memset(buf,0,sizeof(buf));
        buf[0] = *row[0];
        int file_size;
        if(row[1] != NULL)
            file_size = atoi(row[1]);
        else
            file_size = 0;
        memcpy(buf + 1,(const char*)&file_size,sizeof(int));
        sprintf(buf + 5,"%s",row[2]);
        int len = 5 + strlen(buf + 5);
        ret = send(client_fd,&len,sizeof(int),MSG_NOSIGNAL);
        DISCON_CHECK(ret,-1,client_fd);
        ret = send(client_fd,buf,len,MSG_NOSIGNAL);
        DISCON_CHECK(ret,-1,client_fd);
        row = mysql_fetch_row(res);
    }
    mysql_free_result(res);
    mysql_close(connect);

    int ctl_num = LS_FIN;
    ret = send(client_fd,&ctl_num,sizeof(int),MSG_NOSIGNAL);
    DISCON_CHECK(ret,-1,client_fd);
    return 0;
}

#include "../HeaderFile/pthread_pool.h"
#include "../HeaderFile/database.h"
#include "../HeaderFile/ctlno.h"

int client_put(int client_fd)
{
    MYSQL* connect;
    connect_mysql(&connect);
    int user_id;
    int ret = recv(client_fd,&user_id,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    int file_id;
    recv(client_fd,&file_id,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    int len;
    ret = recv(client_fd,&len,sizeof(int),0);
    DISCON_CHECK(ret,0,client_fd);
    char file_name[128] = {0};
    ret = recv_client_all(client_fd,file_name,len);
    DISCON_CHECK(ret,-1,client_fd);
    char mysql_oper[256] = {0};
    sprintf(mysql_oper,"select * from File where parent_id='%d' and file_name='%s' and user_id='%d'"
            ,file_id,file_name,user_id);
    MYSQL_RES* res = query(mysql_oper,connect);
    MYSQL_ROW row = mysql_fetch_row(res);
    int ctl_num;
    if(row == NULL)
    {
        ctl_num = PUT_SUCCESS;
    }
    else
    {
        ctl_num = PUT_FAIL;
    }
    mysql_free_result(res);
    ret = send(client_fd,&ctl_num,sizeof(int),MSG_NOSIGNAL);
    DISCON_CHECK(ret,-1,client_fd);
    // upload 
    while(1)
    {
        ret = recv(client_fd,&ctl_num,sizeof(int),0);
        DISCON_CHECK(ret,0,client_fd);
        if(ctl_num == NO_MORE_FILE)
            break;
        int parent_id;
        mode_t mode;
        ret = recv(client_fd,&mode,sizeof(mode_t),0);
        DISCON_CHECK(ret,0,client_fd);
        ret = recv(client_fd,&parent_id,sizeof(int),0);
        DISCON_CHECK(ret,0,client_fd);
        ret = recv(client_fd,&len,sizeof(int),0);
        DISCON_CHECK(ret,0,client_fd);
        ret= recv_client_all(client_fd,file_name,len);
        DISCON_CHECK(ret,-1,client_fd);
        file_name[len] = '\0';
        if((mode & S_IFMT) == S_IFDIR)
        {
            sprintf(mysql_oper,"insert into File(user_id,parent_id,file_name,file_type) values(%d,%d,'%s','d');"
                    ,user_id,parent_id,file_name);
            insert_to_mysql(mysql_oper,connect);
            sprintf(mysql_oper,"select file_id from File where file_name='%s' and user_id=%d and parent_id=%d;"
                    ,file_name,user_id,parent_id);
            res = query(mysql_oper,connect);
            row = mysql_fetch_row(res);
            int new_dir_id = atoi(row[0]);
            mysql_free_result(res);
            ret = send(client_fd,&new_dir_id,sizeof(int),0);
            DISCON_CHECK(ret,0,client_fd);
            continue;
        }
        off_t file_size;
        ret = recv(client_fd,&file_size,sizeof(off_t),0);
        DISCON_CHECK(ret,0,client_fd);
        char md5[33] = {0};
        ret = recv_client_all(client_fd,md5,32);
        DISCON_CHECK(ret,-1,client_fd);
        sprintf(mysql_oper,"select * from File where md5='%s';",md5);
        res = query(mysql_oper,connect);
        row = mysql_fetch_row(res);
        if(row == NULL)
        {
            ctl_num = PUT_NOT_EXIST;
        }
        else
        {
            ctl_num = PUT_EXIST;
        }
        mysql_free_result(res);
        sprintf(mysql_oper,"insert into File(parent_id,file_name,user_id,md5,file_size,file_type) values(%d,'%s',%d,'%s',%ld,'f');"
                ,parent_id,file_name,user_id,md5,file_size);
        insert_to_mysql(mysql_oper,connect);
        ret = send(client_fd,&ctl_num,sizeof(int),MSG_NOSIGNAL);
        DISCON_CHECK(ret,-1,client_fd);
        printf("ctl_num = %d\n",ctl_num);
        if(ctl_num == PUT_EXIST)
        {
            printf("hi");
            continue;
        }
        ret = recv(client_fd,&ctl_num,sizeof(int),0);
        DISCON_CHECK(ret,0,client_fd);
        if(ctl_num != PUT_SUCCESS)
        {
            sprintf(mysql_oper,"delete from File where parent_id=%d and file_name='%s';"
                    ,parent_id,file_name);
            insert_to_mysql(mysql_oper,connect);
            continue;
        }
        char file_path[4096] = {0};
        sprintf(file_path,"%s/%s",FILE_STORE_PATH,md5);
        int file_fd = open(file_path,O_RDWR|O_CREAT|O_EXCL,mode);
        DISCON_CHECK(file_fd,-1,client_fd);
        ret = recv_user_file(client_fd,file_fd,file_size);
        DISCON_CHECK(ret,-1,client_fd);
        close(file_fd);
        ret = send(client_fd,&ctl_num,sizeof(int),MSG_NOSIGNAL);
        DISCON_CHECK(ret,-1,client_fd);
    }
    close(client_fd);
    mysql_close(connect);
    return 0;
}

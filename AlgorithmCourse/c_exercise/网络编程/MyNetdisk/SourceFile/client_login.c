#include "../HeaderFile/pthread_pool.h"
#include "../HeaderFile/ctlno.h"

int client_login(int client_fd)
{
    MYSQL* connect;
    connect_mysql(&connect);
    int length;
    int ret;
    char user_name[32];
    char user_passwd[32];
    while(1)
    {
        ret = recv(client_fd,&length,sizeof(int),0);
        DISCON_CHECK(ret,-1,client_fd);
        ret = recv_client_all(client_fd,user_name,length);
        DISCON_CHECK(ret,-1,client_fd);
        ret = recv(client_fd,&length,sizeof(int),0);
        DISCON_CHECK(ret,-1,client_fd);
        ret = recv_client_all(client_fd,user_passwd,length);
        DISCON_CHECK(ret,-1,client_fd);
        ret = user_name_avaiable(user_name,connect);
        if(ret == 1)
        {
            int ctl_num = USER_NAME_NOTEX;
            ret = send(client_fd,&ctl_num,sizeof(int),MSG_NOSIGNAL);
            DISCON_CHECK(ret,-1,client_fd);
            continue;
        }
        if(is_match(user_name,user_passwd,connect) != 0)
        {
            int ctl_num = PASSWD_MISMATCHED;
            ret = send(client_fd,&ctl_num,sizeof(int),MSG_NOSIGNAL);
            DISCON_CHECK(ret,-1,client_fd);
            continue;
        }
        else
            break;
    }
    int ctl_num = LOGIN_SUCCESS;
    ret = send(client_fd,&ctl_num,sizeof(int),MSG_NOSIGNAL);
    DISCON_CHECK(ret,-1,client_fd);
    char mysql_oper[256];
    int user_id = get_user_id(mysql_oper,user_name,connect);
    ret = send(client_fd,&user_id,sizeof(int),MSG_NOSIGNAL);
    DISCON_CHECK(ret,-1,client_fd);
    int file_id = get_file_id(mysql_oper,user_id,connect);
    ret = send(client_fd,&file_id,sizeof(int),MSG_NOSIGNAL);
    DISCON_CHECK(ret,-1,client_fd);
    mysql_close(connect);
    return 0;
}

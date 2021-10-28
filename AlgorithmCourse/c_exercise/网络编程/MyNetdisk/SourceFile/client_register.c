#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/pthread_pool.h"
#include <crypt.h>

int client_register(int client_fd)
{
    MYSQL* connect;
    int ret = connect_mysql(&connect);
    char user_name[32] = {0};
    char user_passwd[32] = {0};
    int length;

    // user_name check
    ret = recv(client_fd,&length,sizeof(int),0);
    DISCON_CHECK(ret,-1,client_fd);
    ret = recv_client_all(client_fd,user_name,length);
    DISCON_CHECK(ret,-1,client_fd);

    int flag;
    while((ret = user_name_avaiable(user_name,connect)) != 1)
    {
        DISCON_CHECK(ret,-1,client_fd);
        memset(user_name,0,sizeof(user_name));
        flag = USER_NAME_NO_AVAIABLE;
        ret = send(client_fd,&flag,sizeof(int),MSG_NOSIGNAL);
        DISCON_CHECK(ret,-1,client_fd);
        ret = recv(client_fd,&length,sizeof(int),0);
        DISCON_CHECK(ret,-1,client_fd);
        ret = recv_client_all(client_fd,user_name,length);
        DISCON_CHECK(ret,-1,client_fd);
    }
    flag = USER_NAME_AVAIABLE;
    ret = send(client_fd,&flag,sizeof(int),MSG_NOSIGNAL);
    DISCON_CHECK(ret,-1,client_fd);


    // user_passwd no check
    ret = recv(client_fd,&length,sizeof(int),0);
    DISCON_CHECK(ret,-1,client_fd);
    ret = recv_client_all(client_fd,user_passwd,length);
    DISCON_CHECK(ret,-1,client_fd);

    char salt[32] = {0};
    strcpy(salt,"$6$");
    get_salt(salt + 3);

    char mysql_oper[256] = {0};

    void* crybuf = NULL;
    int cry_size = 0;
    crypt_ra(user_passwd,salt,&crybuf,&cry_size);
    sprintf(mysql_oper,"insert into User(user_name,salt,cryptpasswd) values('%s','%s','%s');"
            ,user_name,salt + 3,get_crypt_passwd((const char*)crybuf));
    insert_to_mysql(mysql_oper,connect);
    free(crybuf);
    int user_id = get_user_id(mysql_oper,user_name,connect);

    sprintf(mysql_oper,"insert into File(parent_id,file_name,user_id,file_type) values(0,'%d_dir',%d,'d')"
            ,user_id,user_id);
    insert_to_mysql(mysql_oper,connect);

    int file_id = get_file_id(mysql_oper,user_id,connect);
    update_user_table(mysql_oper,user_id,file_id,connect);

    mysql_close(connect);
    return 0;
}

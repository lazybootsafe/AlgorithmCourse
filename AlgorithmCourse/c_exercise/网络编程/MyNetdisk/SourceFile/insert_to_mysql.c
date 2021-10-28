#include "../HeaderFile/ctlno.h"
#include <crypt.h>

int insert_to_mysql(const char* mysql_oper,MYSQL* connect)
{
    int queryResult = mysql_query(connect,mysql_oper);
    if(queryResult)
    {
        printf("%s\n",mysql_error(connect));
        return -1;
    }
    return 0;
}
//int main()
//{
//    const char* user_name = "panhao";
//    MYSQL* connect = NULL;
//    int ret = connect_mysql(&connect);
//    if(ret == -1)
//        return - 1;
//    char mysql_oper[256] = {0};
//    void* crybuf = NULL;
//    int cry_size = 0;
//    crypt_ra("Ph981030","$6$TkyW.IGQJhxS8sNT",&crybuf,&cry_size);
//    sprintf(mysql_oper,"insert into User(user_name,salt,cryptpasswd) values('%s','%s','%s');"
//            ,user_name,"TkyW.IGQJhxS8sNT",get_crypt_passwd((const char*)crybuf));
//    insert_to_mysql(mysql_oper,connect);
//    free(crybuf);
//    int user_id = get_user_id(mysql_oper,user_name,connect);
//
//    sprintf(mysql_oper,"insert into File(parent_id,file_name,user_id,file_type) values(0,'%d_dir',%d,'d');"
//            ,user_id,user_id);
//    printf("%s\n",mysql_oper);
//    insert_to_mysql(mysql_oper,connect);
//
//    int file_id = get_file_id(mysql_oper,user_id,connect);
//    update_user_table(mysql_oper,user_id,file_id,connect);
//}

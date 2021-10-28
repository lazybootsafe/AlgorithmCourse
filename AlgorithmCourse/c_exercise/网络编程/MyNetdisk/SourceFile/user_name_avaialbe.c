#include "../HeaderFile/ctlno.h"

int user_name_avaiable(const char* user_name,MYSQL* connect)
{
    char buf[128];
    sprintf(buf,"select * from User where user_name='%s'",user_name);
    unsigned int queryRet = mysql_query(connect,buf);
    if(queryRet)
    {
        printf("Mysql query error: %s\n",mysql_error(connect));
        return -1;
    }
    MYSQL_RES* res;
    res = mysql_store_result(connect);
    return (mysql_num_rows(res) == 0)? 1: 0;
}

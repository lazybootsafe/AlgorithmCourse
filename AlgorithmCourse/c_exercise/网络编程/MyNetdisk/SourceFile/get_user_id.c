#include "../HeaderFile/ctlno.h"

int get_user_id(char* mysql_oper,const char* user_name,MYSQL* connect)
{
    sprintf(mysql_oper,"select user_id from User where user_name='%s'",user_name);
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
    int ret = atoi(row[0]);
    mysql_free_result(res);
    return ret;
}

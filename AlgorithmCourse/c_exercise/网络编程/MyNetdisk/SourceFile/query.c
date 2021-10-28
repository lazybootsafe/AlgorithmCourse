#include "../HeaderFile/database.h"

MYSQL_RES* query(char* mysql_oper,MYSQL* connect)
{
    int queryResult = mysql_query(connect,mysql_oper);
    if(queryResult)
    {
        printf("%s\n",mysql_error(connect));
        return NULL;
    }
    MYSQL_RES* res;
    res = mysql_use_result(connect);
    return res;
}

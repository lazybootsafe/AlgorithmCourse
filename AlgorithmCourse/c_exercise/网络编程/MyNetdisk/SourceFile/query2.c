#include "../HeaderFile/database.h"

MYSQL_RES* query2(char* mysql_oper,MYSQL* connect)
{
    int queryResult = mysql_query(connect,mysql_oper);
    if(queryResult)
    {
        printf("%s\n",mysql_error(connect));
        return NULL;
    }
    return mysql_store_result(connect);
}

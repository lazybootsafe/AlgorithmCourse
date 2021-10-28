#include "../HeaderFile/ctlno.h"

int update_user_table(char* mysql_oper,int user_id,int file_id,MYSQL* connect)
{
    sprintf(mysql_oper,"update User set dir_id=%d where user_id=%d;",file_id,user_id);
    int queryResult = mysql_query(connect,mysql_oper);
    if(queryResult)
    {
        printf("%s\n",mysql_error(connect));
        return -1;
    }
    return 0;
}

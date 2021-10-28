#include "../HeaderFile/ctlno.h"
#include <crypt.h>

int is_match(const char* user_name,const char* user_passwd,MYSQL* connect)
{
    char sha512[256] = {0};
    strcpy(sha512,"$6$");
    char mysql_oper[256];
    sprintf(mysql_oper,"select salt,cryptpasswd from User where user_name='%s'",user_name);
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
    sprintf(sha512 + 3,"%s",row[0]);
    void* crypt_add = NULL;
    int crypt_size = 0;
    crypt_ra(user_passwd,sha512,&crypt_add,&crypt_size);
    int len = strlen(sha512) + 1;
    sha512[len - 1] = '$';
    sprintf(sha512 + len,"%s",row[1]);
    mysql_free_result(res);
    int ret = strcmp(sha512,(const char*)crypt_add);
    return ret;
}



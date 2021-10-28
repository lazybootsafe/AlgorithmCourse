#ifndef __PH__DATABASE
#define __PH__DATABASE
#include <mysql/mysql.h>
#include <string.h>
#include <stdio.h>

int connect_mysql(MYSQL** connect);
MYSQL_RES* query(char* mysql_oper,MYSQL* connect);
MYSQL_RES* query2(char* mysql_oper,MYSQL* connect);

#endif

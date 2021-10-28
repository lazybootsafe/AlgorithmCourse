#ifndef __PH__CTL__NO
#define __PH__CTL__NO


#include <stdlib.h>
#include "../HeaderFile/unixhead.h"
#include "../HeaderFile/database.h"

#define CTL_LS 1
#define CTL_CD 2
#define CTL_PWD 3
#define CTL_PUT 4
#define CTL_GET 5
#define CTL_RM 6
#define CTL_MKDIR 7
#define CTL_DOWNLOAD 8
#define CTL_REGISTER 9
#define CTL_LOGIN 10

// register
#define USER_NAME_NO_AVAIABLE 0
#define USER_NAME_AVAIABLE 1

// login
#define LOGIN_FAIL 0
#define LOGIN_SUCCESS 1
#define USER_NAME_NOTEX 2
#define PASSWD_MISMATCHED 3

// mkdir
#define FILE_NAME_NO_AVAIABLE 0
#define FILE_NAME_AVAIABLE 1

// ls
#define LS_FIN 0

// cd
#define CD_BACK 0
#define CD_JMP 1
#define CD_FAIL 2
#define CD_SUCCESS 3

// put
#define PUT_FAIL 0
#define PUT_SUCCESS 1
#define MORE_FILE 2
#define NO_MORE_FILE 3
#define PUT_NOT_EXIST 4
#define PUT_EXIST 5
#define PUT_OVER 6

#define DISCON_CHECK(ret,num,client_fd) {if(ret == num){close(client_fd);return -1;}}

int client_ls(int client_fd);
int client_cd(int client_fd);
int client_pwd(int client_fd);
int client_put(int client_fd);
int client_get(int client_fd);
int client_rm(int client_fd);
int client_mkdir(int client_fd);
int client_register(int client_fd);
int client_login(int client_fd);

// register function
int user_name_avaiable(const char* user_name,MYSQL* connect);
void get_salt(char* str);
const char* get_crypt_passwd(const char* crybuf);
int insert_to_mysql(const char* mysql_oper,MYSQL* connect);
int get_user_id(char* mysql_oper,const char* user_name,MYSQL* connect);
int get_file_id(char* mysql_oper,int user_id,MYSQL* connect);
int update_user_table(char* mysql_oper,int user_id,int file_id,MYSQL* connect);

// login function
int is_match(const char* user_name,const char* user_passwd,MYSQL* connect);

// put function
void link_path(char* file_name);

#endif

#include "../HeaderFile/unixhead.h"
#include "../HeaderFile/pthread_pool.h"

int send_file_to_client(int client_fd,int file_id,char* file_name,char* path,MYSQL* connect)
{
    char buf[4096] = {0};
    sprintf(buf,"select file_id,md5,file_type from File where parent_id=%d and file_name='%s';"
            ,file_id,file_name);
    MYSQL_RES* res = query(buf,connect);
    MYSQL_ROW row = mysql_fetch_row(res);
    if(row == NULL)
        return 0;
    memset(buf,0,sizeof(buf));
    sprintf(buf + sizeof(int),"%s/%s",path,file_name);
    int len = strlen(buf +sizeof(int));
    memcpy(buf,&len,sizeof(int));
    buf[sizeof(int) + len] = *row[2];
    int ret = send(client_fd,buf,sizeof(int) + len + 1, MSG_NOSIGNAL);
    if(ret == -1)
        return -1;
    if(*row[2] == 'd')
    {
        file_id = atoi(row[0]);
        mysql_free_result(res);
        sprintf(buf,"select file_name from File where parent_id=%d;",file_id);
        res = query2(buf,connect);
        unsigned long num_rows = mysql_num_rows(res);
        if(num_rows == 0)
        {
            return 0;
        }
        char** file_name_arr = (char**)malloc(sizeof(char*)* num_rows);
        char* _file_name = (char*)malloc(sizeof(char) * 128 * num_rows);
        memset(_file_name,0,sizeof(char) * 128 * num_rows);
        for(unsigned long i = 0; i < num_rows;++i)
        {
            row = mysql_fetch_row(res);
            file_name_arr[i] = _file_name + i * 128;
            strcpy(file_name_arr[i],row[0]);
        }
        mysql_free_result(res);
        for(unsigned long i = 0; i < num_rows; ++i)
        {
            memset(buf,0,sizeof(buf));
            sprintf(buf,"%s/%s",path,file_name);
            ret = send_file_to_client(client_fd,file_id,file_name_arr[i],buf,connect);
            if(ret == -1)
                break;
        }
        free(file_name_arr);
        free(_file_name);
        return ret;
    }
    sprintf(buf,"%s/%s",FILE_STORE_PATH,row[1]);
    int file_fd = open(buf,O_RDWR);
    printf("file_fd = %d\n",file_fd);
    if(file_fd == -1)
    {
        puts(buf);
        mysql_free_result(res);
        return -1;
    }
    ret = send_file(client_fd,file_fd);
    mysql_free_result(res);
    close(file_fd);
    return ret;
}

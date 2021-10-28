#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/client.h"
#include "../HeaderFile/md5.h"
#include "../HeaderFile/unixhead.h"
int upload(int sock_fd,char* path,int parent_id)
{
    int ctl_num = MORE_FILE;
    send(sock_fd,&ctl_num,sizeof(int),0);
    struct stat st;
    stat(path,&st);
    send(sock_fd,&st.st_mode,sizeof(mode_t),0);
    send(sock_fd,&parent_id,sizeof(int),0);
    char dir_name[128] = {0};
    get_file_name(dir_name,path);
    int len = strlen(dir_name);
    send(sock_fd,&len,sizeof(int),0);
    send(sock_fd,dir_name,strlen(dir_name),0);
    if((st.st_mode & S_IFMT) == S_IFDIR)
    {
        int file_id;
        recv(sock_fd,&file_id,sizeof(int),0);
        DIR* pdir = opendir(path);
        struct dirent* file;
        char buf[4096] = {0};
        while((file = readdir(pdir)) != NULL)
        {
            if(strcmp(file->d_name,".") == 0 || strcmp(file->d_name,"..") == 0)
            {
                continue;
            }
            memset(buf,0,4096);
            sprintf(buf,"%s/%s",path,file->d_name);
            upload(sock_fd,buf,file_id);
        }
        return 0;
    }
    send(sock_fd,&st.st_size,sizeof(off_t),0);
    char md5[33] = {0};
    compute_file_md5(path,md5,st.st_size);
    send(sock_fd,md5,32,0);
    recv(sock_fd,&ctl_num,sizeof(int),0);
    if(ctl_num == PUT_NOT_EXIST)
    {
        int file_fd = open(path,O_RDWR);
        if(file_fd == -1)
        {
            perror(path);
            ctl_num = PUT_FAIL;
            send(sock_fd,&ctl_num,sizeof(int),0);
            return 0;
        }
        else
        {
            ctl_num = PUT_SUCCESS;
            send(sock_fd,&ctl_num,sizeof(int),0);
        }
        int ret = sendfile(sock_fd,file_fd,NULL,st.st_size);
        ERROR_CHECK(ret,-1,"sendfile");
        recv(sock_fd,&ctl_num,sizeof(int),0);
        close(file_fd);
    }
    return 0;
}

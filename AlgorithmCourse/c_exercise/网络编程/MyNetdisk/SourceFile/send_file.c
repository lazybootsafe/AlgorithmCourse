#include "../HeaderFile/pthread_pool.h"
#include "../HeaderFile/client.h"
#include "../HeaderFile/md5.h"
int send_file(int client_fd,int file_fd)
{
    struct stat st;
    fstat(file_fd,&st);
    int ret = send(client_fd,&st,sizeof(struct stat),MSG_NOSIGNAL);
    if(ret == -1)
        return -1;
    int ctl_num = -1;
    ret = recv(client_fd,&ctl_num,sizeof(int),0);
    if(ret == 0)
        return -1;
    if(ctl_num == GETS_NOT_EXIST)
    {
        ret = recv(client_fd,&ctl_num,sizeof(int),0);
        if(ret == 0 || ctl_num == GETS_STOP_RECV)
            return -1;
        sendfile(client_fd,file_fd,NULL,st.st_size);
        recv(client_fd,&ctl_num,sizeof(int),0);
    }
    if(ctl_num == GETS_EXIST)
    {
        ret = recv(client_fd,&ctl_num,sizeof(int),0);
        if(ret == 0 || ctl_num == GETS_STOP_RECV)
            return -1;
        ret = recv_client_all(client_fd,&st,sizeof(struct stat)); 
        if(ret == -1) return -1;
        char md5[33] = {0};
        compute_file_md5_2(file_fd,md5,st.st_size);
        puts(md5);
        ret = send(client_fd,md5,32,MSG_NOSIGNAL);
        if(ret == -1) return -1;
        int offset_bak = 0;
        ret = recv(client_fd,&offset_bak,sizeof(int),0);
        if(ret == 0) return -1;
        off_t offset = offset_bak;
        fstat(file_fd,&st);
        lseek(file_fd,offset,SEEK_SET);
        sendfile(client_fd,file_fd,&offset,st.st_size);
        recv(client_fd,&ctl_num,sizeof(int),0);
    }
    return 0;
}

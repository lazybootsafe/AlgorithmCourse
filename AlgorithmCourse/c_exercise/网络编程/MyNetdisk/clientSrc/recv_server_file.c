#include "../HeaderFile/client.h"
#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/md5.h"
#include "../HeaderFile/pthread_pool.h"
int recv_server_file(int sock_fd,char* path)
{
    puts(path);
    struct stat st;
    recv_n_bytes(sock_fd,&st,sizeof(struct stat));
    int ret = access(path,F_OK);
    int ctl_num = -1;
    if(ret == -1)
    {
        ctl_num = GETS_NOT_EXIST;
        send(sock_fd,&ctl_num,sizeof(int),0);
        int file_fd = open(path,O_RDWR|O_CREAT|O_EXCL,st.st_mode); 
        if(file_fd == -1)
        {
            perror(path);
            ctl_num = GETS_STOP_RECV;
            send(sock_fd,&ctl_num,sizeof(int),0);
            return -1;
        }
        else
        {
            ctl_num = GETS_START_RECV;
            send(sock_fd,&ctl_num,sizeof(int),0);
            recv_file(sock_fd,file_fd,st.st_size);
            close(file_fd);
            ctl_num = GETS_OVER;
            send(sock_fd,&ctl_num,sizeof(int),0);
        }

    }
    else
    {
        ctl_num = GETS_EXIST;
        send(sock_fd,&ctl_num,sizeof(int),0);
        int file_fd = open(path,O_RDWR|O_CREAT|O_EXCL,st.st_mode); 
        if(file_fd == -1)
        {
            perror(path);
            ctl_num = GETS_STOP_RECV;
            send(sock_fd,&ctl_num,sizeof(int),0);
            return -1;
        }
        else
        {
            ctl_num = GETS_START_RECV;
            send(sock_fd,&ctl_num,sizeof(int),0);
            fstat(file_fd,&st);
            send(sock_fd,&st,sizeof(struct stat),0);
            char md5[33] = {0};
            char server_md5[33] = {0};
            compute_file_md5(path,md5,st.st_size);
            recv_client_all(sock_fd,server_md5,32);
            puts(md5);
            puts(server_md5);
            int offset = 0;
            if(strcmp(md5,server_md5) == 0)
            {
                offset = st.st_size;
            }
            send(sock_fd,&offset,sizeof(int),0);
            recv_file_from_offset(sock_fd,file_fd,st.st_size,offset);
            close(file_fd);
            ctl_num = GETS_OVER;
            send(sock_fd,&ctl_num,sizeof(int),0);
        }

    }
    return 0;
}

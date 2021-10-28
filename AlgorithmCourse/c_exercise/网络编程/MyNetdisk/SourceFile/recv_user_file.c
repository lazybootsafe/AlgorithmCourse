#include "../HeaderFile/unixhead.h"
int recv_user_file(int client_fd,int file_fd,off_t file_size)
{
    int total = 0;
    int pipefd[2];
    int ret = pipe(pipefd);
    ERROR_CHECK(ret,-1,"pipe");
    while(total < file_size)
    {
        ret = splice(client_fd,NULL,pipefd[1],NULL,4096,SPLICE_F_MOVE|SPLICE_F_MORE);
        ERROR_CHECK(ret,-1,"splice");
        ret = splice(pipefd[0],NULL,file_fd,NULL,ret,SPLICE_F_MOVE|SPLICE_F_MORE);
        ERROR_CHECK(ret,-1,"splice");
        total += ret;
    }
    return 0;
}

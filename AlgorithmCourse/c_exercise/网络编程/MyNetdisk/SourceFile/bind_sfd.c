#include "../HeaderFile/tcp_link.h"
#include "../HeaderFile/unixhead.h"

int bind_sfd(char** arg,int sfd)
{
    struct sockaddr_in server_addr;
    server_addr.sin_addr.s_addr = inet_addr(arg[0]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(arg[1]));
    int ret = bind(sfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    return ret;
}

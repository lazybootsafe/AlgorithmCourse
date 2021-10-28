#include "../HeaderFile/unixhead.h"
#include "../HeaderFile/client.h"
#include "../HeaderFile/ctlno.h"

int sign_up(int sock_fd)
{
    int ctl_num = CTL_REGISTER;
    send(sock_fd,&ctl_num,sizeof(int),0);

    int ret;
    char user_name[32];
    while(1)
    {
        rewind(stdin);
        memset(user_name,0,sizeof(user_name));
        printf("user name: ");
        ret = scanf("%s",user_name);
        if(ret == -1)
            exit(0);
        user_name[31] = '\0';
        int len = strlen(user_name);
        if(len < 5)
        {
            puts("user name too short!");
            continue;
        }
        send(sock_fd,&len,sizeof(int),0);
        send(sock_fd,user_name,len,0);
        recv(sock_fd,&ctl_num,sizeof(int),0);
        if(ctl_num == USER_NAME_NO_AVAIABLE)
        {
            puts("user name has been used!");
            continue;
        }
        else
            break;
    }
    char user_passwd[32];
    while(1)
    {
        rewind(stdin);
        memset(user_passwd,0,sizeof(user_name));
        printf("password: ");
        system("stty raw -echo");
        ret = scanf("%s",user_passwd);
        system("stty -raw echo");
        printf("\n");
        if(ret == -1)
            exit(0);
        user_passwd[31] = '\0';
        int len = strlen(user_passwd);
        if(len < 5)
        {
            puts("password too short!");
            continue;
        }
        send(sock_fd,&len,sizeof(int),0);
        send(sock_fd,user_passwd,len,0);
        break;
    }
    return 0;
}

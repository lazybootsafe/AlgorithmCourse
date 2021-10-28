#include "../HeaderFile/client.h"
#include "../HeaderFile/ctlno.h"
#include "../HeaderFile/unixhead.h"

int login(int sock_fd)
{
    char user_name[32];
    char user_passwd[32];
    int ctl_num = CTL_LOGIN;
    send(sock_fd,&ctl_num,sizeof(int),0);
    while(1)
    {
        rewind(stdin);
        memset(user_name,0,sizeof(user_name));
        memset(user_name,0,sizeof(user_passwd));
        printf("user name: ");
        scanf("%s",user_name);
        rewind(stdin);
        printf("password: ");
        system("stty raw -echo");
        scanf("%s",user_passwd);
        system("stty -raw echo");
        printf("\n");
        user_name[31] = '\0';
        user_passwd[31] = '\0';
        int len = strlen(user_name);
        send(sock_fd,&len,sizeof(int),0);
        send(sock_fd,user_name,len,0);
        len = strlen(user_passwd);
        send(sock_fd,&len,sizeof(int),0);
        send(sock_fd,user_passwd,len,0);
        recv(sock_fd,&ctl_num,sizeof(int),0);
        switch(ctl_num)
        {
        case PASSWD_MISMATCHED:
            puts("incorrect password or user name");
            return -1;
        case USER_NAME_NOTEX:
            puts("user name not exist");
            return -1;
        case LOGIN_SUCCESS:
            return 0;
        default:
            puts("unknown error");
            return -1;
        }
    }
    return 0;
}

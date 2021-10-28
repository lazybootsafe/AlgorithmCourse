#include "../HeaderFile/unixhead.h"
#include "../HeaderFile/client.h"
#include "../HeaderFile/pthread_pool.h"
#include "../HeaderFile/ctlno.h"
int main(int argc,char* argv[])
{
    // link to server
    ARGS_CHECK(argc,3);
    int sfd = socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(sfd,-1,"socket");
    struct sockaddr_in server_addr;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_family = AF_INET;
    int ret = connect(sfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    ERROR_CHECK(ret,-1,"connect");

    int user_select = 0;
    int flag = 1;
    while(flag)
    {
        show_menu1();
        ret = scanf("%d",&user_select);
        rewind(stdin);
        if(ret == -1)
            return 0;
        switch(user_select)
        {
        case 1:
            sign_up(sfd);
            break;
        case 2:
            flag = login(sfd);
            break;
        default:
            puts("Enter error operation number!");
            break;
        }
    }
    int user_id;
    recv(sfd,&user_id,sizeof(int),0);
    int file_id;
    recv(sfd,&file_id,sizeof(int),0);
    flag = 1;
    char buf[4096];
    char path[4096] = {0};
    path[0] = '/';
    while(flag)
    {
        memset(buf,0,sizeof(buf));
        printf("Enter a command: ");
        scanf("%s",buf);
        if(strcmp(buf,"ls") == 0)
        {
            ls(sfd,file_id);
        }
        else if(strcmp(buf,"pwd") == 0)
        {
            puts(path);
        }
        else if(strcmp(buf,"mkdir") == 0)
        {
            memset(buf,0,sizeof(buf));
            scanf("%s",buf);
            rewind(stdin);
            my_mkdir(sfd,file_id,user_id,buf);
        }
        else if(strcmp(buf,"cd") == 0)
        {
            memset(buf,0,sizeof(buf));
            scanf("%s",buf);
            rewind(stdin);
            if(strcmp(buf,"..") == 0 && strlen(path) == 1)
            {
                puts("/");
                continue;

            }
            ret = cd(sfd,buf,path,&file_id);
            if(ret == 0)
            {
                puts(path);
            }
            else
            {
                puts("no such directory");
            }
        }
        else if(strcmp(buf,"puts") == 0)
        {
            memset(buf,0,sizeof(buf));
            scanf("%s",buf);
            rewind(stdin);
            struct stat st_stat;
            ret = stat(buf,&st_stat);
            if(ret == -1)
            {
                perror("");
                continue;
            }
            if((st_stat.st_mode & S_IFMT) == S_IFDIR)
            {
                get_absolute_path(buf,sizeof(buf));
            }
            else
            {
                link_path(buf);
            }
            int newsfd = socket(AF_INET,SOCK_STREAM,0);
            ERROR_CHECK(sfd,-1,"socket");
            int ret = connect(newsfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
            ERROR_CHECK(ret,-1,"connect");
            put(newsfd,buf,user_id,file_id);
        }
        else if(strcmp(buf,"gets") == 0)
        {
            memset(buf,0,sizeof(buf));
            scanf("%s%s",buf + sizeof(buf) / 2,buf);
            rewind(stdin);
            struct stat st_stat;
            ret = stat(buf,&st_stat);
            if(ret == -1)
            {
                perror("");
                continue;
            }
            if((st_stat.st_mode & S_IFMT) != S_IFDIR)
            {
                puts("Not effective directory!"); 
                continue;
            }
            get_absolute_path(buf,sizeof(buf)/ 2);
            int newsfd = socket(AF_INET,SOCK_STREAM,0);
            ERROR_CHECK(sfd,-1,"socket");
            int ret = connect(newsfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
            ERROR_CHECK(ret,-1,"connect");
            gets(newsfd,buf + sizeof(buf)/2,buf,file_id);
        }

    }
    close(sfd);
}

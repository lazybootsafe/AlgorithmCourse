#include "../HeaderFile/client.h"
#include "../HeaderFile/unixhead.h"
int get_absolute_path(char* buf,int size)
{              
    char* oldpath = getcwd(NULL,0);
    chdir(buf);
    char* newpath = getcwd(NULL,0);
    memset(buf,0,size);
    strcpy(buf,newpath);
    chdir(oldpath);
    free(oldpath);
    free(newpath);
    return 0;
}

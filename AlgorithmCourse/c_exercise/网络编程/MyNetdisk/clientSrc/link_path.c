#include "../HeaderFile/ctlno.h"
void link_path(char* file_name)
{
    char tmp[256] = {0};
    strcpy(tmp,file_name);
    char* path = getcwd(NULL,0);
    sprintf(file_name,"%s/%s",path,tmp);
    free(path);
}

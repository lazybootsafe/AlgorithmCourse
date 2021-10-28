#include "../HeaderFile/client.h"
#include "../HeaderFile/unixhead.h"
int get_file_name(char* file_name,char* path)
{
    int i;
    for(i = strlen(path) - 1; path[i] != '/'; --i);
    strcpy(file_name,path + i + 1);
    return 0;
}

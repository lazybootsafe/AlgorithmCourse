#include "../HeaderFile/ctlno.h"

const char* get_crypt_passwd(const char* crybuf)
{
    int i; 
    int num = 0;
    for(i = 0; num != 3; ++i)
    {
        if(crybuf[i] == '$')
            ++num;
    }
    return crybuf + i;
}

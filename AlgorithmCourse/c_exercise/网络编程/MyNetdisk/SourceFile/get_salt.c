#include "../HeaderFile/ctlno.h"

void get_salt(char* str)
{
    srand(time(NULL));
    for(int i = 0; i < 16; ++i)
    {
        switch(rand()%3)
        {
        case 0:
            str[i] = rand()%26 + 'a';
            break;
        case 1:
            str[i] = rand()%26 + 'A';
            break;
        case 2:
            str[i] = rand()%10 + '0';
            break;
        }   
    }
}

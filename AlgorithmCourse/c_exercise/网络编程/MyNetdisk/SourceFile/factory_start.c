#include "../HeaderFile/factory.h"
#include "../HeaderFile/unixhead.h"
int factory_start(factory_t* p_fact)
{
    if(p_fact->start_flag == 0)
    {
        for(int i = 0; i < p_fact->pthread_num; ++i)
        {
            pthread_create(p_fact->pthId_arr + i,NULL,p_fact->pthread_func,p_fact);
        }
        p_fact->start_flag = 1;
    }
    return 0;
}

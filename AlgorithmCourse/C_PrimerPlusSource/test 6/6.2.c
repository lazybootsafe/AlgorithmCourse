#include<stdio.h> //��ӡ$,���е���һ��
int main(void)
{
    int a,b;   //aΪ��,bΪ��
    for(a=1;a<=5;a++)
    {
        for(b=0;b<a;b++)
        {
            printf("$");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

#include<stdio.h>    //��ӡA,���е���һ����ĸ�Ҳ��ظ�
int main(void)
{
    int a,b;      //aΪ��,bΪ��
    char c='A';
    for(a=1;a<=6;a++)
    {
        for(b=1;b<=a;b++)
        {
            printf("%c",c++);
        }
        printf("\n");
    }

    return 0;
}

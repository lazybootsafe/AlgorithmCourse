#include<stdio.h>    //��ӡF,���е���һ����ĸ����ĸ�ݼ���A
int main(void)
{
    int a,b;   //aΪ��,bΪ��
    char c='F';
    for(a=1;a<=6;a++)
    {
        for(b=0;b<a;b++)
        {
            printf("%c",c-b);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

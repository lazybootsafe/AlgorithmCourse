/* 1.��Ʋ�����һ���������������л�ȡ��n���ַ��������հס��Ʊ�
�������з������ѽ��������һ����������ĵ�ַ��������Ϊһ��������*/
#include <stdio.h>
#define SIZE 40
char *c_get(char *ar,int n);
int main(void)
{
    char ar[SIZE];

    c_get(ar,10);
    puts(ar);

    return 0;
}

char *c_get(char *ar,int n)
{
    int i=0;

    while(i<n)
        ar[i++]=getchar();
    ar[i]='\0';

    return ar;
}

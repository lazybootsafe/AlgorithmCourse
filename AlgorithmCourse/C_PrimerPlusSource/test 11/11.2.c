/*2.�޸Ĳ������ϰ1�ĺ�������n���ַ���ֹͣ�����ڶ�����1���հס�
�Ʊ�����з�ʱֹͣ���ĸ��������ĸ�ֹͣ������ֻʹ��scanf()��*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 80
char *c_get(char *ar,int n);
int main(void)
{
    char ar[SIZE];

    c_get(ar,10);
    puts(ar);

    system("pause");
    return 0;
}

char *c_get(char *ar,int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        *(ar+i)=getchar();
        if(ar[i]==' '|| ar[i]=='\t' ||ar[i]=='\n')
            break;
    }
    ar[i]='\0';

    return ar;
}

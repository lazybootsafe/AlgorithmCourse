/*4.��Ʋ�����һ�������������Ʊ����ϰ3��������ֻ���������ܵ�2��
����ָ���ɶ�ȡ������ַ�����*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 40
void word_get(char *ar,int n);
int main(void)
{
    char ar[SIZE];

    word_get(ar,10);
    puts(ar);

    system("pause");
    return 0;
}

void word_get(char *ar, int n)
{
    char ch;
    int i=0;

    while( isspace( ch=getchar() ) )
        continue;
    do
    {
        *(ar+i)=ch;
        i++;
    }

    while( !isspace(ch=getchar()) && i<(n-1) );
    ar[i]='\0';
}

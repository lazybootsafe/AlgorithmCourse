/*2.��дһ������ͨ�������в�����ȡ�����������ַ���������������
������ʹ�á��������&�������|�������^����������Զ������ַ�����
ʽ��ӡ���������޷�ʹ�������л���������ͨ������ʽ�ó����ȡ�ַ�
������*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int trans_2to10(char *st);//2�����ַ���ת10��������
char *trans_10to2(int num,char *ch);//10��������ת�������ַ���
void show(const char * st);//��ӡ�ַ���

int main(int argc,char *argv[])
{
    int x,y;
    char ch[CHAR_BIT*sizeof(int) + 1];

    if(argc!=3)
    {
        fprintf(stderr,"��������!\n");
        exit(EXIT_FAILURE);
    }

    x=trans_2to10(argv[1]);
    y=trans_2to10(argv[2]);

    printf("     ~%s     ��: ",argv[1]);
    show(trans_10to2(~x,ch));
    printf("     ~%s     ��: ",argv[2]);
    show(trans_10to2(~y,ch));
    printf("%s & %s��: ",argv[1],argv[2]);
    show(trans_10to2(x&y,ch));
    printf("%s | %s��: ",argv[1],argv[2]);
    show(trans_10to2(x|y,ch));
    printf("%s ^ %s��: ",argv[1],argv[2]);
    show(trans_10to2(x^y,ch));

    return 0;
}

int trans_2to10(char *st)
{
    int tol=0;

    while(*st)
        tol=(tol<<1)+(*st++-'0');

    return tol;
}

char *trans_10to2(int n,char *ch)
{
    int i;
    const static int size=CHAR_BIT*sizeof(int);

    for (i=size-1;i>=0;i--,n>>= 1)
        ch[i]=(01&n)+'0';//n&01����n���һλ��ֵ
    ch[size]='\0';

    return ch;
}

void show(const char *st)
{
    int i=0;

    while(st[i])
    {
        putchar(st[i]);
        if(++i%4==0 && st[i])
            putchar(' ');
    }
    printf("\n");
}


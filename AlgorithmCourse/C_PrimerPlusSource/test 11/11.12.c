/*12.��дһ�����򣬶�ȡ���룬ֱ������ EOF���������ĵ���������
д��ĸ����Сд��ĸ�������������������ַ�����ʹ��ctype.hͷ�ļ��е�
������*/
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int words=0,upper=0,lower=0;
    int punct=0,digit=0,inword=0;

    while((ch=getchar()) != EOF)
    {
        if(!isspace(ch) && (!ispunct(ch)) && !inword)
        {
            inword=1;
            words++;
        }
        if(isspace(ch) || ispunct(ch) && inword )
            inword=0;
        if(isupper(ch) )
            upper++;
        if(islower(ch))
            lower++;
        if(ispunct(ch))
            punct++;
        if(isdigit(ch))
            digit++;
    }
    printf("������: %d, ��д��ĸ��: %d, Сд��ĸ��: %d, �����: %d, ������: %d.\n",
            words, upper, lower, punct, digit);

    getchar();
    return 0;
}

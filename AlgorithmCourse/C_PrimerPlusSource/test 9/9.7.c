#include <stdio.h>/*7.��дһ���������ӱ�׼�����ж�ȡ�ַ���ֱ�������ļ���β������Ҫ
����ÿ���ַ��Ƿ�����ĸ������ǣ���Ҫ�������ĸ����ĸ���е���ֵλ
�á����磬c��C����ĸ���е�λ�ö���3���ϲ�һ����������һ���ַ���Ϊ
������������ַ���һ����ĸ�򷵻�һ����ֵλ�ã����򷵻�-1��*/
#include <string.h>
int GET_CH(char);
int main(void)
{
    char ch;

    printf("�����ı�:");
    while((ch=getchar()) != EOF)
    {
        if(GET_CH(ch)!=-1)
            printf("%c����ĸ �ڵ�%dλ.\n",ch,GET_CH(ch));
        else
        {
            putchar(ch);
            printf("������ĸ.\n");
        }

    }
    return 0;
}

int GET_CH(char ch)
{
    if(isalpha(ch))
        return tolower(ch)-'a'+1;
    else
        return -1;
}

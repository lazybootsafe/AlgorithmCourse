/*6.��дһ����Ϊis_within()�ĺ���������һ���ַ���һ��ָ���ַ�����
ָ����Ϊ���������βΡ����ָ���ַ����ַ����У��ú�������һ������ֵ
����Ϊ�棩�����򣬷���0����Ϊ�٣�����һ�������ĳ����в��Ըú�����
ʹ��һ��ѭ���������ṩ����ֵ��*/
#include <stdio.h>
#include <string.h>

#define SIZE 80
int is_within(char c,char *str);
int main(void)
{
    char str[SIZE];
    char ch;

    puts("����һ���ַ���(quit�뿪)��");
    while( strcmp(gets(str),"quit") )
    {
        puts("����һ����ĸ.");
        scanf("%c", &ch);
        while( getchar() != '\n')
            continue;
        if(is_within(ch,str))
            puts("�ҵ��ˣ�");
        else
            puts("û��!");
        puts("����һ���ַ���(quit�뿪)��");
    }
    puts("�ټ���");

    getchar();
    return 0;
}

int is_within(char c,char *str)
{
    int flag=0;
    int i=0;

    while(i++<strlen(str))
    {
        if(*str++ ==c)
        {
            flag=1;
            break;
        }
    }

    return flag;
}

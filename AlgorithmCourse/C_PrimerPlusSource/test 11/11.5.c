/*5.��Ʋ�����һ��������������1�������β�ָ�����ַ����������в�
�ҵ�2�������β�ָ�����ַ��״γ��ֵ�λ�á�����ɹ����ú�����ָ���
�ַ���ָ�룬������ַ�����δ�ҵ�ָ���ַ����򷵻ؿ�ָ�루�ú����Ĺ�
���� strchr()������ͬ������һ�������ĳ����в��Ըú�����ʹ��һ��ѭ��
�������ṩ����ֵ��*/
#include <stdio.h>
#include <string.h>

#define SIZE 80
char *search_string(char *str,char c);
int main(void)
{
    char str[SIZE];
    char ch;
    char *temp;

    puts("����һ���ַ���(quit�뿪)��");
    gets(str);
    while( strcmp(str,"quit") )
    {
        puts("����һ����ĸ.");
        scanf("%c", &ch);
        while( getchar() != '\n')
            continue;
        temp=search_string(str,ch);
        if(temp!=NULL)
            printf("�ҵ��ˣ���%c��ʼ���ַ�����%s.",ch,temp);
        else
            puts("û��!");
        puts("����һ���ַ���(quit�뿪)��");
        gets(str);
    }
    puts("�ټ���");

    getchar();
    return 0;
}

char *search_string(char *str,char c)
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
    if(flag)
        return str-1;
    else
        return NULL;
}

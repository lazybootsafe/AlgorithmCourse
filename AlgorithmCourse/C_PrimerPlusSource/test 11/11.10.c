/*10.��дһ����������һ���ַ�����Ϊ��������ɾ���ַ����еĿո�
��һ�������в��Ըú�����ʹ��ѭ����ȡ�����У�ֱ���û�����һ�п��С�
�ó���Ӧ��Ӧ�øú���ֻÿ��������ַ���������ʾ�������ַ�����*/
#include <stdio.h>
#include <string.h>
#define SIZE 40
char * s_gets(char * st, int n);
void delete_space(char * st);
int main(void)
{
    char str[SIZE];

    while (*s_gets(str, SIZE) != '\n')  //������н���
        delete_space(str);
    puts("Bye.");

    getchar();
    return 0;
}

//�Զ�����ַ������뺯��
char * s_gets(char * st, int n)
{
    int i = 0;

    printf("Input the first string (blank line to quit):\n");
    if (fgets(st, n, stdin) != NULL && st[0] != '\n')	//������ֵst������NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return st;
}

//ɾ���ո�ĺ���
void delete_space(char * st)
{
    char *temp=st;

    printf("\nThe original string is:\n");
    puts(st);
    while(*st)
    { //��������ո񣬺��������ַ���ǰ��һ��
        if(*st==' ')
            for(int i=0;st[i]!='\0';i++)
                st[i]=st[i+1];
        else
            st++;
    }
    puts("Now, the string is:");
    puts(temp);
}


/*8.��дһ����Ϊstring_in()�ĺ�������������ָ���ַ�����ָ����Ϊ��
���������2���ַ����а�����1���ַ������ú��������ص�1���ַ�����ʼ
�ĵ�ַ�����磬string_in("hats", "at")������hats��a�ĵ�ַ�����򣬸ú�����
�ؿ�ָ�롣��һ�������ĳ����в��Ըú�����ʹ��һ��ѭ���������ṩ����
ֵ��*/
#include <stdio.h>
#include <string.h>
#define SIZE 40
char * s_gets(char * st, int n);
char *string_in(char *s1,char *s2);
int main(void)
{
    char str1[SIZE];
    char str2[SIZE];

    printf("Input the first string (type quit to quit):\n");
    while (strcmp(s_gets(str1, SIZE), "quit"))		//����quit����
    {
        printf("Input the second string:\n");
        s_gets(str2, SIZE);
        if ( string_in(str1, str2) )
        {
            printf("Find!\n");
            puts( string_in(str1, str2) );
        }
        else
            printf("Can't find!\n");
        printf("Input the first string (type quit to quit):\n");
    }
    printf("Bye.\n");

    getchar();
    return 0;
}

//�Զ�����ַ������뺯��
char * s_gets(char * st, int n)
{
    int i = 0;

    if (fgets(st, n, stdin))	//������ֵst������NULL
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

//��s1�м��s2
char *string_in(char *s1,char *s2)
{
    int i;

    while(*s1) //����s1�ַ���
    {
        i=0;
        while (s1[i] == s2[i])//����Ƿ����
        {
            i++;
            if(!s2[i])//��ȵ����s2ĩβ��0.��0��1��return��
                return s1;
        }

        s1++;
    }
    return NULL;
}

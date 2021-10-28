/*9.��дһ�����������ַ����е��������䷴���ַ������档��һ������
�ĳ����в��Ըú�����ʹ��һ��ѭ���������ṩ����ֵ��*/
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define QUIT "quit"
char * s_gets(char * st, int n);
void reverse(char * st);
int main(void)
{
    char str[SIZE];

    printf("Input the first string (type quit to quit):\n");
    while (strcmp(s_gets(str, SIZE), QUIT))		//����quit����
    {
        reverse(str);
        puts(str);
        printf("Input the first string (type quit to quit):\n");
    }


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

//ʹ�ַ�������ĺ���
void reverse(char * st)
{
    unsigned int i;
    char temp;

    size_t length = strlen(st);
    for (i = 0; i < length / 2; i++)
    {
        temp = st[length - i -1];
        st[length - i - 1] = st[i];
        st[i] = temp;
    }
    st[length] = '\0';
}

//�������ֻ�ǵ����ӡ�����ַ�����������ʹ�ַ�������
//void reverse(char * st)
//{
//    int i=0;
//
//    for(i=strlen(st)-1;i>=0;i--)
//        putchar(st[i]);
//    st[0]='\0';
//}

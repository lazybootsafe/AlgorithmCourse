/*7.strncpy(s1, s2, n)������s2�е�n���ַ�������s1�У��ض�s2�������б�
Ҫ�Ļ���ĩβ��ӿ��ַ������s2�ĳ�����n�����n��Ŀ���ַ��������Կ�
�ַ���β���ú�������s1���Լ���дһ�������ĺ�������Ϊmystrncpy()����
һ�������ĳ����в��Ըú�����ʹ��һ��ѭ���������ṩ����ֵ��*/
#include <stdio.h>
#include <string.h>
#define SIZE 40
char *mystrncpy(char *s1,char *s2, int n);
int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    int num;

    printf("Input the first string (type quit to quit):\n");
    while (strcmp(gets(s1), "quit"))		//����quit����
    {
        printf("Input the second string:\n");
        gets(s2);
        printf("Input the number of char copied from s2: ");
        scanf("%d", &num);
        getchar();						//�����س�
        //��s2�ĳ��ȴ��ڻ����Ҫ�������ַ���ʱ��Ҫ��s1ĩβ����'\0',
        //����ע��Ҫ�ڵ��ú���֮ǰ����Ȼstrlen(s1)�ᷢ���ı�
        if (strlen(s2) >= num)
            s1[strlen(s1) + num] = '\0';
        puts(mystrncpy(s1, s2, num));	//�����������ַ���s1
        printf("Input the first string (type quit to quit):\n");
    }

    printf("Bye.\n");

    getchar();
    return 0;
}

char *mystrncpy(char *s1,char *s2, int n)
{
    int i;
    char *str=s1;

    while(*s1++)
        continue;//s1ָ��ָ��λ���Ѿ��������ַ�
    *--s1=*s2;
    for(i=1;i<n&&*s2;i++)
        *++s1=*++s2;

    return str;
}

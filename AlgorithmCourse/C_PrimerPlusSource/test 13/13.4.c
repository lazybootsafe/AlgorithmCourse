/*4.��дһ�����򣬰�˳������Ļ����ʾ���������г��������ļ���ʹ��
argc����ѭ���� */
#include <stdio.h>
#include <stdlib.h>  // �ṩ exit()��ԭ��
#define SIZE 40
int main(int argc, char *argv[])
{
    FILE *p;
    int i;
    char ch;

    for (i = 1; i < argc; i++)
    {
        printf("File %d:\n", i);
        if ((p = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", argv[i]);
            //exit(EXIT_FAILURE);
        }
        while ((ch = getc(p)) != EOF)
            putchar(ch);
        printf("\n");
    }

    return 0;
}

/*1.�޸ĳ����嵥13.1�еĳ���Ҫ����ʾ�û������ļ���������ȡ�û�
�������Ϣ����ʹ�������в����� */
#include <stdio.h>
#include <stdlib.h>  // �ṩ exit()��ԭ��
int main(void)
{
    int ch;      // ��ȡ�ļ�ʱ������ÿ���ַ��ĵط�
    FILE *fp;  // ���ļ�ָ�롱
    char st[20];
    unsigned long count = 0;
    printf("�������ļ�����");
    fscanf(stdin,"%s",st);
    if ((fp = fopen(st, "r")) == NULL)
    {
        printf("Can't open %s\n", st);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); // �� putchar(ch); ��ͬ
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %lu characters\n", st, count);
    return 0;
}

/*3.��дһ���ļ�����������ʾ�û������ı��ļ��������Ը��ļ�����
Ϊԭʼ�ļ���������ļ������ó���Ҫʹ�� ctype.h �е� toupper()��������
д�뵽����ļ�ʱ�������ı�ת���ɴ�д��ʹ�ñ�׼I/O���ı�ģʽ�� */
#include <stdio.h>
#include <stdlib.h>  // �ṩ exit()��ԭ��
#include <ctype.h>
#define SIZE 40
int main(void)
{
    FILE *fp_old,*fp_new;
    char name_old[SIZE],name_new[SIZE];
    char ch;

    printf("������Դ�ļ���:");
    gets(name_old);
    printf("�������½��ļ���:");
    gets(name_new);
    if((fp_old=fopen(name_old,"r")) ==NULL)
        fprintf(stderr,"���ܴ�%s�ļ�.\n",name_old);
    if((fp_new=fopen(name_new,"w")) ==NULL)
        fprintf(stderr,"���ܴ�%s�ļ�.\n",name_new);
    //��������
    while( (ch=getc(fp_old)) !=EOF )
        putc(toupper(ch),fp_new);
    fclose(fp_old);
    fclose(fp_new);

    return 0;
}

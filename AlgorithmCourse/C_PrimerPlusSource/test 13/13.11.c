/*11.��дһ�����򣬽������������в�������1��������һ���ַ�������
2��������һ���ļ�����Ȼ��ó�����Ҹ��ļ�����ӡ�ļ��а������ַ���
�������С���Ϊ�������������ж����������ַ��ģ�����Ҫʹ��fgets()����
��getc()��ʹ�ñ�׼C�⺯��strstr()��11.5.7�ڼ�Ҫ���ܹ�����ÿһ���в���
ָ���ַ����������ļ��е������ж�������255���ַ���*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //�ṩstrstr����
#define SIZE 256
int main (int argc,char *argv[])
{
    FILE *p;
    char ch[SIZE];
    int flag1,flag2;

    if(argc!=3)
    {
        fprintf(stderr, "�����в�����������\n.");
        exit(EXIT_FAILURE);
    }
    else
    {
        if( (p=fopen(argv[2],"r")) ==NULL )
            {
                fprintf(stderr,"���ܴ�%s�ļ�",argv[2]);
                exit(EXIT_FAILURE);
            }
    }
    while( fgets(ch,SIZE,p) != NULL)
    {
        if( strstr( ch,argv[1] ))//�����в����ַ�������
        {
            fputs(ch,stdout);
            flag1=0;
        }
        else
            flag2=1;
    }
    if(flag1&&flag2)
        puts("û�и��ַ�����");
    fclose(p);

    return 0;
}

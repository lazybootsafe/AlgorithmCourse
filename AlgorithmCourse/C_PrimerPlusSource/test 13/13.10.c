/*10.��дһ�������һ���ı��ļ���ͨ��������ʽ����ļ�����ͨ��
һ��ѭ������ʾ�û�����һ���ļ�λ�á�Ȼ��ó����ӡ�Ӹ�λ�ÿ�ʼ����
һ�����з�֮ǰ�����ݡ��û����븺�������ֵ�ַ����Խ�������ѭ����*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    long site;//ƫ����
    char name[20];//������
    char ch[256];//�洢�ַ�
    FILE *p;

    printf("����������Ҫ�򿪵��ı��ļ�:");
    gets(name);
    if( (p=fopen(name, "r")) ==NULL )
        {
            fprintf(stderr,"�򲻿�%s�ļ�",name);
            exit(EXIT_FAILURE);
        }
    puts("����������Ҫ������ļ�λ��(���ڵ���0������):");
    while( (scanf("%ld",&site)) == 1  &&  site>=0  )
    {
        getchar();
        fseek(p,site,SEEK_SET);
        fgets(ch,256,p);
        fputs(ch,stdout);
        puts("����������Ҫ������ļ�λ��(���ڵ���0������,�����������뿪):");
    }
    puts("bye.");
    fclose(p);

    return 0;
}

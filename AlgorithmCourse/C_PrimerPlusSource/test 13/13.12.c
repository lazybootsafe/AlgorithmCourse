/*12.����һ���ı��ļ����ں�20�У�ÿ��30����������Щ��������0��9
֮�䣬�ÿո�ֿ������ļ��������ֱ�ʾһ��ͼƬ��0��9��ʾ�����ӵĻ�
�ȡ���дһ�����򣬰��ļ��е����ݶ���һ��20��30��int�����С�һ�ְ���
Щ����ת��ΪͼƬ�Ĵ��Է����ǣ��ó���ʹ�������е�ֵ��ʼ��һ��20��31
���ַ����飬��ֵ0 ��Ӧ�ո��ַ���1 ��Ӧ���ַ����Դ����ơ�����Խ���
ʾ�ַ���ռ�Ŀռ�Խ�����磬��#��ʾ9��ÿ�е����һ���ַ�����31����
�ǿ��ַ������������������20���ַ�������󣬳�����ʾ���յ�ͼƬ
��������ӡ���е��ַ���������������������ı��ļ���*/

#include <stdio.h>
#include <stdlib.h>
#define ROW 20 //20��
#define COL 30 //ÿ��30��
int main (void)
{
    int ar_old[ROW][COL];
    char ar_new[ROW][COL+1];
    char name[20];
    FILE *p1,*p2;//p1ָ���ȡ�ļ���p2ָ�������ļ�
    char ch[]={" .':~*=?%#"};//���ֶ�Ӧ�ַ�
    int i,j;

    puts("��������Ҫ��ȡ���ļ���:");//�򿪶�ȡ�ļ�
    gets(name);
    if((p1=fopen(name,"r")) == NULL)
    {
        fprintf(stderr,"���ܴ�%s�ļ�",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            fscanf(p1,"%d",&ar_old[i][j]);//��ȡ�ļ�����,scanf��ȡ�������ո�
            ar_new[i][j]=ch[ar_old[i][j]];//���ļ�����ת������Ӧ���ŷ����ַ�������
        }
        ar_new[i][COL]='\0';//ִ������һ��ѭ������ʱCOL=j��
    }

    puts("��������Ҫ������ļ���:");//�򿪴����ļ�
    gets(name);
    if((p2=fopen(name,"w")) == NULL)
    {
        fprintf(stderr,"���ܴ�%s�ļ�",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<ROW;i++)
    {
        fprintf(p2,"%s\n",ar_new[i]);
        fprintf(stdout,"%s\n",ar_new[i]);
    }
    if(fclose(p1) !=0 || fclose(p2) !=0)
        fputs("�ر��ļ�ʧ��.\n",stderr);

    return 0;
}

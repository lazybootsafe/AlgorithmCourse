/*13.�ñ䳤���飨VLA�������׼���飬��ɱ����ϰ12��*/

#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int row=20,col=30;//20��,ÿ��30��
    int ar_old[row][col];
    char ar_new[row][col+1];
    char name[20];
    FILE *p1,*p2;//p1ָ���ȡ�ļ���p2ָ�������ļ�
    char ch[]={" .':~*=?%#"};
    int i,j;

    puts("��������Ҫ��ȡ���ļ���:");//�򿪶�ȡ�ļ�
    gets(name);
    if((p1=fopen(name,"r")) == NULL)
    {
        fprintf(stderr,"���ܴ�%s�ļ�",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            fscanf(p1,"%d",&ar_old[i][j]);
            ar_new[i][j]=ch[ar_old[i][j]];//���ļ�����ת������Ӧ���ŷ����ַ�������
        }
        ar_new[i][j]='\0';//ִ������һ��ѭ������ʱcol=j��
    }

    puts("��������Ҫ������ļ���:");//�򿪴����ļ�
    gets(name);
    if((p2=fopen(name,"w")) == NULL)
    {
        fprintf(stderr,"���ܴ�%s�ļ�",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<row;i++)
    {
        fprintf(p2,"%s\n",ar_new[i]);
        fprintf(stdout,"%s\n",ar_new[i]);
    }
    if(fclose(p1) !=0 || fclose(p2) !=0)
        fputs("�ر��ļ�ʧ��.\n",stderr);

    return 0;
}

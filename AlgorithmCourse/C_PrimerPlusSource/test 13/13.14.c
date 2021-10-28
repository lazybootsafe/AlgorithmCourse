/*14.����ͼ�������Ǵ�����ɴ����ص�����ͼ�񣬿��ܻ����һЩʧ
�档Ϊ�����ϰ12�������ʧ��ĺ������ú�����ÿ��ֵ����������������
��ֵ���Ƚϣ������ֵ������Χ����ֵ�Ĳ����1��������������ֵ��ƽ
��ֵ����������Ϊ�����������ֵ��ע�⣬��߽��ϵĵ����ڵĵ�����4
�������������⴦��*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>//�ṩabs����ֵ����
#define ROW 20 //20��
#define COL 30 //ÿ��30��
void eliminate_distortion(int ar_old[][COL],int n);//����ʧ�溯��
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
    if((p1=fopen(name,"r"))  ==  NULL)
    {
        fprintf(stderr,"���ܴ�%s�ļ�",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            fscanf(p1,"%d",&ar_old[i][j]);//��ȡ�ļ�����,scanf��ȡ�������ո�
        }
    }

    eliminate_distortion(ar_old,ROW);//����ʧ��

    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            ar_new[i][j]=ch[ar_old[i][j]];//���ļ�����ת������Ӧ���ŷ����ַ�������
        }
        ar_new[i][j]='\0';//ִ������һ��ѭ������ʱCOL=j��
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
        fprintf(p2,"%s\n",ar_new[i]);//��ӡ��p2ָ����ļ�
        fprintf(stdout,"%s\n",ar_new[i]);//��ӡ����Ļ
    }
    //�ر��ļ�
    if(fclose(p1) !=0 || fclose(p2) !=0)
        fputs("�ر��ļ�ʧ��.\n",stderr);

    return 0;
}

void eliminate_distortion(int ar_old[][COL],int n)//����ʧ�溯��
{
    int i,j;

    for(i=0;i<n;i++) //����ʧ��
    {
        for(j=0;j<COL;j++)
        {
            if((i == 0 && j == 0) || (i == 0 && j == 29) || (i == 19 && j == 0) || (i == 19 && j == 29)) //���ĸ��ǵ�ʱ��
                ;
            else if (i == 0) //�ڵ�һ��
            {       //�����������
                if ((abs(ar_old[i][j]-ar_old[i][j-1]) > 1) && (abs(ar_old[i][j]-ar_old[i][j+1]) > 1) && (abs(ar_old[i][j]-ar_old[i+1][j]) > 1))
                    ar_old[i][j]=(ar_old[i][j-1]+ar_old[i][j+1]+ar_old[i+1][j])/3.0+0.5;//��������
            }
            else if (j == 0) //�ڵ�һ��
            {      //�����������
                if ((abs(ar_old[i][j]-ar_old[i-1][j]) > 1) && (abs(ar_old[i][j]-ar_old[i][j+1]) > 1) && (abs(ar_old[i][j]-ar_old[i+1][j]) > 1))
                    ar_old[i][j]=(ar_old[i-1][j]+ar_old[i][j+1]+ar_old[i+1][j])/3.0+0.5;//��������
            }

            else if (i == 19) //�����һ��
            {     //�����������
                if ((abs(ar_old[i][j]-ar_old[i][j-1]) > 1) && abs((ar_old[i][j]-ar_old[i][j+1]) > 1) && (abs(ar_old[i][j]-ar_old[i-1][j]) > 1))
                    ar_old[i][j]=(ar_old[i-1][j]+ar_old[i][j-1]+ar_old[i][j+1])/3.0+0.5;//��������
            }

            else if (j == 29) //�����һ��
            {     //�����������
                if ((abs(ar_old[i][j]-ar_old[i][j-1]) > 1) && (abs(ar_old[i][j]-ar_old[i+1][j]) > 1) && (abs(ar_old[i][j]-ar_old[i-1][j]) > 1))
                    ar_old[i][j]=(ar_old[i-1][j]+ar_old[i][j-1]+ar_old[i+1][j])/3.0+0.5;//��������
            }

            else //���м�
            {     //�������������
                if ((abs(ar_old[i][j]-ar_old[i][j-1]) > 1) && (abs(ar_old[i][j]-ar_old[i][j+1]) > 1) && (abs(ar_old[i][j]-ar_old[i-1][j]) > 1) && (abs(ar_old[i][j]-ar_old[i+1][j]) > 1))
                    ar_old[i][j]=(ar_old[i-1][j]+ar_old[i+1][j]+ar_old[i][j-1]+ar_old[i][j+1])/4.0+0.5;//��������
            }
        }
    }
}

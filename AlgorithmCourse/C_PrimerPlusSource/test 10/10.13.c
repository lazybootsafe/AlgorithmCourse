#include<stdio.h>/*13.��дһ��������ʾ�û�����3������ÿ��������5��double���͵���
�������û�����ȷ����Ӧ�������������ֵ���ݣ����ó���Ӧ�����������
a.���û���������ݴ�����3��5��������
b.����ÿ�飨5�������ݵ�ƽ��ֵ
c.�����������ݵ�ƽ��ֵ
d.�ҳ���15�������е����ֵ
e.��ӡ���
ÿ������Ҫ�õ����ĺ�������ɣ�ʹ�ô�ͳC��������ķ�ʽ������
������b��Ҫ��дһ�����㲢����һά����ƽ��ֵ�ĺ���������ѭ�����ø�
����3�Ρ����ڴ�����������ĺ�����Ӧ�ð�����������Ϊ�������������c
��d�ĺ���Ӧ�ѽ����������������*/
#define ROWS 3
#define COLS 5
#define NUM 15
void get_ar(double ar[][COLS], int n); //�õ�����
double ave_num(double ar[]); //һάƽ��ֵ
void sum(double ar[][COLS], int n);//����ƽ��ֵ
double max(double ar[][COLS], int n); //�ҳ����ֵ
void printf_all(double ar[][COLS], int n);//��ӡ����

int main(void)
{
    double array[ROWS][COLS];

    printf_all(array,ROWS);

    return 0;
}

void get_ar(double ar[][COLS], int n) //�õ�����
{
    int i,j;

    printf("�������3����,ÿ��5��.\n");
    for(i=0;i<n;i++)
        for(j=0;j<COLS;j++)
        scanf("%lf",&ar[i][j]);

}

double ave_num(double ar[]) //һά����ƽ��ֵ
{
    int i;
    double tol;

    for(i=0,tol=0;i<COLS;i++)
        tol+=ar[i];

    return tol/COLS;
}

void sum(double ar[][COLS], int n)//����ƽ��ֵ
{
    int i,j;
    double tol;

    for(i=0;i<n;i++)
        for(j=0;j<COLS;j++)
            tol+=ar[i][j];

    printf("�������ݵ�ƽ��ֵ��:%g.\n",tol/NUM);
}

double max(double ar[][COLS], int n) //�ҳ����ֵ
{
    double max=ar[0][0];
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<COLS;j++)
            if(max<ar[i][j])
            max=ar[i][j];
    }

    printf("���ֵ��%g.\n",max);
}

void printf_all(double ar[][COLS], int n)//��ӡ����
{
    int i;

    get_ar(ar,ROWS);
    for(i=0;i<ROWS;i++)
        printf("��%d����ƽ��ֵ��:%g.\n",i+1,ave_num(ar[i]));
    sum(ar,ROWS);
    max(ar,ROWS);
    printf("\n");
    printf("�ټ�.\n");
}

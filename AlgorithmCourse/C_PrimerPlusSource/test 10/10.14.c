#include<stdio.h>/*14.�Ա䳤������Ϊ�����βΣ���ɱ����ϰ13��*/
#define ROWS 3
#define COLS 5
#define NUM 15
void get_ar(int n,int m ,double ar[n][m]); //�õ�����
double ave_num(double ar[]); //һάƽ��ֵ
void sum(int n,int m ,double ar[n][m]);//����ƽ��ֵ
double max(int n,int m ,double ar[n][m]); //�ҳ����ֵ
void printf_all(int n,int m ,double ar[n][m]);//��ӡ����

int main(void)
{
    double array[ROWS][COLS];

    printf_all(ROWS,COLS,array);

    return 0;
}

void get_ar(int n,int m ,double ar[n][m]) //�õ�����
{
    int i,j;

    printf("�������3����,ÿ��5��.\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
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

void sum(int n,int m ,double ar[n][m])//����ƽ��ֵ
{
    int i,j;
    double tol;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            tol+=ar[i][j];

    printf("�������ݵ�ƽ��ֵ��:%g.\n",tol/NUM);
}

double max(int n,int m ,double ar[n][m]) //�ҳ����ֵ
{
    double max=ar[0][0];
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if(max<ar[i][j])
            max=ar[i][j];
    }

    printf("���ֵ��%g.\n",max);
}

void printf_all(int n,int m ,double ar[n][m])//��ӡ����
{
    int i;

    get_ar(n,m,ar);
    for(i=0;i<n;i++)
        printf("��%d����ƽ��ֵ��:%g.\n",i+1,ave_num(ar[i]));
    sum(n,m,ar);
    max(n,m,ar);
    printf("\n");
    printf("�ټ�.\n");
}

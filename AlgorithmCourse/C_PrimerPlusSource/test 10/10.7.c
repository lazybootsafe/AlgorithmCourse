#include<stdio.h>/*7.��дһ�����򣬳�ʼ��һ��double���͵Ķ�ά���飬ʹ�ñ����ϰ2��
��һ�����������Ѹ������е����ݿ�������һ����ά�����У���Ϊ��ά����
����������飬���Կ���ʹ�ô���һά����Ŀ������������������е�ÿ��
�����飩��*/
#define ROWS 3
#define COLS 2
void copy_ar(double ar1[],double ar[],int n);//����һά���麯��
void printf_ar(double ar[][COLS],int rows); //��ӡ��ά���麯��

int main(void)
{
    int rows;
    double array[ROWS][COLS]={  {1.2,2.3},
                                {4.6,5.2},
                                {7.8,8.6}};
    double target[ROWS][COLS];

    for(rows=0;rows<ROWS;rows++)
        copy_ar(target[rows],array[rows],COLS);//ÿ�ο���һ��һά,�ܹ��м���һά�Ϳ�������,�͵����ǿ���3��,ÿ��������2��double��.
    printf_ar(target,ROWS);

    return 0;
}

void copy_ar(double ar1[],double ar[],int n)//һ�ο���һ��һά����
{
    int i;

    for(i=0;i<n;i++)
        ar1[i]=ar[i];
}

void printf_ar(double ar[][COLS],int rows)
{
    int i,j;

    for(i=0;i<rows;i++)
    {
     for(j=0;j<COLS;j++)
        printf("%g ",ar[i][j]);
        printf("\n");
    }
}

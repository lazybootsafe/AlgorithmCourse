#include <stdio.h>/*9.��дһ�����򣬳�ʼ��һ��double���͵�3��5��ά���飬ʹ��һ������
�䳤����ĺ������俽������һ����ά�����С���Ҫ��дһ���Ա䳤����Ϊ
�βεĺ�������ʾ������������ݡ�����������Ӧ���ܴ�������N��M����
�������������֧�ֱ䳤���飬��ʹ�ô�ͳC��������N��5�����飩��*/
#define M 5
#define N 3
void copy_ar(double ar1[][M],double ar[][M],int n);//����һά���麯��
void printf_array(int n, int m ,double ar[n][m]); //��ӡһά���麯��

int main(void)
{
    double array[N][M]={ {1.1 , 2.1 , 3.1 , 4.1 , 5.1},
                         {1.2 , 2.2 , 3.2 , 4.2 , 5.2} ,
                         {1.3 , 2.3 , 3.3 , 4.3 , 5.3} };
    double array1[N][M];

    copy_ar(array1 , array , M);
    printf_array(N,M,array1);
    return 0;
}

void copy_ar(double ar1[][M],double ar[][M],int n)//һ�ο���һ��һά����
{
    int i,j;

    for(i=0;i<n;i++)
        for(j=0;j<M;j++)
            ar1[i][j]=ar[i][j];
}

void printf_array(int n, int m ,double ar[n][m])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%g\t ",ar[i][j]);
        printf("\n");
    }

}

#include <stdio.h>/*11.��дһ����������һ��int���͵�3��5��ά���飬���ú��ʵ�ֵ��ʼ
�������ó����ӡ�����е�ֵ��Ȼ���ֵ����������ԭֵ��2����������ʾ
����Ԫ�ص���ֵ����дһ��������ʾ��������ݣ��ٱ�дһ�������Ѹ�Ԫ��
��ֵ�������������������Ժ�������������Ϊ������*/
#define M 5
#define N 3
void double_ar(double ar[][M] , int n);		//��������ĺ���
void printf_ar(int n, int m ,double ar[n][m]);					//��ӡ����ĺ���
int main(void)
{
    double array[N][M]={ {1.1 , 2.1 , 3.1 , 4.1 , 5.1},
                         {1.2 , 2.2 , 3.2 , 4.2 , 5.2} ,
                         {1.3 , 2.3 , 3.3 , 4.3 , 5.3} };

    printf("The original array:\n");
    printf_ar(N,M, array);

    double_ar(array,N);
    printf("The present array:\n");
    printf_ar(N,M, array);

    return 0;
}

void double_ar(double ar[][M] , int n)
{
    int i,j;

    for(i=0;i<n;i++)
        for(j=0;j<M;j++)
            ar[i][j]*=2;
}

void printf_ar(int n, int m ,double ar[n][m])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%g\t ",ar[i][j]);
        printf("\n");
    }
}

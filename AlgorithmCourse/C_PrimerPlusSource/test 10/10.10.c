#include <stdio.h>/*10.��дһ�����������������������Ӧ��Ԫ����ӣ�Ȼ��ѽ������
���� 3 �������С�Ҳ����˵���������1�а�����ֵ��2��4��5��8������2��
������ֵ��1��0��4��6����ô�ú�����3��4��9��14������3�����顣������
��3����������һ�������С����һ���򵥵ĳ����в��Ըú�����*/
#define SIZE 5
void sum_ar(double ar1[], double ar2[], double ar3[] , int n);		//������ĺ���
void print_ar(double ar[], int rows);						//��ӡ����ĺ���
int main(void)
{
    double array1[SIZE] ={1.2, 2.3, 2.6, 3.5, 3.2};
    double array2[SIZE] ={7.8, 8.6, 7.2, 3.9, 6.6};
    double sum[SIZE];

    printf("The original array1:\n");
    print_ar(array1, SIZE);
    printf("The original array2:\n");
    print_ar(array2, SIZE);
    sum_ar(array1,array2,sum,SIZE);
    printf("The sum array:\n");
    print_ar(sum, SIZE);

    return 0;
}

void sum_ar(double ar1[], double ar2[], double ar3[] , int n)
{
    int r;
    for (r = 0; r < n; r++)
        ar3[r] = ar1[r] + ar2[r];
}

void print_ar(double ar[], int rows)
{
    int r;
    for (r = 0; r < rows; r++)
            printf("%g\t ", ar[r]);
        printf("\n");

}

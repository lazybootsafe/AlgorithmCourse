#include<stdio.h>/*2.��дһ�����򣬳�ʼ��һ��double���͵����飬Ȼ��Ѹ����������
������3�����������У���main()��������4�����飩��ʹ�ô������ʾ����
�������е�1�ݿ�����ʹ�ô�ָ���ʾ����ָ������ĺ������е�2�ݿ�����
��Ŀ����������Դ�������ʹ�������Ԫ�ظ�����Ϊǰ���������Ĳ�������3
��������Ŀ����������Դ��������ָ��Դ�������һ��Ԫ�غ����Ԫ�ص�ָ
�롣Ҳ����˵������������������������������ʾ��
double��source[5]��=��{1.1,��2.2,��3.3,��4.4,��5.5};
double��target1[5];
double��target2[5];
double��target3[5];
copy_arr(target1,��source,��5);
copy_ptr(target2,��source,��5);
copy_ptrs(target3, source, source + 5);*/
#define SIZE 5
void copy_arr(double ar1[], double ar[],int n);
void copy_ptr(double *ar2 , double *ar, int n);
void copy_ptrs(double *ar3 , double *ar ,double *end);
void printf_array(double ar[] , int n);
int main(void)
{
    double source[SIZE]={1.1 , 2.2 , 3.3 , 4.4 , 5.5 };
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1,source,SIZE);
    copy_ptr(target2,source,SIZE);
    copy_ptrs(target3,source,source+SIZE);
    printf_array(target1 , SIZE);
    printf_array(target2 , SIZE);
    printf_array(target3 , SIZE);

    return 0;
}

void copy_arr(double ar1[], double ar[],int n)
{
    int i;

    for(i=0;i<n;i++)
        ar1[i]=ar[i];
}

void copy_ptr(double *ar2 , double *ar, int n)
{
    int i=0;

    for(i=0;i<n;i++)
        *ar2++=*ar++;


}

void copy_ptrs(double *ar3 , double *ar ,double *end)
{
    int i=0;

    for(i=0;ar<end;i++)
        *ar3++=*ar++;
}

void printf_array(double ar[] , int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("%g ",ar[i]);
    printf("\n");
}

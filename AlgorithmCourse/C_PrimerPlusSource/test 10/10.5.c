#include<stdio.h>/*5.��дһ�����������ش�����double�������������ֵ����Сֵ�Ĳ�
ֵ������һ���򵥵ĳ����в��Ըú�����*/
double dif(double *ar, int n);

int main(void)
{
    double array[]={1.5, 3.75, 4.3, 2.6, 2.15, 6.66};
    printf("%g",dif(array,6));
    printf("\n");

    return 0;
}

double dif(double *ar, int n)
{
    double max=ar[0],min=ar[0];
    int i;

    for(i=0;i<n;i++)
    {
        if(max<ar[i])
        max=ar[i];
        if(min>ar[i])
        min=ar[i];
    }

    return max-min;
}

#include<stdio.h>/*4.��дһ�����������ش�����double�������������ֵ���±꣬����һ
���򵥵ĳ����в��Ըú�����*/
double return_max(double *ar , int n);

int main(void)
{
    double array[]={1.5, 3.75, 4.3, 2.6, 2.15, 6.66};
    printf("%g",return_max(array,6));
    printf("\n");

    return 0;
}

double return_max(double ar[] , int n)
{
    int i,max=0;

    for(i=0;i<n;i++)
    {
        if(ar[max]<ar[i])
        max=i;
    }

    return max;
}

#include <stdio.h> /*6.��д������һ���������ú�����3��double�����ĵ�ַ��Ϊ����������
Сֵ�����1���������м�ֵ�����2�����������ֵ�����3��������*/
void TEST(double *,double *,double *);
int main(void)
{
    double num1,num2,num3;

    printf("enter 3 numbers:\n");
    scanf("%lf%lf%lf",&num1,&num2,&num3);
    printf("Originally\nnum1 = %.2f, num2 = %.2f, num3 = %.2f\n",
            num1, num2, num3);
    TEST(&num1,&num2,&num3);
    printf("Now\nnum1 = %.2f, num2 = %.2f, num3 = %.2f\n",
            num1, num2, num3);

    return 0;
}

void TEST(double *x,double *y,double *z)
{
    double t;

    if (*y<*x )
    {
        t=*x;
        *x=*y;
        *y=t;
    }
    if (*z<*x)
    {
        t=*x;
        *x=*z;
        *z=t;
    }
    if (*z<*y)
    {
        t=*y;
        *y=*z;
        *z=t;
    }
}

#include <stdio.h>//���һ������min(x, y)����������double����ֵ�Ľ�Сֵ��
double min(double,double);
int main()
{
    double a=0,b=0;

    printf("����������С��һ������:");
    scanf("%lf %lf",&a,&b);
    printf("С������%lf.\n",min(a,b));

    return 0;
}

double min(double a,double b)
{
    return (a<b ? a:b);
}

#include <stdio.h>/*��д������һ������larger_of()���ú���������double���ͱ�����ֵ
�滻Ϊ�ϴ��ֵ�����磬 larger_of(x, y)���x��y�нϴ��ֵ���¸�������������*/
double larger_of(double *,double *);
int main(void)
{
    double x=0,y=0;

    printf("����2�������ȴ�С:\n");
    scanf("%lf%lf",&x,&y);
    larger_of(&x,&y);
    printf("2������%.2lf %.2lf.\n",x,y);
    return 0;
}
double larger_of(double *x,double *y)
{
    *x > *y ? (*y = *x) : (*x = *y);
}

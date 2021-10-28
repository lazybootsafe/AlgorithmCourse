//varargs.c -- use variable number of arguments
#include <stdio.h>
#include <stdarg.h>
double sum(int, ...);
int main(void)
{
    double s, t;
    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("return value for "
    "sum(3, 1.1, 2.5, 13.3):       %g\n", s);
    printf("return value for "
    "sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n", t);
    return 0;
}
double sum(int lim, ...)
{
    va_list ap;          // ����һ�����󴢴����
    double tot = 0;
    int i;
    va_start(ap, lim);    // ��ap��ʼ��Ϊ�����б�
    for (i = 0; i < lim; i++)
        tot += va_arg(ap, double); // ���ʲ����б��е�ÿһ��
    va_end(ap);          // ������
    return tot;
}

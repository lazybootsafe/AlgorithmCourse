/*7.������ʹ�ñ�κ�����һ������Σ�
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show_array(const double ar[], int n);
double * new_d_array(int n, ...);
int main()
{
double * p1;
double * p2;
p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
show_array(p1, 5);
show_array(p2, 4);
free(p1);
free(p2);
return 0;
}
new_d_array()��������һ��int���͵Ĳ�����double���͵Ĳ������ú���
����һ��ָ�룬ָ����malloc()������ڴ�顣int���͵Ĳ���ָ���˶�̬��
���е�Ԫ�ظ�����double���͵�ֵ���ڳ�ʼ��Ԫ�أ���1��ֵ������1��Ԫ
�أ��Դ����ƣ�����дshow_array()��new_d_array()�����Ĵ��룬������
����*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define SIZE 40

void show_array(const double ar[], int n);
double * new_d_array(int n, ...);

int main()
{
    double * p1;
    double * p2;
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}

void show_array(const double ar[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%10.2f ", ar[i]);
        printf(", ");
    }
    printf("\n");
}

double * new_d_array(int n, ...)
{
    va_list ap;
    va_start(ap,n);
    int i=0;

    double *p=(double *)malloc(n*sizeof(double));
    while(i<n)
        p[i++]=va_arg(ap,double);
    va_end(ap);

    return p;
}

#include <stdio.h>/*8.ʹ�ñ����ϰ2�еĿ�����������һ���ں�7��Ԫ�ص������е�3����5
��Ԫ�ؿ������ں�3��Ԫ�ص������С��ú���������Ҫ�޸ģ�ֻ��Ҫѡ��
���ʵ�ʵ�ʲ�����ʵ�ʲ�������Ҫ���������������С��ֻ��Ҫ������Ԫ��
�ĵ�ַ�ʹ�����Ԫ�صĸ�������*/
#define SIZE 7
void copy_ar(double ar1[],double ar[],int n);//����һά���麯��
void printf_array(double ar[] , int n); //��ӡһά���麯��

int main(void)
{
    double source[SIZE]={1.1 , 2.2 , 3.3 , 4.4 , 5.5 ,6.6 , 7.7 };
    double target[3];

    copy_ar(target,source+2,3);
    printf_array(target,3);

    return 0;
}

void copy_ar(double ar1[],double ar[],int n)//һ�ο���һ��һά����
{
    int i;

    for(i=0;i<n;i++)
        ar1[i]=ar[i];
}

void printf_array(double ar[] , int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("%g ",ar[i]);
    printf("\n");
}

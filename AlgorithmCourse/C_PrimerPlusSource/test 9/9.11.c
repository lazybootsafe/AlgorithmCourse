#include <stdio.h>/*Fibonacci()�������ú�����ѭ������ݹ����쳲���������*/
unsigned long Fibonacci(unsigned long n);
int main(void)
{
    unsigned long n,i;

    printf("����һ��������n:");
;
    while((scanf("%lu",&n)) == 1)
    {
        for(i=1;i<=n;i++)
            printf("%lu,",Fibonacci(i));
        printf("\n��������:");
    }

    return 0;
}

unsigned long Fibonacci(unsigned long n) //Fibonacci()����,n����40��Ϳ�ʼ�����
{
    unsigned long a=1,b=1,i;

    for(i=2;i<=n;i++)   //i=3;i<=n;i++
    {
        b=a-b;             //a=a+b;
        a+=b;             //b=a-b;
    }
    return a;
}

/*14.��дһ��ͨ�����������еĳ�������ݡ���1�������в�����double
���͵�������Ϊ�ݵĵ�������2����������������Ϊ�ݵ�ָ����*/
#include <stdio.h>
#include <stdlib.h>
double mypower(double n, int exp);
int main(int argc, char * argv[])
{
    printf("The result is: %g",
            mypower(atof(argv[1]), atoi(argv[2])));
}

double mypower(double n, int exp)
{
    double pow=1.0;

    if(exp>0)
        for(pow=1.0;exp>=1;exp--)
            pow*=n;
    else if(exp<0)
    {
        if(!n)//��n=0��ʱ��0�ĸ�����û������
            puts("û������!");
        for(pow=1.0;exp<0;exp++)
            pow*=(1/n);

    }
    else if(n)//��ͬ��else if(n&&exp=0)
        //��0��0�η�����1
        pow=1;
    else
    {
        pow=1/n;
        puts("û������!");
    }
    return pow;
}

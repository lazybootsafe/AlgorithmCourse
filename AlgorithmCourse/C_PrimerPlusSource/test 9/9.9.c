#include <stdio.h> /*9.ʹ�õݹ麯����д�����ϰ8��*/
double power(double n, int p);
int main(void)
{
    double n=0;
    int p=0;

    printf("���������ָ��:\n");
    while ((scanf("%lf%d",&n,&p)) == 2)
        printf("%.2lf��%d������:%lf\n",n,p,power(n,p));

    return 0;
}

double power(double n, int p)
{
    double pow = 1;
    int i;

    if(p==0)
    {
        if(n==0)
        {
            pow=1;
            printf("duang,û��ֵ!\n");
        }
        else
            pow=1;
    }


    else if(p>0)
            pow=n*power(n,p-1);
    else
        {
            if(n!=0)
                pow=1/(n*power(n,-p-1));
            else
                pow=0;
        }

    return pow;         // ����pow��ֵ
}

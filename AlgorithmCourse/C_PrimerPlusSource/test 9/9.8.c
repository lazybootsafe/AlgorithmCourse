#include <stdio.h> /*8.��6�µĳ����嵥6.20�У�power()��������һ��double��������������
���ݡ��Ľ��ú�����ʹ������ȷ���㸺�ݡ����⣬����Ҫ����0���κδ���
��Ϊ0���κ�����0���ݶ�Ϊ1������Ӧ����0��0����δ���壬��˰Ѹ�ֵ��
��Ϊ1����Ҫʹ��һ��ѭ�������ڳ����в��Ըú�����*/

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

double power(double n, int p) // ��������
{
    double pow = 1;
    int i;

    if(p==0)
    {
        if(n==0)
        {
            pow=1;
            printf("It is not defined.\n");
        }
        else
            pow=1;
    }


    else if(p>0)
        for (i = 1; i <= p; i++)
            pow *= n;
    else
        {
            if(n!=0)
            {
            for (i = 1; i <= -p; i++)   // for (i = 0; i > p; i--)
                pow *= n;               //      pow /= n;             //��д��
            pow=1/pow;
            }
            else
                pow=0;
        }

    return pow;         // ����pow��ֵ
}

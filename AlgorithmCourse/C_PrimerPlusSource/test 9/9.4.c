#include <stdio.h> /*�����ĵ���ƽ�����������㣺�ȵõ������ĵ�����Ȼ�����
����������ƽ��ֵ�����ȡ�������ĵ�������дһ����������������double����
�Ĳ��������������������ĵ���ƽ������*/
double HA (double,double);
int main(void)
{
    double m=0,n=0;
    printf("����������:");
    scanf("%lf%lf",&m,&n);
    printf("���ǵĵ���ƽ������:%.4lf.\n",HA(m,n));
    return 0;
}

double HA (double m,double n)
{

    return (1/((1/m+1/n)/2));
}

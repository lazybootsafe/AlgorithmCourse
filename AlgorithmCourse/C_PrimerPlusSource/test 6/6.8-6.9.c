#include<stdio.h> //����2��������֮����������˻����
double dif(double m,double n);//���庯��dif
int main(void)
{
    double m,n,z;
    printf("����������������:");
    while(scanf("%lf%lf",&m,&n)==2)
    {
        printf("%lf\n",dif(m,n));
        printf("������������������:");
    }
    printf("������Ĳ��Ǹ�����.\n");
    system("pause");
    return 0;
}
double dif(double m,double n) //���������������˻�
{
    double z;
    z=(m-n)/(m*n);
    return z;
}

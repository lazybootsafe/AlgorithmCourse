#include <stdio.h> //����2����������
int main(void)
{
    double m,n,a,k;
    double l=-1.0;
    int num;
    printf("���������:");
    scanf("%d",&num);
    for(n=1.0,a=0.0,m=0.0;n<=num;n++)
    {
        a=1.0/n;
        m+=a;
        l*=-1.0;
        k+=a*l;
    }
     printf("��һ������1.0+1.0/2.0+1.0/3.0+1.0/4.0+...��%lf\n",m);
     printf("�ڶ�������1.0-1.0/2.0+1.0/3.0-1.0/4.0+...��%lf\n",k);
	system("pause");
    return 0;
 }

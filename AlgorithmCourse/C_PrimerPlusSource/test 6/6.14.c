#include <stdio.h> //����8����,������8�����ĺ�
int main(void)
{
    double x[8],y[8];
    int a;
    printf("������8����:");
    for(a=0;a<=7;a++)
    {
        y[0]=x[0];
        scanf("%lf",&x[a]);
        y[a]=y[a-1]+x[a];
    }
    printf("������:");
    for(a=0;a<=7;a++)
    {
        printf("%15.3lf",x[a]);
    }
    printf("\n");
    printf("���ֺ�:");
    for(a=1;a<=8;a++)
    {
        printf("%15.3lf",y[a-1]);
    }
    printf("\n");
    system("pause");
	return 0;
 }

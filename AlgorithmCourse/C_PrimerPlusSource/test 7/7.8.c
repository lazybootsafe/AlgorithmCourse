#include <stdio.h>  //��дһ��������ʾ�û�����һ�ܹ�����Сʱ����Ȼ���ӡ�����ܶ˰��;����롣
#define BASE1 8.75
#define BASE2 9.33
#define BASE3 10.00
#define BASE4 11.20
//���ֵȼ��Ļ�������
#define TIME 40 //����40СʱΪ�Ӱ�
#define OVERTIME 1.5    //�Ӱ೬��40Сʱ=1.5����ʱ��
#define TAX1 15/100 //ǰ300��ԪΪ15%
#define TAX2 20/100 //��150��ԪΪ20%
#define TAX3 25/100 //����Ϊ25%
#define BREAK1 300  //˰�ʵĵ�һ���ֽ��
#define BREAK2 450  //˰�ʵĵڶ����ֽ��
int main(void)
{
    int a=0,n=0;
    double base=0,work_time=0,tax=0,income=0,wage=0;    //tax˰,income����,wage����,base��������
    const int LENGTH=65;    //*�ĳ���

    for(a=0;a<LENGTH;a++)
        printf("*");
    printf("\n��ѡ����Ĺ��ʵȼ�:\n");
    printf("1) $8.75//hr \t\t\t 2) $9.33/hr\n");
    printf("3) $10.00//hr \t\t\t 4) $11.20/hr\n");
    printf("5) �뿪\n");
    for(a=0;a<LENGTH;a++)
        printf("*");
    printf("\n");//��ӡ���

    while(scanf("%d",&n)==1)
    {
    switch(n)
        {
        case 1:base=BASE1;
                break;
        case 2:base=BASE2;
                break;
        case 3:base=BASE3;
                break;
        case 4:base=BASE4;
                break;
        case 5:printf("�뿪.\n");
                return 0;
        default:printf("��������ȷѡ��.\n");
        }//ѡ��������ʵȼ�

    printf("��һ�ܹ�������Сʱ?\n");
    scanf("%lf",&work_time);
    if(work_time<=TIME)
        wage=work_time*base;
    else
    {
        work_time=(work_time-TIME)*OVERTIME+TIME;
        wage=work_time*base;
    }
    if(wage<=BREAK1)
        tax=wage*TAX1;
    else if(wage <=BREAK2)
        tax=BREAK1*TAX1+(wage-BREAK1)*TAX2;
    else
        tax=BREAK1*TAX1+(BREAK2-BREAK1)*TAX2+(wage-BREAK2)*TAX3;  //����˰
    income=wage-tax;
    printf("�ܹ���:%.2lf ˰:%.2lf ������:%.2lf\n",wage,tax,income);
    printf("�ٴ�ѡ���ʵȼ�(1-4;����q�뿪):\n");
    }
    return 0;
}

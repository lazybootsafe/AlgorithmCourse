#include <stdio.h>  //��дһ��������ʾ�û�����һ�ܹ�����Сʱ����Ȼ���ӡ�����ܶ˰��;����롣
#define BASE_PAY 10   //��������10��Ԫ/Сʱ
#define TIME 40 //����40СʱΪ�Ӱ�
#define OVERTIME 1.5    //�Ӱ೬��40Сʱ=1.5����ʱ��
#define TAX1 15/100 //ǰ300��ԪΪ15%
#define TAX2 20/100 //��150��ԪΪ20%
#define TAX3 25/100 //����Ϊ25%
#define BREAK1 300  //˰�ʵĵ�һ���ֽ��
#define BREAK2 450  //˰�ʵĵڶ����ֽ��
int main(void)
{
    double work_time=0,tax=0,income=0,wage=0;    //tax˰,income����,wage����
    printf("��һ�ܹ�������Сʱ?\n");
    scanf("%lf",&work_time);
    if(work_time<=TIME)
        wage=work_time*BASE_PAY;
    else
    {
        work_time=(work_time-TIME)*OVERTIME+TIME;
        wage=work_time*BASE_PAY;
    }
    if(wage<=BREAK1)
        tax=wage*TAX1;
    else if(wage <=BREAK2)
        tax=BREAK1*TAX1+(wage-BREAK1)*TAX2;
    else
        tax=BREAK1*TAX1+(BREAK2-BREAK1)*TAX2+(wage-BREAK2)*TAX3;  //����˰
    income=wage-tax;
    printf("����:%.2lf ˰:%.2lf ������:%.2lf\n",wage,tax,income);
    return 0;
}

#include <stdio.h>

#define RATE1 0.12589	//��һ��360ǧ��ʱ�ķ���
#define RATE2 0.17901	//��һ��320ǧ��ʱ�ķ���
#define RATE3 0.20971	//����680ǧ��ʱ�ķ���
#define BREAK1 360.0	//���ʵĵ�һ���ֽ��
#define BREAK2 680.0	//���ʵĵڶ����ֽ��
#define BASE1 (BREAK1 * RATE1)	//�õ�360ǧ��ʱ���ܷ���
#define BASE2 (BASE1 + (BREAK2 - BREAK1) * RATE2)	//�õ�680ǧ��ʱ���ܷ���

int main(void)
{
	//else if �ṹ����if else�����õ���ã���ͬʱ����в�ͬ�ķ��ʣ�
	double kwh;
	double bill;

	printf("Please enter the kwh used: ");
	scanf_s("%lf", &kwh);
	if (kwh < BREAK1)
	{
		bill = kwh * RATE1;		//����ֵС�ڷ��ʵĵ�һ���ֽ��ʱ�ķ���
	}
	else if (kwh < BREAK2)
	{
		bill = BASE1 + (kwh - BREAK1) * RATE2;		//����ֵ�ڷ��ʵĵ�һ�������ֽ��֮��ʱ�ķ���
	}
	else
	{
		bill = BASE2 + (kwh - BREAK2)* RATE3;		//����ֵ�ڷ��ʵĵ������ֽ��ʱ�ķ���
	}
	printf("The charge for %.1f kwh is $%1.2f\n", kwh, bill);

	getchar();
	getchar();
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(double, double);

int main(void)
{
	struct funds stan = {
		"Garlic-Meln Bank",
		3024.72,
		"Lucky's Savings and Loan",
		9237.11
	};

	system("color 4A");
	printf("Stan has a total of $%.2lf.\n",
		sum(stan.bankfund, stan.savefund));		/*�ṹ��Ա��Ϊ��������
												  
												  ��Ȼ�����ϣ����������Ӱ��ṹ��Ա��ֵ�����Դ��ݳ�Ա��ַ��modify(&stan.bankfund);*/

	getchar();
	return 0;
}

double sum(double x, double y)
{
	return (x + y);
}
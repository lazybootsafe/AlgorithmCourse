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

double sum(struct funds moolah);		//������һ���ṹ

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		3024.72,
		"Lucky's Savings and Loan",
		9237
	};

	system("color 0A");
	printf("Stan has a total of $%.2f\n", sum(stan));		//����sum()ʱ�������fundsģ�崴��һ���Զ�����moolah��Ȼ�����moolah�ṹ�ĳ�Ա����ʼ��Ϊstan�ṹ����Ӧ��Աȡֵ�ĸ���

	getchar();
	return 0;

}

double sum(struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);

}
#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50
#define N 2

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds money[], int n);

int main(void)
{
	struct funds jones[N] = { 
	{
		"Garlic-Melon Bank",
		3024.72f,
		"Lucky's Saving and Loan",
		9237.11
	},
	{
		"Honest Jack's Bank",
		3534.28,
		"Party Time Savings",
		3203.89
	}
	};

	system("color 5A");
	printf("The Joneses have a total of $%.2lf\n", 
		sum(jones, N));		//������������ĵ�ַ��׼ȷ�أ�Ҳ��������Ԫ�ء����ṹjones[0]�ĵ�ַ�����Եȼ�д��Ϊ��sum(&jones[0], N);

	/*Ҫ���ܽ᣺

	�� �������������������е�һ���ṹ�ĵ�ַ���ݸ�����
	�� Ȼ�����������ķ����ŷ��������������еĺ����ṹ��ע������ĺ������ú�ʹ����������ͬ����Ч����
		sum(&jones[0], n);
		��Ϊ���߶�ָ��ͬһ��ַ��ʹ��������ֻ�Ǵ��ݽṹ�ĵ�ַ�ļ�ӷ�����
	�� ��Ϊ����sum()�������ı�ԭ�������ݣ�����ʹ��ANSI C�������޶���const��*/
	system("pause");
	return 0;
}

double sum(const struct funds money[], int n)
{
	double total = 0;
	
	for (int i = 0; i < n; i++)
	{
		total += money[i].bankfund + money[i].savefund;
	}

	return total;
}
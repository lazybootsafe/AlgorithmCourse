
//�ùݹ�����

#include <stdio.h>
#include <stdlib.h>
#include "_9.11_hotel.h"		//�ṩ�ùݹ������ĳ�������ͺ�������

int menu(void)		
{
	int code, status;

	system("color 4E");

	printf("\n%s%s\n", STARS, STARS);
	printf("Enter the number of the desired hotel: \n");
	printf("1).Fairfield Arms      2).Hotel Olympic\n");
	printf("3).Chertworthy Plaza   4).The Stockton\n");
	printf("5).quit\n");
	printf("%s%s\n", STARS, STARS);
	while (((status = scanf_s("%d", &code))!= 1) || (code < 1 || code > 5))		//ɨ������ʧ�ܻ��ߣ����ֳ���1��5
	{
		if (status != 1)		//���ɨ������ʧ��
		{
			scanf_s("%*s");		//������һ���հ��ַ����ӵ�һ���ǿ��ַ���ʼ������һ���հ��ַ�Ϊֹ�������ַ�ȫ����ȡ��������
		}
		printf("Enter an integer from 1 to 5, please.\n");
	}
	
	return code;	//���ط����
}

int getnights(void)
{
	int nights;

	printf("How many nights are needed: ");
	while (scanf_s("%d", &nights) != 1)
	{
		scanf_s("%*s");
		printf("Please enter an integer , such as 2.\n");
	}

	return nights;		//��������
}

void showprice(double rate, int nights)
{
	double total = 0.0;			//�������Ӹ��㳣��Ϊdouble����
	double factor = 1.0;

	for (int n = 1; n <= nights; n++, factor *= DISCOUNT)
	{
		total += rate * factor;
	}
	printf("The total cost will be $%.2f\n", total);

}
#include <stdio.h>

#define SIZE 4

int main(void)
{
	short dates[SIZE];
	short * pti;
	double bills[SIZE];
	double * ptf;

	pti = dates;		//�������ַ����ָ��
	ptf = bills;		//ͬ��
	printf("%23s %10s\n", "short", "double");
	for (short i = 0; i < SIZE; i++)
	{
		printf("pointers + %d: %10p %10p\n", i, pti + i, ptf + i);		//ָ���n�ȼ���ָ��ֵ����n����ָ���������͵��ֽڴ�С
	}

	getchar();
	return 0;
}
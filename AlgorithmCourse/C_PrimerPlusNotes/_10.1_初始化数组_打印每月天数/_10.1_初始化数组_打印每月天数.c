#include <stdio.h>

#define MONTHS 12  //���������������С���������Ժ�����ά�����޸�

int main(void)
{
	//��ʼ�����飬��ʽ����
	const int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	//����12��int��Ա�����飬const����Ϊ������ʹ�ø�����ɶ�������д
	
	for (int i = 0; i < MONTHS; i++)
	{
		printf("Month %-2d has %2d days.\n", i + 1, days[i]);
	}

	getchar();
	return 0;
}
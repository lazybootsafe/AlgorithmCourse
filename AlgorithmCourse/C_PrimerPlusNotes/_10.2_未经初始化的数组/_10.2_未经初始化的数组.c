#include <stdio.h>

#define SIZE 4

int main(void)
{
	//δ����ʼ��������
	int no_data[SIZE];

	printf("%2s%14s", "i", "no_data[i]\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%2d%14d\n", i, no_data[i]);	//����δ����ʼ�����ڲ���Ա���ڴ浥Ԫ�����е�������ֵ����ӡ������Ľ��
	}
	
	getchar();
	return 0;
}
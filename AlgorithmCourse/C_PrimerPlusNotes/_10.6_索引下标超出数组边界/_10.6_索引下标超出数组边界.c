#include <stdio.h>

#define SIZE 4

int main(void)
{
	int value1 = 44;
	int arr[SIZE];
	int value2 = 88;
	
	printf("value1 = %d, value2 = %d\n", value1, value2);
	
	for (int i = -1; i <= SIZE; i++)
	{
		arr[i] = 2 * i + 1;		//Ϊ���鸳ֵ����Ȼ�������±곬����Χ���������ֵ���ֵ����ʼ���������ڴ浥Ԫ�����ܸı�����λ�õı�����ֵ
	}
	for (int i = -1; i < 7; i++)	//�����±곬����Χ���������ֵ���ֵ�������ڴ浥Ԫ������������λ�õı�����ֵ
	{
		printf("%2d %d\n", i, arr[i]);
	}
	printf("value1 = %d, value2 = %d\n", value1, value2);

	getchar();
	return 0;
}
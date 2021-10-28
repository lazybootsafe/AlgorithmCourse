/*
	��дһ���������ú�������һ��int��������������������д�λ���������ڳ����в����������*/
#include <stdio.h>
#include <stdlib.h>

int count_onbit(int n);

int main(void)
{
	int n = 73;
	
	system("color 5A");
	printf("The %d has %d bits on.\n", n, count_onbit(n));

	system("pause");
	return 0;
}

int count_onbit(int n)
{
	int size = 8 * sizeof(int);
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if ((n & 01) == 1)
		{
			count++;
		}
		n >>= 1;
	}

	return count;
}
#include <stdio.h>

#define COLS 4

int sum2d(int ar[][COLS], int rows);
int sum(int arp[], int n);

int main(void)
{
	int total1, total2, total3;
	int * pt1;
	int(*pt2)[COLS];

	pt1 = (int[2]){ 10, 20 };
	pt2 = (int[2][4]){{ 1, 2, 3, -9 }, { 4, 5, 6, -8 }};

	total1 = sum(pt1, 2);
	total2 = sum2d(pt2, 2);
	total3 = sum((int[]){ 4, 4, 4, 5, 5, 5 }, 6);	//���ϳ���ֱ�Ӵ������鳣�������������д�����������ͨ���÷�

	printf("total1 = %d\n", total1);
	printf("total2 = %d\n", total2);
	printf("total3 = %d\n", total3);

	getchar();
	return 0;
}

int sum2d(int arr[][COLS], int rows)
{
	int total = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			total += arr[i][j];
		}
	}

	return total;
}


int sum(int arr[], int n)
{
	int total = 0;

	for (int i = 0; i < n; i++)
	{
		total += arr[i];
	}

	return total;
}
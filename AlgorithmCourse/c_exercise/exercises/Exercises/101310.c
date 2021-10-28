#if 0
#include <stdio.h>
#include <stdlib.h>

void add_arr(int dest[], const int src1[], const int src2[], int len)
{
	for (int i = 0; i < len; i++)
		dest[i] = src1[i] + src2[i];
}

int main(void)
{
	int arr1[] = { 2,4,5,8 };
	int arr2[] = { 1,0,4,6 };
	int sum[4];
	add_arr(sum, arr1, arr2, 4);
	for (int i = 0; i < 4; i++)
		printf("%d ", sum[i]);
	putchar('\n');

	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double arr1[8], arr2[8];
	double sum;
	printf("Enter 8 data to the first array: ");
	for (int i = 0; i < 8; i++)
	{
		scanf_s("%lf", &arr1[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		sum = 0;
		for (int j = 0; j <= i; j++)
			sum += arr1[i];
		arr2[i] = sum;
	}
	printf("First array datas: ");
	for (int i = 0; i < 8; i++)
		printf("%g ", arr1[i]);
	printf("\nSecond array datas: ");
	for (int i = 0; i < 8; i++)
		printf("%g ", arr2[i]);

	return 0;
}

#endif
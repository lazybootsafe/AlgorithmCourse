#if 0
#include <stdio.h>
#include <stdlib.h>

void sort(double *arr, int length);
void recursive_revers(int first, int end, double* arr, int len);

int main(void)
{
	//double source[12] = { 2.5,3.2,1.2,1.6,2.4,0.1,5.2,0.9,0.3,0.9,1.4,7.3 };
	double source[12] = { 3,2,1,4,5,6,7,8,12,10,9,11 };
	for (int i = 0; i < 12; i++)
		printf("%g ", source[i]);
	putchar('\n');
	//recursive_revers(0, 5, source, 5);
	sort(source, 12);
	for (int i = 0; i < 12; i++)
		printf("%g ", source[i]);
	return 0;
}

void sort(double * arr, int length)
{
	for (int i = 0; i < (length / 2); i++)
	{
		double temp = arr[i];
		arr[i] = arr[length - 1 - i];
		arr[length -1 - i] = temp;
	}
}

void recursive_revers(int first, int end, double * arr, int len)
{
	if (len > (end / 2))
	{
		double temp = arr[first];
		arr[first] = arr[len - 1];
		arr[len - 1] = temp;
		recursive_revers(first + 1, end, arr, len - 1);
	}
}

#endif
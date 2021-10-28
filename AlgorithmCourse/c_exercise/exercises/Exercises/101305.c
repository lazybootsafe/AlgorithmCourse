#if 0
#include <stdio.h>
#include <stdlib.h>

double get_range(double *arr, int length);

int main(void)
{
	double source[5] = { 2.3,5.6,1.5,7.2,4.5 };
	printf("The max diff in array is %g\n", get_range(source, 5));

	return 0;
}

double get_range(double * arr, int length)
{
	double max = arr[0];
	double min = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	return (max - min);
}

#endif
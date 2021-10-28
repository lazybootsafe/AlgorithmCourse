#if 0
#include <stdio.h>
#include <stdlib.h>

int get_pos(double *arr, int length);

int main(void)
{
	double source[5] = { 1.1, 2.2, 3.3, 5.5, 2.5 };
	printf("The largest number's index in array is %d\n", get_pos(source, 5));

	return 0;
}

int get_pos(double *arr, int length)
{
	int index = 0;
	double max = arr[0];
	for (int i = 1; i < length; i++)
	{
		//if (max < arr[i + 1])
		//{
		//	max = arr[i + 1];
		//	index = i + 1;
		//}
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

int get_larger(int * arr, int length);

int main(void)
{
	int source[5] = { 2,4,6,8,10 };
	printf("The lagerest number in array is: %d\n", get_larger(source, 5));
	return 0;
}

int get_larger(int * arr, int length)
{
	int max = arr[0];
	
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < arr[i + 1])
			max = arr[i + 1];
	}
	return max;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int arr[8];
	arr[0] = 2;
	for (int i = 1; i <= 7; i++)
		arr[i] = arr[i - 1] * 2;
	int i = 0;
	do
		printf("%d ", arr[i++]);
	while (8 > i);

	return 0;
}

#endif
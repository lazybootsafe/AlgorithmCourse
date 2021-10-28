#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void sort(int array[], int len);

int main(void)
{
	int source[SIZE];
	srand((unsigned int)time(0));
	for (int i = 0; i < SIZE; i++)
		source[i] = rand() % 10 + 1;

	printf("Before:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%4d ", source[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	sort(source, SIZE);
	puts("After:");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%4d ", source[i]);
		if ((i + 1) % 10 == 0)
			putchar('\n');
	}

	return 0;
}

void sort(int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (array[i] > array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

#endif
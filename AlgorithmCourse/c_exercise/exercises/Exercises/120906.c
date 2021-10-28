#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define LENGTH 1000

int main(void)
{
	int num[SIZE + 1] = { 0 };
	int datum;
	for (int i = 1; i <= 10; i++)
	{
		printf("This is %d round to create data.\n", i);
		srand(i);

		for (int m = 0; m < LENGTH; m++)
		{
			datum = rand() % 10 + 1;
			num[datum]++;
		}

		printf("Rand data created.\n");
		for (int j = 1; j <= SIZE; j++)
		{
			printf("The datum %d created %d times.\n", j, num[j]);
		}
	}

	return 0;
}

#endif
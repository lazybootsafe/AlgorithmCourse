#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int big, small, sum = 0;
	printf("Enter lower and upper integer limits: ");
	scanf_s("%d %d", &small, &big);
	while (big > small)
	{
		sum = 0;
		for (int i = small; i <= big; i++)
		{
			sum += i * i;
		}
		printf("Them sum of the squares form %d to %d is %d\n", small, big, sum);
		printf("Enter lower and upper integer limits: ");
		scanf_s("%d %d", &small, &big);
	}
	printf("Done\n");

	return 0;
}

#endif
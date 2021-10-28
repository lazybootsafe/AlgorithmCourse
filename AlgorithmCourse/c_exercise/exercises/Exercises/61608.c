#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float first;
	float second;
	printf("Enter the two float data(seprate with space): ");
	while (scanf_s("%f %f", &first, &second))
	{
		printf("(%g - %g) / (%g * %g) is: %.3f",\
			first, second, first, second,\
			(first - second) / (first*second));
		printf("\nEnter the two flat data(Sprate with space): ");
	}

	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

float calc(float a, float b);

int main(void)
{
	float a, b;
	printf("Enter two float data(seprate with space): ");
	while (scanf_s("%f %f", &a, &b) == 2)
	{
		printf("(%g - %g) / (%g * %g) = %g\n", a, b, a, b, calc(a, b));
		printf("Enter two float data(seprate with space): ");
	}

	return 0;
}

float calc(float a, float b)
{
	return ((a - b) / (a * b));
}

#endif
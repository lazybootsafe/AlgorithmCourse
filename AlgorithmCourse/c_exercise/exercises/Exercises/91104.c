#if 0
#include <stdio.h>
#include <stdlib.h>

double harmean(double x, double y);

int main(void)
{
	double a, b;
	printf("Enter two float number: ");
	scanf_s("%lf %lf", &a, &b);
	printf("The  harmean of %g and %g is %g.\n", a, b, harmean(a, b));

	return 0;
}

double harmean(double x, double y)
{
	return 2 / (1 / x + 1 / y);
}

#endif
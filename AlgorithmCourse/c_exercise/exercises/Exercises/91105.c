#if 0
#include <stdio.h>
#include <stdlib.h>

void larger_of(double *x, double *y);

int main(void)
{
	double a, b;
	printf("Enter two float number: ");
	scanf_s("%lf %lf", &a, &b);
	printf("You input is %g and %g.\n", a, b);
	larger_of(&a, &b);
	printf("After function. data is %g and %g.\n", a, b);

	return 0;
}

void larger_of(double *x, double *y)
{
	if (*x > *y)
		*y = *x;
	else
		*x = *y;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

void comparison(double *x, double *y, double *z);

int main(void)
{
	double a, b, c;
	printf("Enter three float number: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);
	printf("You input is %g, %g and %g.\n", a, b, c);
	comparison(&a, &b, &c);
	printf("After function. data is %g, %g and %g.\n", a, b, c);

	return 0;
}

void comparison(double *x, double *y, double *z)
{
	double temp;
	if (*x > *y)
	{
		temp = *x;
		*x = *y;
		*y = temp;
	}
	if (*x > *z)
	{
		temp = *x;
		*x = *z;
		*z = temp;
	}
	if (*y > *z)
	{
		temp = *y;
		*y = *z;
		*z = temp;
	}
}

#endif
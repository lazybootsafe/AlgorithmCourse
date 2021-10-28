#if 0
#include <stdio.h>
#include <stdlib.h>

double power(double n, int p);

int main(void)
{
	double x, xpow;
	int exp;
	printf("Enter a number and the positive integer power");
	printf(" to which\nthe number will be raised. Enter q");
	printf(" to quit.\n");
	while (scanf_s("%lf %d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip -- bye!\n");

	return 0;
}

double power(double n, int p)
{
	double pow = 1;
	if (n == 0 && p == 0)
	{
		printf("The %g to power %d is not define, return -1!\n", n, p);
		return -1;
	}
	if (n == 0)
		return 0;
	if (p == 0)
		return 1;
	if (p > 0)
	{
		for (int i = 1; i <= p; i++)
			pow *= n;
		return pow;
	}
	else
	{
		for (int i = 1; i <= -(p); i++)
			pow *= n;
		return 1 / pow;
	}
}

#endif
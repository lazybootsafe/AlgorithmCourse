#if 0
#include <stdio.h>
#include <stdlib.h>

double cubic(double a);

int main(void)
{
	double num;
	printf("Enter a double number: ");
	scanf_s("%lf", &num);
	printf("The %lg's cubic is %lg\n", num, cubic(num));

	return 0;
}

double cubic(double a)
{
	double r = a * a * a;
	return r;
}

#endif
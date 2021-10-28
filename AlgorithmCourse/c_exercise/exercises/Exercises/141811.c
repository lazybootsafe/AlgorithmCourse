#if 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LEN 100

void transform(double src[], double tar[], int n, double(*func)(double));
double power(double x);

int main(void)
{
	double source[LEN], target[LEN];
	for (int i = 0; i < LEN; i++)
	{
		source[i] = i + 1;
	}
	puts("The source data is:");
	for (int i = 0; i < LEN; i++)
		printf("%5g", source[i]);
	putchar('\n');

	transform(source, target, LEN, sin);
	puts("The target sin data is:");
	for (int i = 0; i < LEN; i++)
		printf("%.3lf  ", target[i]);
	putchar('\n');

	transform(source, target, LEN, cos);
	puts("The target cos data is:");
	for (int i = 0; i < LEN; i++)
		printf("%.3lf  ", target[i]);
	putchar('\n');

	transform(source, target, LEN, sqrt);
	puts("The target sqrt data is:");
	for (int i = 0; i < LEN; i++)
		printf("%.3lf  ", target[i]);
	putchar('\n');

	transform(source, target, LEN, power);
	puts("The target pow data is:");
	for (int i = 0; i < LEN; i++)
		printf("%g  ", target[i]);
	putchar('\n');

	return 0;
}

void transform(double src[], double tar[], int n, double(*func)(double))
{
	for (int i = 0; i < n; i++)
		tar[i] = func(src[i]);
}

double power(double x)
{
	return x * x;
}

#endif // 1
#if 0
#include <stdio.h>
#include <stdlib.h>
//��VS�ڽ��꺯������ Ҫ���޸�
double Min(double x, double y);

int main(void)
{
	double a, b;
	scanf_s("%lf %lf", &a, &b);
	printf("%g", min(a, b));

	return 0;
}

double Min(double x, double y)
{
	return x < y ? x : y;
}

#endif
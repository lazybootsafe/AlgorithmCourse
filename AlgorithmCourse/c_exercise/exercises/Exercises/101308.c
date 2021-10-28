#if 0
#include <stdio.h>
#include <stdlib.h>

void copy(double *dest, double *src, int len);

int main(void)
{
	double source[] = { 9,8,7,6,5,4,3 };
	double target[3];
	copy(target, source + 2, 3);
	for (int i = 0; i < 7; i++)
		printf("%.01f ", source[i]);
	putchar('\n');
	for (int i = 0; i < 3; i++)
		printf("%.01f ", target[i]);
	putchar('\n');

	return 0;
}

void copy(double * dest, double * src, int len)
{
	for (int i = 0; i < len; i++)
		*(dest + i) = *(src + i);
}

#endif
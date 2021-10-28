#if 0
#include <stdio.h>
#include <stdlib.h>

void copy_arr(double dest[], double src[], int n);
void copy_ptr(double *dest, double *src, int n);
void copy_ptrs(double *dest1, double *src1, double *src2);

int main(void)
{
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[5];
	double target2[5];
	double target3[5];
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);

	printf("source: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%g ", source[i]);
	}
	putchar('\n');
	printf("target1: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%g ", target1[i]);
	}
	putchar('\n');
	printf("target2: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%g ", target2[i]);
	}
	putchar('\n');
	printf("target3: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%g ", target3[i]);
	}
	putchar('\n');

	return 0;
}

void copy_arr(double dest[], double src[], int n)
{
	for (int i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
}

void copy_ptr(double * dest, double * src, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
}

void copy_ptrs(double * dest, double * src1, double * src2)
{
	for (int i = 0; i < (src2 - src1); i++)
	{
		*(dest + i) = *(src1 + i);
	}
}

#endif
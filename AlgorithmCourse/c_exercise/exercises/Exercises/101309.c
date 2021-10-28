#if 0
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

void copy_array(int n, int m, double dest[][5], const double src[][COLS])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			dest[i][j] = src[i][j];
	}
}

void show_array(int n, int m, const double array[][COLS])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%g ", array[i][j]);
		putchar('\n');
	}
}

int main(void)
{
	const int n = 3;
	const int m = 5;
	double source[][5] = {
		{ 0.2,1.5,5.9,3.4,6.8 },
		{ 7.2,5.5,4.9,9.4,1.8 },
		{ 2.2,0.5,1.9,6.4,3.8 }
	};
	double target[ROWS][COLS];

	copy_array(n, m, target, source);
	show_array(n, m, target);

	return 0;
}

#endif
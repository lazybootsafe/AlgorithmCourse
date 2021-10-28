#if 0
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4 //ÐÐ
#define COLS 2 //ÁÐ

void xcopy_arr(double dest[], double src[], int len);
void xcopy_ptr(double* dest, double *src, int len);
void xcopy_ptrs(double* dest, double *src1, double *src2);

void copy_2d_arr(double dest[][ROWS], double src[][ROWS], int len);
void copy_2d_prt(double(*dest)[ROWS], double(*src)[ROWS], int len);

int main(void)
{
	double target[COLS][ROWS];
	double source[COLS][ROWS] = {
		{4.3,3.2,0.4,6.5},
		{4.2,7.2,0.9,6.1}
	};
	//copy_2d_prt(target, source, COLS);
	copy_2d_arr(target, source, COLS);
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
			printf("%5.2f", target[i][j]);
		putchar('\n');
	}

	return 0;
}

void xcopy_arr(double dest[], double src[], int len)
{
	for (int i = 0; i < len; i++)
		dest[i] = src[i];
}

void xcopy_ptr(double * dest, double * src, int len)
{
	for (int i = 0; i < len; i++)
		*(dest + i) = *(src + i);
}

void xcopy_ptrs(double * dest, double * src1, double * src2)
{
	for (int i = 0; i < (src2 - src1); i++)
		*(dest + i) = *(src1 + i);
}

void copy_2d_arr(double dest[][ROWS], double src[][ROWS], int len)
{
	for (int i = 0; i < len; i++)
		xcopy_arr(dest[i], src[i], ROWS);
}

void copy_2d_prt(double(*dest)[ROWS], double(*src)[ROWS], int len)
{
	for (int i = 0; i < len; i++)
		xcopy_ptr(*(dest + i), *(src + i), ROWS);
}

#endif
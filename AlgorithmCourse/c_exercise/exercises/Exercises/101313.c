#if 0
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

void input(double arr[ROWS][COLS]);
double col_average(const double arr[COLS]);
double average(const double arr[ROWS][COLS]);
double remax_number(const arr[ROWS][COLS]);
void show_data(const double arr[ROWS][COLS]);
void show_result(const double arr[ROWS][COLS]);

int main(void)
{
	double arr[ROWS][COLS];
	input(arr);
	show_data(arr);
	show_result(arr);

	return 0;
}

void input(double arr[ROWS][COLS])
{
	puts("Enter the array number.");
	for (int i = 0; i < ROWS; i++)
	{
		puts("Enter five double number seprate by enter or space:");
		for (int j = 0; j < COLS; j++)
			scanf_s("%lf", &arr[i][j]);
	}
}

double col_average(const double arr[COLS])
{
	double sum = 0;
	for (int i = 0; i < COLS; i++)
		sum += arr[i];
	return sum / COLS;
}

double average(const double arr[ROWS][COLS])
{
	double sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			sum += col_average(arr[i]);
	}
	return sum / ROWS;
}

double remax_number(const double arr[ROWS][COLS])
{
	double max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	return max;
}

void show_data(const double arr[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			printf("%.2f ", arr[i][j]);
		putchar('\n');
	}
}

void show_result(const double arr[ROWS][COLS])
{
	puts("The Average of every colnum is:");
	for (int i = 0; i < ROWS; i++)
		printf("The %d colnum's average is %g.\n", i, col_average(arr[i]));
	printf("The array's data average is %g.\n", average(arr));
	printf("The max datum in the array is %g.\n", remax_number(arr));
}

#endif
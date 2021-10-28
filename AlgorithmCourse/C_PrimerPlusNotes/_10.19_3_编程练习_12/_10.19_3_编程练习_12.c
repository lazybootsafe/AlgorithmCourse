#include<stdio.h>
#include<stdlib.h>

#define COLOR system("COLOR 0A")
#define ROWS 3
#define COLS 5
#define AMOUNT ROWS*COLS

void get_arr2d(double arr[][COLS], int rows);					//��ȡ��ά����
void show_per_row_average(double arr[][COLS], int rows);		//��ӡ��ά�����ÿһ�е�ƽ��ֵ
double get_row_average(double arr[], int cols);					//�����ά�����һ�е�ƽ��ֵ
double get_all_row_average(double arr[][COLS], int rows);		//�����ά��������Ԫ�ص�ƽ��ֵ

int main(void)
{
	double arr[ROWS][COLS], average;
	
	COLOR;
	get_arr2d(arr, ROWS);
	show_per_row_average(arr, ROWS);
	average = get_all_row_average(arr, ROWS);
	printf("Average of the %d numbers: %.1lf\n", AMOUNT, average);

	getchar();
	getchar();
	getchar();
	return 0;
}

//��ȡ��ά����
void get_arr2d(double arr[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		printf("Enter line %d with %d number: ", i + 1, COLS);
		for (int j = 0; j < COLS; j++)
		{
			scanf_s("%lf", &arr[i][j]);
		}
	}
}

//��ӡ��ά�����ÿһ�е�ƽ��ֵ
void show_per_row_average(double arr[][COLS], int rows)
{
	double row_average;

	for (int i = 0; i < rows; i++)
	{
		row_average = get_row_average(arr[i], COLS);
		printf("Average of line %d: %.1lf\n", i + 1, row_average);
	}
}

//�����ά�����һ�е�ƽ��ֵ
double get_row_average(double arr[], int cols)
{
	double retn = 0;

	for (int i = 0; i < cols; i++)
	{
		retn += arr[i];
	}
	retn /= cols;

	return retn;
}

//�����ά��������Ԫ�ص�ƽ��ֵ
double get_all_row_average(double arr[][COLS], int rows)
{
	double total = 0.0, average;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			total += arr[i][j];
		}
	}
	average = total / AMOUNT;

	return average;
}
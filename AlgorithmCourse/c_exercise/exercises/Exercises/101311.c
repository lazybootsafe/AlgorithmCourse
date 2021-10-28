#if 0
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

void show(const int src[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			printf("%2d ", src[i][j]);
}

void times_element(int src[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			src[i][j] = src[i][j] * 2;
}

int main(void)
{
	int arr[3][5] = { {1,3,5,7,9},{2,4,6,8,0},{9,5,2,7,6} };
	show(arr);
	times_element(arr);
	putchar('\n');
	show(arr);

	return 0;
}

#endif
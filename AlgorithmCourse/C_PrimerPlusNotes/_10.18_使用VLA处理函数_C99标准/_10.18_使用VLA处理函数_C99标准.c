

/******************************************************************************
 ****																	   ****
 ****								����ʧ��							   ****
 **** ��������֧��C99�ı䳤���飨VLA����ֻ���ܴ�СΪ�������ʽ�������С�� ****
 **** ��VLA�ı������ʽ�±겻֧�֣��Ƿ�������						       ****
 ****																	   ****
 ******************************************************************************/

#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, int ar[rows][cols]);

int main(void)
{
	int rs = 3;
	int cs = 10;

	int junk[ROWS][COLS] = {
		{ 2, 4, 6, 8 },
		{ 3, 5, 7, 9 },
		{ 12, 10, 8, 6 }
	};

	int morejunk[ROWS - 1][COLS + 2] = {
		{ 20, 30, 40, 50, 60, 70 },
		{ 5, 6, 7, 8, 9, 10 }
	};
	int varr[rs][cs];	//VLA

	for (int i = 0; i < rs; i++)
	{
		for (int  j= 0; j < cs; j++)
		{
			varr[rs][cs] = i * j + j;
		}
	}

	printf("3 x 5 array\n");
	printf("Sum of all elemets is %d\n",
		sum2d(ROWS, COLS, junk));

	printf("2 x 6 array\n");
	printf("Sum of all elemets is %d\n",
		sum2d(ROWS - 1, COLS + 2, morejunk));

	printf("3 x 10 VLA\n");
	printf("Sum of all elemets is %d\n",
		sum2d(rs, cs, varr));

	getchar();
	return 0;
}

//����һ��VLA�����ĺ���
int sum2d(int rows, int cols, int arr[rows][cols])
{
	int r;
	int c;
	int tot;
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
			tot += arr[rows][cols];
	}

	return 0;
}
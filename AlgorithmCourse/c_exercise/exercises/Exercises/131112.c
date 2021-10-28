#if 0
#include <stdio.h>
#include <stdlib.h>

#define   ROWS 20
#define   COLS 30
#define LEVELS 10
const char trans[LEVELS + 1] = " .':~*=&%#";//" .':*=&%@"

void MakePic(int data[][COLS], char pic[][COLS], int rows);
void init(char arr[][COLS], char ch);

int main(void)
{
	int row, col;
	int picIn[ROWS][COLS];
	char picOut[ROWS][COLS];
	char szFileName[81];
	FILE * inFile;

	init(picOut, 'S');
	
	printf("Enter name of file: ");
	gets_s(szFileName, 80);
	if ((fopen_s(&inFile, szFileName, "r")) != 0)
	{
		fprintf(stderr, "Could not open data file.\n");
		exit(EXIT_FAILURE);
	}
	for (row = 0; row < ROWS; row++)
		for (col = 0; col < COLS; col++)
			fscanf_s(inFile, "%d", &picIn[row][col]);
	if (ferror(inFile))
	{
		fprintf(stderr, "Error getting data from file.\n");
		exit(EXIT_FAILURE);
	}
	MakePic(picIn, picOut, ROWS);

	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
			putchar(picOut[row][col]);
		putchar('\n');
	}
	return 0;
}

void MakePic(int data[][COLS], char pic[][COLS], int rows)
{
	int row, col;
	for (row = 0; row < rows; row++)
		for (col = 0; col < COLS; col++)
			pic[row][col] = trans[data[row][col]];
}

void init(char arr[][COLS], char ch)
{
	int r, c;
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			arr[r][c] = ch;
	}
}

#endif
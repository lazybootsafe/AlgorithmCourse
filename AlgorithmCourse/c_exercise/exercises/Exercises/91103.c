#if 0
#include <stdio.h>
#include <stdlib.h>

void print(char c, int rows, int cols);

int main(void)
{
	int a, b;
	char c;
	printf("Enter the char: ");
	scanf_s("%c", &c, 1);
	printf("Enter the rows and cols: ");
	scanf_s("%d %d", &a, &b);
	print(c, a, b);
	return 0;
}

void print(char c, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			putchar(c);
		printf("\n");
	}
}

#endif
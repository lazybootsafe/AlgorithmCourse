#if 0
#include <stdio.h>
#include <stdlib.h>

void chline(char ch, int cols, int rows);

int main(void)
{
	int a, b;
	char c;
	printf("Enter a charactor: ");
	scanf_s("%c", &c, 1);
	printf("Enter the rows and cols: ");
	scanf_s("%d %d", &b, &a);
	chline(c, a, b);

	return 0;
}

void chline(char ch, int cols, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%c", ch);
		printf("\n");
	}
}

#endif
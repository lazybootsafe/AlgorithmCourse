#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int array[8];
	printf("请输入8个整数： ");
	for (int i = 0; i < 8; i++)
	{
		scanf_s("%d", &array[i]);
	}
	for (int i = 7; i >= 0; i--)
	{
		printf("%d ", array[i]);
	}

	return 0;
}

#endif
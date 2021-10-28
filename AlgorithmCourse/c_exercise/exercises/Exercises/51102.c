#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num;
	printf("Enter a number: ");
	scanf_s("%d", &num);
	for (int i = num; i <= (num + 10); i++)
	{
		printf("%d ", i);
	}

	return 0;
}

#endif
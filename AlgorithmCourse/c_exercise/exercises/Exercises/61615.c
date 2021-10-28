#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char arr[256] = { 0 };
	printf("Enter your character data: ");
	int i = 0;
	while (arr[i] != '\n' && ++i)
	{
		scanf_s("%c", &arr[i], 1);
	}

	for (; i >= 0; i--)
	{
		printf("%c", arr[i]);
	}
	printf("\nDone\n");

	return 0;
}

#endif
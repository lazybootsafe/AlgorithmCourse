#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int head;
	int tail;
	printf("Enter the head number: ");
	scanf_s("%d", &head);
	printf("Enter the tail number: ");
	scanf_s("%d", &tail);
	printf("Original\tSquare\t\tCubic:\n");
	for (int i = head; i <= tail; i++)
	{
		printf("%-6d\t\t%-10d\t%-10d\n", i, i*i, i*i*i);
	}
	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count = 0;
	int sum = 0;
	printf("Enter the number of days you word: ");
	scanf_s("%d", &count);
	while (0 < count)
	{
		sum = sum + (count*count);
		count--;
	}
	printf("You earned $%d total!\n", sum);

	return 0;
}

#endif
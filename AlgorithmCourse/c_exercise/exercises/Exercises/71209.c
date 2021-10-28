#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	printf("Enter a number(greater than 2): ");
	scanf_s("%d", &num);
	if (2 > num)
	{
		printf("%d is out of rang.\n", num);
	}
	else
	{
		for (int i = 2; i <= num; i++)
		{
			int is_prime = 1;
			for (int j = 2; j <= i / 2; j++)
			{
				if (i%j == 0)
				{
					is_prime = 0;
					break;
				}
			}
			if (1 == is_prime)
				printf("%d ", i);
		}
	}

	return 0;
}

#endif
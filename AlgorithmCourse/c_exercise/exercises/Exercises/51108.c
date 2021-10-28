#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int one;
	int two;
	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand: ");
	scanf_s("%d", &two);
	printf("Now enter the first operand: ");
	scanf_s("%d", &one);
	while (one > 0)
	{
		printf("%d \% %d is %d\n", one, two, (one%two));
		printf("Enter next number for first operand (<= to quit): ");
		scanf_s("%d", &one);
	}
	printf("Done\n");

	return 0;
}

#endif
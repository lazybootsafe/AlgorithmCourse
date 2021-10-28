#if 0
#include <stdio.h>
#include <stdlib.h>

void to_binary(unsigned long n);
void to_base_n(unsigned long n, unsigned int m);

int main(void)
{
	unsigned long number;
	unsigned int target;
	printf("Enter two integer(q to quit):\n");
	//while (scanf_s("%lu", &number) == 1)
	//{
	//	printf("Binary equivalent: ");
	//	to_binary(number);
	//	putchar('\n');
	//	printf("Enter an integer(q to quit):\n");
	//}
	while (scanf_s("%lu %u", &number, &target) == 2)
	{
		printf("Convert %lu to %u notation is: ", number, target);
		to_base_n(number, target);
		putchar('\n');
		puts("Enter two integer(q to quit):");
	}
	printf("Done.\n");

	return 0;
}

void to_binary(unsigned long n)
{
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');
}

void to_base_n(unsigned long n, unsigned int m)
{
	if (m < 2 || m>10)
	{
		puts("\nThe second parameter range 2 ~ 10");
		return;
	}
	int re;
	re = n % m;
	if (n >= 2)
		to_base_n(n / m, m);
	printf("%d", re);
}

#endif
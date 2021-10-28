#if 0
#include <stdio.h>
#include <stdlib.h>

void Fibonacci(int n);

int main(void)
{
	int n;
	puts("Enter the number of Fibonacci(q to quit):");
	while (scanf_s("%d", &n) == 1)
	{
		if (n == 0)
			puts("0");
		if (n == 1)
			puts("1");
		if (n >= 2)
		{
			Fibonacci(n);
			puts("Enter the number of Fibonacci(q to quit):");
		}

	}

	return 0;
}

void Fibonacci(int n)
{
	unsigned long a, b, temp;
	a = 1;
	b = 1;
	for (int i = 0; i < n; i++)
	{
		printf("%lu ", a);
		temp = a + b;
		a = b;
		b = temp;
	}
	putchar('\n');
}

#endif
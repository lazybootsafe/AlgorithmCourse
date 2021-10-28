#if 0
#include <stdio.h>
#include <stdlib.h>

int rotate_l(int n, int len);

int main(void)
{
	int i, length;
	printf("Enter the number and a move bit: ");
	scanf_s("%d %d", &i, &length);
	printf("The %d move %d bit. result is %d\n", i, length, rotate_l(i, length));

	return 0;
}

int rotate_l(int n, int len)
{
	const static int size = CHAR_BIT * sizeof(int);
	if (len > size || len < 0)
	{
		puts("Error length.");
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		if (n&(1 << (size - 1)))
		{
			n <<= 1;
			n |= 1;
		}
		else
			n <<= 1;
	}
	return n;
}

#endif
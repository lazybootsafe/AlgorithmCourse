#if 0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int switch_count(int n);
char * itobs(int, char*);
int onbits(int n);

int main(int argc, char *argv[])
{
	//char str[10];
	//gets_s(str, 10);
	//int i = atoi(str);
	//printf("The switch bit of %d is %d.\n", i, switch_count(i));
	if (argc != 2)
		exit(1);
	int i = atoi(argv[1]);
	printf("The switch bit of %d is %d.\n", i, switch_count(i));

	int val;
	char bstr[CHAR_BIT * sizeof(int) + 1];
	printf("Enter an integer (q to quit): ");
	while (scanf_s("%d", &val))
	{
		printf("%d (%s) has %d bit(s) on.\n", val, itobs(val, bstr), onbits(val));
		printf("Next value: ");
	}
	puts("Done");

	return 0;
}

int switch_count(int n)
{
	int sum = 0;
	const static int size = CHAR_BIT * sizeof(int);
	for (int i = 0; i < size; i++)
	{
		if (n & 1)
			sum++;
		n >>= 1;
	}
	return sum;
}

char * itobs(int n, char * ps)
{
	static int size = CHAR_BIT * sizeof(int);
	for (int i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';
	return ps;
}

int onbits(int n)
{
	static const int size = CHAR_BIT * sizeof(int);
	int ct = 0;
	for (int i = 0; i < size; i++, n >>= 1)
		if ((1 & n) == 1)
			ct++;
	return ct;
}

#endif // 1
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 32
int bstoi(char *st);

int main(void)
{
	char *pbin = "01001001";
	int num = 0;
	int len = strlen(pbin);
	for (int i = 0; i < len; i++)
		num = num * 2 + (pbin[i] - '0');
	printf("%d\n", num);
	printf("%d\n", bstoi(pbin));
	return 0;
}

int bstoi(char * st)
{
	int sum = 0;
	while (*st != '\0')
	{
		sum *= 2;
		sum += *st++ - '0';
	}
	return sum;
}

#endif // 1
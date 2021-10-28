#if 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int atoi_rewrite(char * string)
{
	int result = 0;
	int length = strlen(string);
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(string[i]))
			return 0;
		result = result * 10 + (string[i] - '0');
	}
	return result;
}

int main(void)
{
	char ch[10];
	int result = 0;
	printf("Enter a number of integer: ");
	scanf_s("%s", &ch, 10);
	result = atoi_rewrite(ch);
	printf("String %s to integer %d\n", ch, result);
	return 0;
}

#endif
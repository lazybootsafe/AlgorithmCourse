#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40

char * string_in(char *str, char *sub);

int main(void)
{
	char str[SIZE] = { 0 }, sub[SIZE] = { 0 };
	char *p = NULL;
	puts("Enter a string as main string(blank to quit): ");
	fgets(str, SIZE, stdin);
	puts("Enter a sub string to find in main: ");
	fgets(sub, SIZE, stdin);
	while (*str != '\n')
	{
		p = string_in(str, sub);
		printf("The position of sub string is: %p\n", p);
		puts("Enter a string as main string(blank to quit): ");
		fgets(str, SIZE, stdin);
		printf("Enter a sub string to find in main: ");
		fgets(sub, SIZE, stdin);
	}

	return 0;
}

char * string_in(char * str, char * sub)
{
	int count = 0;
	int len = strlen(sub);
	while (*str != '\n' && count < len)
	{
		if (*(str + count) == *(str + count))
			count++;
		else
		{
			count = 0;
			str++;
		}
	}
	if (count == len)
		return str;
	else
		return NULL;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

char* read_char(char* str, int len);

int main(void)
{
	char str[SIZE] = { 0 };
	puts("Enter a string.");
	read_char(str, SIZE);
	puts("The string is:");
	puts(str);

	return 0;
}

char * read_char(char * str, int len)
{
	for (int i = 0; i < len; i++)
	{
		str[i] = getchar();
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' || str[i] == EOF)
			break;
	}
	return str;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

char * read_char(char *str, int len);

int main(void)
{
	char test[SIZE] = { 0 };
	puts("Enter a string.");
	read_char(test, SIZE);
	puts("The string is:");
	puts(test);

	return 0;
}

char * read_char(char * str, int len)
{
	for (int i = 0; i < len; ++i)
	{
		str[i] = getchar();
		if (str[i] == EOF)
			break;
	}

	//int i = 0;
	//do
	//{
	//	str[i] = getchar();
	//} while (str[i] != EOF && ++i < len);
	return str;
}

#endif
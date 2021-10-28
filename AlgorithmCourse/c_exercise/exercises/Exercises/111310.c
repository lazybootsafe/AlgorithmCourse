#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 40
char *trim_str(char *str);

int main(void)
{
	char szString[SIZE];
	printf("Enter a string: ");
	fgets(szString, SIZE, stdin);
	while (*szString != '\n')
	{
		trim_str(szString);
		printf("The trim string is: %s\n", szString);
		printf("Enter a string: ");
		fgets(szString, SIZE, stdin);
	}

	return 0;
}

char * trim_str(char * str)
{
	char *head = str;
	int count = 0;
	while (*str != '\0')
	{
		if (*str != ' ')
			*head++ = *str++;
		else
		{
			str++;
			count++;
		}
	}
	while (count--)
		*head++ = '\0';
	return str;
}

#endif
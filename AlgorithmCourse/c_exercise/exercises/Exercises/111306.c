#if 0
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 40
bool is_within(char c, char *str);

int main(void)
{
	char source[SIZE];
	char dest = ' ';
	printf("Enter a string: ");
	fgets(source, SIZE, stdin);
	while (dest != EOF)
	{
		printf("Enter a char to find (EOF for Quit): ");
		while ((dest = getchar()) == '\n')
			continue;
		if (is_within(dest, source) != 0)
			printf("Found the charactor %c in the string\n", dest);
		else
			printf("Charactor %c not found. Try another?\n", dest);
	}

	return 0;
}

bool is_within(char c, char * str)
{
	while (*str != '\0')
	{
		if (*str == c)
			return true;
		else
			str++;
	}
	return false;
}

#endif
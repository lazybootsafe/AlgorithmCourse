#if 0
#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

char * find_char(char *str, char c);

int main(void)
{
	char source[SIZE];
	char dest = ' ';
	char *position;
	printf("Enter a string: ");
	fgets(source, SIZE, stdin);
	while (dest != EOF)
	{
		printf("Enter a char to find (EOF for Quit): ");
		while ((dest = getchar()) == '\n')
			continue;
		if ((position = find_char(source, dest)) != NULL)
			printf("Found the char %c in the %p\n", *position, position);
		else
			printf("Charactor %c not found. Try another?\n", dest);
	}

	return 0;
}

char * find_char(char * str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return str;
		else
			str++;
	}
	return NULL;
}

#endif
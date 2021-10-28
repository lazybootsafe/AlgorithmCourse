#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	char c;
	if (argc < 2)
		c = 'p';
	c = argv[1][1];
	char string[256];
	puts("Enter the string:");
	gets_s(string, 256);
	int length = strlen(string);
	switch (c)
	{
	case 'p':
		printf("The original text is: %s", string);
		break;
	case 'u':
		printf("The Upper text is: ");
		for (int i = 0; i < length; i++)
			putchar(toupper(string[i]));
		break;
	case 'l':
		printf("The Lower text is: ");
		for (int i = 0; i < length; i++)
			putchar(tolower(string[i]));
		break;
	}

	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void get_char(void);
int get_pos(char c);

int main(void)
{
	get_char();

	return 0;
}

void get_char(void)
{
	char c;
	printf("Enter the charactors(Enter Ctrl + Z end the input): ");
	while ((c = getchar()) != EOF)
	{
		//if ((c = getchar()) == 'n')
		//	continue;
		//if (isalpha(c))
		if (get_pos(c) != -1)
			printf("The char %c's position in alphabet is %d.\n", c, get_pos(c));
		else
			printf("%c is not a alphabet.\n", c);
	}
}

int get_pos(char c)
{
	if (c >= 'A'&&c <= 'Z')
		return c - 'A' + 1;
	if (c >= 'a'&&c <= 'z')
		return c - 'a' + 1;
	return -1;
}

#endif
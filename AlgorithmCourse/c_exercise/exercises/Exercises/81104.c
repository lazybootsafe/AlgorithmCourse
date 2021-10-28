#if 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	int words = 0;
	int letter = 0;
	char c;
	puts("Enter Ctrl + Z end the input.");
	while ((c = getchar()) != EOF)
	{
		//if (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z')
		//	letter++;
		if (isalpha(c) != 0)
			letter++;
		//if (c == ' ' || c == ',' || c == '.' || c == '\n')
		//	word++;
		if (ispunct(c) != 0 || c == ' ')
			words++;
	}
	printf("There are %d words, and %d charactor, %g C/W!\n", words, letter, 1.0 * letter / words);
	return 0;
}

#endif
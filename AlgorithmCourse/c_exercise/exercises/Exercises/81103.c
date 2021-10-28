#if 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	int lowcase = 0;
	int upcase = 0;
	char c;
	printf("Enter Ctrl + Z end the input.\n");
	while ((c = getchar()) != EOF)
	{
		if (c >= 'A'&&c <= 'Z')
			upcase++;
		if (c >= 'a'&&c <= 'z')
			lowcase++;
		//if (islower(c))
		//	lowcase++;
		//if (isupper(c))
		//	upcase++;
	}
	printf("There are %d uppercase, and %d lowercase in the file!\n", upcase, lowcase);

	return 0;
}

#endif
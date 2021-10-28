#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count = 0;
	char c;
	puts("Enter Ctrl + Z end the input.");
	while ((c = getchar()) != EOF)
	{
		if (count++ == 10)
		{
			printf("\n");
			count = 1;
		}
		if (c >= 0x20)	//可使用八、十、十六进制
		{
			printf(" \'%c\'->%3d ", c, c);
		}
		else if (c == '\n')
		{
			printf(" \\n->\\n\n ");
			count = 0;
		}
		else if (c == '\t')
		{
			printf(" \\t->\\t ");
		}
		else
		{
			printf(" \'%c\'->^%c ", c, (c + 64));
		}
	}

	return 0;
}

#endif
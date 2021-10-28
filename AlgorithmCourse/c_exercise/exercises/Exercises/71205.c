#if 0
#include <stdio.h>

int main(void)
{
	int count = 0;
	char ch;
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case '.':
			printf("!");
			count++;
			break;
		case '!':
			printf("!!");
			count++;
			break;
		default:
			printf("%c", ch);
			break;
		}
	}
	printf("\nTotal replace %d times\n", count);

	return 0;
}

#endif
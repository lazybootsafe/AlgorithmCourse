#if 0
#include <stdio.h>

int main(void)
{
	int count = 0;
	int halfpair = 0;
	char ch;

	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case 'e':
			halfpair = 1;
			break;
		case 'i':
			if (halfpair == 1)
			{
				count++;
				halfpair = 0;
			}
			break;
		default:
			halfpair = 0;
		}
	}
	printf("\nTotally exist %d \'ei\' in all char!\n", count);
	return 0;
}

#endif
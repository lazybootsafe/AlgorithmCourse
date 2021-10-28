#if 0
#include <stdio.h>

int main(void)
{
	int count = 0;
	char ch;
	while ((ch = getchar()) != '#')	//ÍË³öÌõ¼þ
	{
		if (ch == '!')				//Ì¾ºÅ×ªË«Ì¾ºÅ
		{
			printf("!!");
			count++;
		}
		else if (ch == '.')			//¾äºÅ×ªÌ¾ºÅ
		{
			printf("!");
			count++;
		}
		else
			printf("%c", ch);
	}
	printf("\nTotal replace %d times\n", count);

	return 0;
}

#endif
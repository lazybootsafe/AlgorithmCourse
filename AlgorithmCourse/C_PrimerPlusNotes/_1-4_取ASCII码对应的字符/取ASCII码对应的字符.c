#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch;

	system("color E9");
	printf("Enter the ASCII��");
	while (scanf_s("%d", &ch, sizeof(ch)) == 1)
	{
		printf("The character for %d is %c\n\n", ch, ch);
		printf("Enter next ANCII��");
	};
	printf("Bye!\n");

	getchar();
	getchar();
	getchar();
	return 0;

}
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function_a(char c);
void function_b(char c);
void function_c(char c);

int main(void)
{


	char ch;
	puts("a) Function A.\tb) Function B.\tc) Function C.\tq) Quit");
	printf("Enter a, b, c or q: ");
	scanf_s("%c", &ch, 1);
	
	void (*pf[3])(char);

	pf[0] = function_a;
	pf[1] = function_b;
	pf[2] = function_c;
	
	while (ch != 'q')
	{
		while (getchar() != '\n')
			continue;
		switch (ch)
		{
		case 'a':
			pf[0](ch);
			break;
		case 'b':
			pf[1](ch);
			break;
		case 'c':
			pf[2](ch);
			break;
		default:
			break;
		}
		puts("a) Function A.\tb) Function B.\tc) Function C.\tq) Quit");
		printf("Enter a, b, c or q: ");
		scanf_s("%c", &ch, 1);
	}
	puts("Done!");

	return 0;
}

void function_a(char c)
{
	printf("This is function_a you select %c\n", c);
}

void function_b(char c)
{
	printf("This is function_b you select %c\n", c);
}

void function_c(char c)
{
	printf("This is function_c you select %c\n", c);
}

#endif
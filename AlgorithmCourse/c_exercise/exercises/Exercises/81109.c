#if 0
#include <stdio.h>
#include <stdlib.h>

void show_menu(void);
float get_number(void);

int main(void)
{
	float a, b;
	char c;
	show_menu();
	c = getchar();
	while (1)
	{
		if (c == 'q' || c == 'Q')
			break;
		switch (c)
		{
		case 'a':
			printf("Enter first number: ");
			a = get_number();
			printf("Enter second number: ");
			b = get_number();
			printf("%g + %g = %g\n", a, b, a + b);
			break;
		case 's':
			printf("Enter first number: ");
			a = get_number();
			printf("Enter second number: ");
			b = get_number();
			printf("%g - %g = %g\n", a, b, a - b);
			break;
		case 'm':
			printf("Enter first number: ");
			a = get_number();
			printf("Enter second number: ");
			b = get_number();
			printf("%g * %g = %g\n", a, b, a * b);
			break;
		case 'd':
			printf("Enter first number: ");
			a = get_number();
			printf("Enter second number: ");
			while ((b = get_number()) == 0)
				printf("Enter a number other than 0: ");
			printf("%g / %g = %g\n", a, b, a / b);
			break;
		default:
			puts("Please enter a char, such as a,s,m,d or q.");
			break;
		}
		getchar();
		show_menu();
		c = getchar();
	}
	puts("Bye.");
	return 0;
}

void show_menu(void)
{
	puts("Enter the operation of your choice:");
	puts("a. add\t\ts. subtract");
	puts("m. multiply\td. divide");
	puts("q. quit");
}

float get_number(void)
{
	float a;
	char c;
	while (scanf_s("%f", &a) != 1)
	{
		while ((c = getchar()) != '\n')
			putchar(c);
		puts(" is not number.");
		printf("Please enter a number, such as 2.5,-1,78E8, or 3: ");
	}
	return a;
}

#endif
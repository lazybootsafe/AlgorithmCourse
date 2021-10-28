#if 0
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
char * mystrncpy(char *dest, char *src, int n);

int main(void)
{
	char destination[SIZE] = { 0 }, source[SIZE] = { 0 };
	int num;
	printf("Enter a string as source (blank to quit): ");
	fgets(source, SIZE, stdin);
	printf("Enter number of charactor you need to copy: ");
	scanf_s("%d", &num);
	while (*source != '\n')
	{
		mystrncpy(destination, source, num);
		printf("The destination string is: %s\n", destination);
		while (getchar() != '\n')
			break;
		printf("Enter a string as source(blank to quit): ");
		fgets(source, SIZE, stdin);
		printf("Enter number of charactor you need to copy: ");
		scanf_s("%d", &num);
	}

	return 0;
}

char * mystrncpy(char * dest, char * src, int n)
{
	int count = 0;
	while (*src != '\0' && count < n)
	{
		*(dest + count++) = *src++;
	}
	if (count < n)
	{
		while (count < n)
		{
			*(dest + count++) = '\0';
		}
	}
	return dest;
}

#endif
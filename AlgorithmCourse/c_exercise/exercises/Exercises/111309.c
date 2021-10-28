#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
char * invert_str(char * str);
char * invert_str2(char * str);

int main(void)
{
	char str[SIZE] = { 0 };
	//char *p = NULL;
	printf("Enter a string: ");
	fgets(str, SIZE, stdin);
	while (*str != '\n')
	{
		invert_str2(str);
		printf("The invert string is: %s\n", str);
		printf("Enter a string: ");
		fgets(str, SIZE, stdin);
	}
	return 0;
}

char * invert_str(char * str)
{
	int len = strlen(str);
	char temp[SIZE];
	for (int i = 0; i < len; i++)
		temp[i] = str[len - 1 - i];
	for (int i = 0; i < len; i++)
		str[i] = temp[i];

	return str;
}
char * invert_str2(char * str)
{
	int len = strlen(str);
	for (int i = 0; i < (len - 1) / 2; i++)
	{
		char temp;
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
	return str;
}

#endif
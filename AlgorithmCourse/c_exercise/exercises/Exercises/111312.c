#if 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 80
int check_words(char *string);
int check_upper(char *string);
int check_lower(char *string);
int check_punct(char *string);
int check_digit(char *string);

int main(void)
{
	char in[SIZE];
	int i = 0;
	while ((in[i++] = getchar()) != EOF)
	{
		if (i >= SIZE)
		{
			puts("Over flowed.");
			break;
		}
	}
	puts("You input complete.\nNow let's counting.");
	printf("Input words %d.\n", check_words(in));
	printf("Input upper char %d.\n", check_upper(in));
	printf("Input lower char %d.\n", check_lower(in));
	printf("Input punct char %d.\n", check_punct(in));
	printf("Input digital %d.\n", check_digit(in));

	return 0;
}

int check_words(char * string)
{
	int count = 0;
	int start = 0;
	while (*string != EOF)
	{
		if (isalpha(*string) == 0 && start == 0)
			string++;
		else if (isalpha(*string) == 0 && start == 1)
		{
			string++;
			count++;
			start = 0;
		}
		else if (isalpha(*string) != 0)
		{
			string++;
			start = 1;
		}
	}
	if (start == 1)
		count++;
	return count;
	return 0;
}

int check_upper(char * string)
{
	int count = 0;
	while (*string != EOF)
	{
		if (isupper(*string++) != 0)
			count++;
	}
	return count;
}

int check_lower(char * string)
{
	int count = 0;
	while (*string != EOF)
	{
		if (islower(*string++) != 0)
			count++;
	}
	return count;
}

int check_punct(char * string)
{
	int count = 0;
	while (*string != EOF)
	{
		if (ispunct(*string++) != 0)
			count++;
	}
	return count;
}

int check_digit(char * string)
{
	int count = 0;
	while (*string != EOF)
	{
		if (isdigit(*string++) != 0)
			count++;
	}
	return count;
}

#endif
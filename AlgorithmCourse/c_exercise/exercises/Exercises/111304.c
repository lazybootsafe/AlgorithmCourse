#if 0
#include <stdio.h>
#include <stdlib.h>

#define SIZE 40
char * get_word(char * out, int len);

int main(void)
{
	char out[SIZE] = { 0 };
	get_word(out, SIZE);
	printf("First word is: %s", out);

	return 0;
}

char * get_word(char * out, int len)
{
	char input[SIZE] = { 0 };
	char *in = input;
	int i = 0;
	puts("Enter a string:");
	fgets(input, SIZE, stdin);
	while ((*in == '\n') || (*in == '\t') || (*in == ' ') && (*in != '\0'))
		in++;
	while ((*in != '\n') && (*in != '\t') && (*in != ' ') && (*in != '\0') && i < len)
	{
		*out++ = *in++;
		i++;
	}
	return out;
}

#endif
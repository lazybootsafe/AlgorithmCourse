#if 0
#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

char * get_word(char *out);

int main(void)
{
	char out[SIZE] = { 0 };
	get_word(out);
	printf("First word is: %s", out);

	return 0;
}

char * get_word(char * out)
{
	char input[SIZE] = { 0 }; 
	char *in = input;
	puts("Enter a string:");
	fgets(input, SIZE, stdin);

	while ((*in == '\n') || (*in == '\t') || (*in == ' ') && *in != '\0')
		in++;
	while ((*in != '\n') && (*in != '\t') && (*in != ' ') && (*in != '\0'))
		*out++ = *in++;

	return out;
}

#endif
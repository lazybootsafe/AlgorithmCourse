#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char ch;
	char find_ch;
	char input[256] = { 0 };
	int repeat_time = 0;
	FILE *pFile;

	if (argc < 2)
	{
		printf("Usage: %s <character>[file_name1 ....]", argv[0]);
		exit(EXIT_FAILURE);
	}
	find_ch = argv[1][0];
	if (argc == 2)
	{
		printf("Enter the string you wanted to analysize: ");
		gets_s(input, 256);
		int input_length = strlen(input);
		for (int i = 0; i < input_length; i++)
		{
			if (find_ch == input[i])
				repeat_time++;
		}
		printf("In string\"%s\",%c have appeared %d times!\n", \
			input, find_ch, repeat_time);
	}
	else
	{
		for (int i = 2; i < argc; i++)
		{
			repeat_time = 0;
			if ((fopen_s(&pFile, argv[i], "r")) != 0)
			{
				printf("Can't open %s\n", argv[i]);
				continue;
			}
			while ((ch = fgetc(pFile)) != EOF)
			{
				if (ch == find_ch)
					repeat_time++;
			}
			printf("In file %s, %c have appeared %d time!\n", \
				argv[i], find_ch, repeat_time);
		}
	}

	return 0;
}

#endif
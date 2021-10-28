#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
int string_in(char *str, char *sub);

int main(int argc, char *argv[])
{
	FILE *pFile;
	char szBuffer[SIZE];
	char *seek_string;
	if (argc < 3)
	{
		printf("Usage:%s string file name ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	seek_string = argv[1];
	if ((fopen_s(&pFile, argv[2], "r")) != 0)
	{
		printf("Can't open the file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while (fgets(szBuffer, SIZE, pFile) != NULL)
	{
		if (strstr(szBuffer, seek_string))
			puts(szBuffer);
	}

	return 0;
}

int string_in(char *str, char *sub)
{
	int count = 0;
	int src_len = strlen(sub);
	while (*str != '\0'&&count < src_len)
	{
		if (*(str + count) == *(sub + count))
			count++;
		else
		{
			count = 0;
			str++;
		}
	}
	if (count == src_len)
		return 1;
	else
		return 0;
}

#endif
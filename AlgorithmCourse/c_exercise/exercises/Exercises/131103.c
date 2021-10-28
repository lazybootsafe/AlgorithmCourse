#if 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	FILE *pFile1, *pFile2;
	char file_name[30] = { 0 };
	char temp[] = "tmp.txt";
	char ch = 0;
	printf("Enter the file name: ");
	gets_s(file_name, 30);

	if ((fopen_s(&pFile1, file_name, "r+")) != 0)
	{
		printf("Can't open file %s.\n", file_name);
		exit(EXIT_FAILURE);
	}
	if ((fopen_s(&pFile2, temp, "w")) != 0)
	{
		printf("Can't open file %s as write mode.\n", temp);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(pFile1)) != EOF)
	{
		ch = toupper(ch);
		putc(ch, pFile2);
	}

	fclose(pFile1);
	fclose(pFile2);
	if ((fopen_s(&pFile1, temp, "r")) != 0)
	{
		printf("Can't open file %s.\n", temp);
		exit(1);
	}
	if ((fopen_s(&pFile2, file_name, "w")) != 0)
	{
		printf("Can't open file %s.\n", file_name);
		exit(1);
	}
	while ((ch = fgetc(pFile1)) != EOF)
	{
		fputc(ch, pFile2);
	}
	fclose(pFile1);
	fclose(pFile2);
	remove(temp);

	return EXIT_SUCCESS;
}

#endif
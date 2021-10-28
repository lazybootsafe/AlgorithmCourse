#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 41
int get_number(FILE * fp);

int main(void)
{
	FILE *pFile;
	char words[SIZE];
	int count = 1;

	if ((fopen_s(&pFile, "wordy", "a+")) != 0)
	{
		fprintf(stderr, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	count = get_number(pFile);
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf_s(stdin, "%40s", &words, SIZE)) == 1 && (words[0]) != '#')
		fprintf(pFile, "%d.%s\n", ++count, words);
	puts("File contents:");
	rewind(pFile);
	while (fscanf_s(pFile, "%s", &words, SIZE) == 1)
		puts(words);
	puts("Done!");
	if (fclose(pFile) != 0)
		fprintf(stderr, "Error closing file\n");

	return 0;
}

int get_number(FILE * fp)
{
	int i = 0;
	char temp[SIZE];
	rewind(fp);
	while (fgets(temp, SIZE, fp) != NULL)
		i++;
	return i;
}

#endif
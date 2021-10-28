#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int main(int argc, char *argv[])
{
	FILE *fa, *fs;
	int files = 0;
	char file_app[SLEN];
	char file_src[SLEN];
	int ch;
	if (argc < 3)
	{
		fprintf(stderr, "Usage:%s dest_file src_file.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fopen_s(&fa, argv[1], "a+")) != 0)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create dest buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	files = argc - 2;
	while (files > 0)
	{
		if ((fopen_s(&fs, argv[argc - files], "r")) != 0)
			fprintf(stderr, "Can't open %s\n", argv[argc - files]);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n", argv[0]);
			if (ferror(fa) != 0)
				fprintf(stderr, "Error in writing file %s.\n", argv[1]);
			fclose(fs);
			printf("File %s appended.\n", argv[1]);
			if (files > 0)
				printf("Next file %s:\n", argv[argc - (--files)]);
			else
				printf("No more file to appended.\n");
		}
	}
	printf("Done appended, and %d files appended.\n", argc - 2);
	rewind(fa);
	printf("%s contents:\n", argv[1]);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("Done displaying.");
	fclose(fa);

//	FILE *fa, *fs;
//	int files = 0;
//	int ch;
//
//	if (argc < 3)
//	{
//		printf("Usage: %s dest_file source1_file ...\n", argv[0]);
//		return;
//	}
//
//	if ((fopen_s(&fa, argv[1], "a+")) != 0)
//	{
//		fprintf(stderr, "Can't open %s\n", argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
//	{
//		fputs("Can't create output buffer\n", stderr);
//		exit(EXIT_FAILURE);
//	}
//	for (int i = 2; i < argc; i++)
//	{
//		if (strcmp(argv[1], argv[i]) == 0)
//		{
//			fputs("Can't append file to itself\n", stderr);
//		}
//		else if ((fopen_s(&fs, argv[i], "r")) != 0)
//		{
//			fprintf(stderr, "Can't open %s\n", argv[i]);
//		}
//		else
//		{
//			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
//			{
//				fputs("Can't create input buffer\n", stderr);
//				continue;
//			}
//			append(fs, fa);
//			if (ferror(fs) != 0)
//			{
//				fprintf(stderr, "Error in reading file %s.\n", argv[i]);
//			}
//			if (ferror(fa) != 0)
//			{
//				fprintf(stderr, "Error in writing file %s.n", argv[1]);
//			}
//			fclose(fs);
//			files++;
//			printf("File %s appended.\n", argv[i]);
//		}
//	}
//
//	printf("Done appending. %d files appended.\n", files);
//	rewind(fa);
//	printf("%s contents:\n", argv[1]);
//	while ((ch = getc(fa)) != EOF)
//	{
//		putchar(ch);
//	}
//	puts("Done displaying!\n");
//	fclose(fa);
//
	return 0;
}

void append(FILE * source, FILE * dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}

char * s_gets(char * st, int n)
{
	return NULL;
}

#endif
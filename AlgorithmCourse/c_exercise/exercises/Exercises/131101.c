#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch;
	FILE *fp;
	unsigned long count = 0;
	char file_name[50];
	printf("Enter the file name: ");
	//scanf_s("%s", &file_name, 50);
	gets_s(file_name, 50);
	if ((fopen_s(&fp, file_name, "r")) != 0)
	{
		printf("Can't open %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putchar(ch);
		count++;
	}
	fclose(fp);
	printf("\nFile %s has %lu characters\n", file_name, count);

	return 0;
}

#endif
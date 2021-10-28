#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

int main(void)
{
	FILE * pFile;
	char szFileName[40];
	long nPosition;
	char szBuffer[SIZE];

	printf("Enter a file name: ");
	gets_s(szFileName, 40);
	if ((fopen_s(&pFile, szFileName, "r")) != 0)
	{
		printf("Can't open file %s.\n", szFileName);
		exit(EXIT_FAILURE);
	}
	printf("Enter the position to read (q or -1 to quit): ");
	while (scanf_s("%ld", &nPosition) == 1 && nPosition >= 0)
	{
		fseek(pFile, nPosition, SEEK_SET);
		if (fgets(szBuffer, SIZE, pFile) != NULL)
			printf("Content is: %s", szBuffer);
		printf("Enter the position to read (q or -1 to quit): ");
	}
	fclose(pFile);

	return 0;
}

#endif 
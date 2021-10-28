#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *pFile1, *pFile2;
	char szFileName1[128] = { 0 };
	char szFileName2[128] = { 0 };
	char szBuffer1[256] = { 0 };
	char szBuffer2[256] = { 0 };

	printf("Enter the first file name: ");
	gets_s(szFileName1, 128);

	printf("Enter the second file name: ");
	gets_s(szFileName2, 128);
	if ((fopen_s(&pFile1, szFileName1, "r")) != 0)
	{
		printf("Can't open file %s\n", szFileName1);
		exit(EXIT_FAILURE);
	}
	if ((fopen_s(&pFile2, szFileName2, "r")) != 0)
	{
		printf("Can't open file %s\n", szFileName2);
		exit(EXIT_FAILURE);
	}
	while ((feof(pFile1) == 0) || (feof(pFile2) == 0))
	{
		if (fgets(szBuffer1, 256, pFile1) != NULL)
		{
			//实现B要求添加收下代码
			/*
			int length = strlen(szBuffer1);
			if (szBuffer1[length - 1] == '\n')
				szBuffer1[length - 1] = '\0';
			*/
			fputs(szBuffer1, stdout);
		}
		if (fgets(szBuffer2, 256, pFile2))
		{
			fputs(szBuffer2, stdout);
		}
	}

	return 0;
}

#endif 
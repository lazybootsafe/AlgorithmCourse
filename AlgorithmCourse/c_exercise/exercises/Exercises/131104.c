#if 0
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//1
	//FILE *pFile;
	//char ch;
	//for (int i = 0; i < argc - 1; i++)
	//{
	//	if ((fopen_s(&pFile, argv[i + 1], "r")) == 0)
	//	{
	//		printf("Now print file %s.\n", argv[i + 1]);
	//		while ((ch = getc(pFile)) != EOF)
	//			putchar(ch);
	//		printf("\n");
	//		fclose(pFile);
	//	}
	//	else
	//	{
	//		printf("Open %s failed.\n", argv[i]);
	//		exit(EXIT_FAILURE);
	//	}
	//}
	//printf("All done, it is %d file printed.\n", argc - 1);

	//2
	FILE *pFile;
	char buf[256] = { 0 };
	for (int i = 1; i < argc; i++)
	{
		if ((fopen_s(&pFile, argv[i], "r")) != 0)
			printf("Can't open file %s.\n", argv[i]);
		printf("%s: \n", argv[i]);
		while (fgets(buf, 256, pFile) != NULL)
			fputs(buf, stdout);
		printf("\n");
	}
	printf("Done.\n");

	return 0;
}

#endif
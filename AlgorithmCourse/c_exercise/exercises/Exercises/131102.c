#if 0
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

//int main(int argc, char **argv)
//{
//	FILE *fp1, *fp2;
//	char buffer[BUFFER_SIZE] = { 0 };
//	if (argc != 3)
//	{
//		printf("Usage:%s source file dest file\n", argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		if ((fopen_s(&fp1, argv[1], "wb")) != 0)
//		{
//			printf("Can't open %s.\n", argv[1]);
//			exit(EXIT_FAILURE);
//		}
//		if ((fopen_s(&fp2, argv[2], "wb")) != 0)
//		{
//			printf("Can't open %s.\n", argv[2]);
//			exit(EXIT_FAILURE);
//		}
//	}
//	size_t bytes;
//	while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, fp1)) > 0)
//	{
//		fwrite(buffer, sizeof(char), bytes, fp2);
//	}
//	fclose(fp1);
//	fclose(fp2);
//
//	return 0;
//}

int main(void)
{
	FILE *fp1, *fp2;
	char *file1 = "data1.dat";
	char *file2 = "data2.dat";
	int ch = 0;

	if ((fopen_s(&fp1, file1, "rb")) != 0)
	{
		printf("Can't open %s.\n", file1);
		exit(EXIT_FAILURE);
	}
	if ((fopen_s(&fp2, file2, "wb")) != 0)
	{
		printf("Can't open %s.\n", file2);
		exit(EXIT_FAILURE);
	}
	while ((ch = fgetc(fp1)) != EOF)
	{
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);

	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(void)
{
	//FILE *in, *out;
	//int ch;
	//char out_file[LEN];
	//char in_file[LEN];
	//int count = 0;
	//printf("Enter the file name: ");
	//scanf_s("%s", in_file, LEN);
	//if ((fopen_s(&in, in_file, "r")) != 0)
	//{
	//	fprintf(stderr, "I couldn't open the file\"%s\"\n", in_file);
	//	exit(EXIT_FAILURE);
	//}
	//strncpy_s(out_file, sizeof(out_file), in_file, LEN - 5);//(out_file, in_file, LEN - 5);
	//out_file[LEN - 5] = '\0';
	////strcat(out_file,".red");
	//strcat_s(out_file, sizeof(out_file), ".red");
	//if ((fopen_s(&out, out_file, "w")) != 0)
	//{
	//	fprintf(stderr, "Can't create output file.\n");
	//	exit(3);
	//}
	//while ((ch = getc(in)) != EOF)
	//{
	//	if (count++ % 3 == 0)
	//		putc(ch, out);
	//}
	//if (fclose(in) != 0 || fclose(out) != 0)
	//	fprintf(stderr, "Error in closing file\n");

	FILE *in, *out;
	int ch;
	char in_file[LEN];
	char out_file[LEN];
	int count = 0;
	printf("Enter the file name: ");
	gets_s(in_file, LEN);
	if ((fopen_s(&in, in_file, "r")) != 0)
	{
		fprintf(stderr, "I couldn't open file\"%s\"", in_file);
		exit(EXIT_FAILURE);
	}
	strncpy_s(out_file, sizeof(out_file), in_file, LEN);
	out_file[LEN - 5] = '\0';
	strcat_s(out_file, sizeof(out_file), ".red");

	if ((fopen_s(&out, out_file, "w")) != 0)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}
	while ((ch = getc(in)) != EOF)
	{
		//第一个字符后每三个字符提取一个字符写入新文件
		if (count++ % 3 == 0)
			putc(ch, out);
	}
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing file\n");

	return 0;
}

#endif
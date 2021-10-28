
/*�����в����ṩ����һ�����ַ������ڶ������ļ�������ӡ�ļ��а����ַ�����������*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char * argv[])
{
	FILE * fp;
	char line[SIZE];

	system("color 0A");
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fp, argv[2], "r") != 0)
	{
		fprintf(stderr, "Can't open file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	//���ζ���һ���ִ���������ִ��������м�������ִ������������
	while (fgets(line, SIZE, fp) != NULL)
	{
		if (strstr(line, argv[1]) != NULL)
		{
			fputs(line, stdout);
		}
	}
	//����д����
	if (ferror(fp) != 0)
	{
		fprintf(stderr, "Error in reading file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	//��β����
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error in closing file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;
}
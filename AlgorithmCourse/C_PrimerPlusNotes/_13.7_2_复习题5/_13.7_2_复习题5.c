#include <stdio.h>
#include <stdlib.h>
//#include <console.h>					//���Mac�û�
#include <string.h>

#define SIZE 256

int has_ch(char ch, char * line);		//Ѱ���ַ����е�ָ���ַ�

int main(int argc, char * argv[])
{
	char ch;
	FILE * fp;
	char line[SIZE];

	/*�����ܣ�����2�������в�������һ����һ���ַ����ڶ������ļ����������ӡ�ļ��а��������ַ�����
	ע�⣺����Macintosh��ʹ��console.h��ccomand()*/

	system("color 5A");
	//argc = ccommand(&argv);
	if (argc != 3)
	{
		printf("Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	ch = argv[1][0];				//ȡ�����в����ĵ�һ���ַ�
	if (fopen_s(&fp, argv[2], "r") != 0)
	{
		printf("Can't open %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, SIZE, fp) != NULL)
	{
		if (has_ch(ch, line))
		{
			fputs(line, stdout);
		}
	}
	if (ferror(fp) != 0)
	{
		printf("Reading \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fclose(fp);

	system("pause");
	return 0;
}

int has_ch(char ch, char * line)
{
	/*��1
	return strchr(line, ch) != NULL ? 1 : 0;*/		//������֮ǰѧ���ַ���ϵ�к�����

	//��2
	while (*line)
	{
		if (ch == *line++)					//��������������ȼ����ڼ����������������ˣ�����һ��
		{
			return 1;
		}
	}

	return 0;
}
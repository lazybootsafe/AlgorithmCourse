/*��д13.2�����������У���ʾ�û�����*/

#include <stdio.h>
#include <stdlib.h>				//����exit()
#include <string.h>				//�ṩstrchr(), strncpy(), strcat()��ԭ��

#define SIZE 81

int main(int argc, char * argv[])
{
	FILE * in, *out;			//�ļ�ָ��
	int ch;
	char file_in[SIZE];			//��������ļ���
	char file_out[SIZE];
	char temp[SIZE];
	int count = 0;
	errno_t err;
	char * pos;
	int cpylen;

	system("color 0A");
	puts("Enter file for inputing:");
	gets_s(file_in, SIZE);

	//ʵ������
	if (err = fopen_s(&in, file_in, "r"))
	{
		fprintf(stderr, "Open file \"%s\" failed.\n", file_in);
		exit(EXIT_FAILURE);
	}

	//ʵ�����
	puts("Enter file for outputing:");
	gets_s(temp, SIZE);
	if (pos = strchr(temp, '.'))
	{
		cpylen = pos - temp;
	}
	else
	{
		cpylen = strlen(temp);
	}
	strncpy_s(file_out, SIZE, temp, cpylen);				//�����ļ����������У�test.txt��ǰ�벿��test��������
	strcat_s(file_out, SIZE, ".red");						//��Ӻ�׺��.red
	if (err = fopen_s(&out, file_out, "w"))
	{
		fprintf(stderr, "Open file \"%s\" failed.\n", file_out);
		exit(EXIT_FAILURE);
	}

	//��������
	while (((ch = getc(in)) != EOF))
	{
		if (count++ % 3 == 0)
		{
			putc(ch, out);								//��.red�ļ���ӡÿ3���ַ��ĵ�һ��
		}
	}

	//��β����
	if (fclose(in) || fclose(out))
	{
		fprintf(stderr, "Errors in closing files.\n");
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;
}
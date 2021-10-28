
//�����л������������в����ṩ�����ļ��������ļ�����ѹ����.red��ͬ���ļ���

#include <stdio.h>
#include <stdlib.h>				//����exit()
#include <string.h>				//�ṩstrchr(), strncpy(), strcat()��ԭ��

#define SIZE 81

int main(int argc, char * argv[])
{
	FILE * in, *out;			//�ļ�ָ��
	int ch;
	char name[SIZE];			//��������ļ���
	int count = 0;				
	errno_t err;
	char * pos;
	int cpylen;

	system("color 0A");
	//��������в���
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//ʵ������
	if (err = fopen_s(&in, argv[1], "r"))
	{
		fprintf(stderr, "Open file \"%s\" failed.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	//ʵ�����
	if (pos = strchr(argv[1], '.'))
	{
		cpylen = pos - argv[1];
	}
	else
	{
		cpylen = strlen(argv[1]);
	}
	strncpy_s(name, SIZE, argv[1], cpylen);				//�����ļ����������У�test.txt��ǰ�벿��test��������
	strcat_s(name, SIZE, ".red");						//��Ӻ�׺��.red
	if (err = fopen_s(&out, name, "w"))
	{
		fprintf(stderr, "Open file \"%s\" failed.\n", name);
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
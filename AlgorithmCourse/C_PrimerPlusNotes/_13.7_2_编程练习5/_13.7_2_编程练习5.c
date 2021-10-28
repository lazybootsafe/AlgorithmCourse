
//�ٴ���Ϥ�������ļ�IO���Ѷ���ļ��Ķ���������׷�ӵ�һ���ļ���,�����в���ʵ��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZEFILE 81
#define SIZEBUF 1024

void append(FILE * src, FILE * dest);

int main(int argc,char * argv[])
{

	FILE * fa, * fs;				//faָ��׷�ӵ�Ŀ���ļ���fsָ��Դ�ļ�
	int count = 0;					//Դ�ļ�������

	system("color 5A");
	if (argc < 3)
	{
		fprintf(stderr, "Have no destination filr or resource file.\n");
		exit(EXIT_FAILURE);
	}

	//��Ҫ׷�ӵ�Ŀ���ļ�,�����������ı�����
	if (fopen_s(&fa, argv[1], "a") != 0)
	{
		fprintf(stderr, "Can't open file %s!\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	//����������Ļ�����
	if (setvbuf(fa, NULL, _IOFBF, SIZEBUF) != 0)
	{
		fputs("Can't create output buffer!\n", stderr);
		exit(EXIT_FAILURE);
	}

	//ѭ����ȡԴ�ļ�����׷��
	for (int i = 2; i < argc; i++)
	{
		//����ļ����ظ�,���������������һ��Դ�ļ���
		if (strcmp(argv[i], argv[1]) == 0)
		{
			fputs("Can't append file to itself.\n", stderr);
		}
		//��Դ�ļ���������������ı�����,�ɹ�������ʧ��������һ��Դ�ļ���
		else if (fopen_s(&fs, argv[i], "r") != 0)
		{
			fprintf(stderr, "Can't open file %s!\n", fs);
		}
		else
		{
			//�����������Ļ�����
			if (setvbuf(fs, NULL, _IOFBF, SIZEBUF) != 0)
			{
				fputs("Can't create input buffer!\n", stderr);
				continue;
			}
			append(fs, fa);									//׷������
			//����д����
			if (ferror(fa) != 0)
			{
				fprintf(stderr, "Error in writing file %s.\n", argv[1]);
			}
			if (ferror(fs) != 0)
			{
				fprintf(stderr, "Error in reading file %s.\n", argv[i]);
			}
			fclose(fs);										//�ر�Դ�ļ�(ͬʱ���ٻ�����)
			++count;										//������+1
		}
	}
	fclose(fa);												//�ر�׷���ļ�(ͬʱ���ٻ�����)
	fprintf(stdout, "Done. %d files appended.\n", count);

	system("pause");
	return 0;

}

void append(FILE * src, FILE * dest)
{
	size_t count;
	static char temp[SIZEBUF];								//����һ��

	while ((count = fread(temp, sizeof(char), SIZEBUF, src)) > 0)			
	{
		fwrite(temp, sizeof(char), count, dest);
	}
}
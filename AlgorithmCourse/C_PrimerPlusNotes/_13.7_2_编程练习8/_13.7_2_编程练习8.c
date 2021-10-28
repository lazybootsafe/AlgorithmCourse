/*����Ҫ��
��һ���ַ���0�������ļ�����Ϊ�����в���������ַ���û�в������棬�����ȡ��׼�����ļ���
���򣬳���һ�δ�ÿ���ļ���Ȼ�󱨸�ÿ���ļ��и��ַ��ĳ��ִ������ļ������ַ�������ͬ����ֵ
һ�𱨸档�����а��������飬��ȷ��������Ŀ�Ƿ���ȷ���Ƿ��ܴ��ļ���������ܴ��ļ�����
��Ҫ������һ���Ȼ�����������һ�ļ���
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 81

int count(int ch, FILE ** fp);

int main(int argc, char * argv[])
{
	char file[SIZE];
	FILE * fp;
	int i = 2;

	system("color 0A");
	if (argc < 2 )
	{
		fprintf(stderr, "The number of order-paramater is not enough.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		//�ӱ�׼��������ȡһ���ļ������򿪵õ��ı�����������Ϣ
		puts("Enter the file name:");
		gets_s(file, SIZE);
		if (fopen_s(&fp, file, "r") != 0)
		{
			fprintf(stderr, "Can't open file %s.\n", file);
			exit(EXIT_FAILURE);
		}
		printf("The \'%c\' has %d in the file %s.\n", argv[1][0], count(argv[1][0], &fp), file);
		if (ferror(fp) != 0)
		{
			fprintf(stderr, "Error in reading %s\n", file);
			exit(EXIT_FAILURE);
		}
		fclose(fp);
	}
	else
	{
		//�������в�����ȡ����ļ������򿪵õ��ı�����������Ϣ
		while (i < argc)
		{
			if (fopen_s(&fp, argv[i], "r") != 0)
			{
				fprintf(stderr, "Can't open file %s.\n", file);
				continue;
			}
			printf("The \'%c\' has %d in the file %s.\n", argv[1][0], count(argv[1][0], &fp), argv[i]);
			if (ferror(fp) != 0)
			{
				fprintf(stderr, "Error in reading %s\n", argv[i]);
				continue;
			}
			fclose(fp);
			i++;
		}
	}

	system("pause");
	return 0;
}


int count(int ch, FILE ** fp)
{
	int temp;
	int ct = 0;

	while ((temp = getc(*fp)) != EOF)
	{
		if (ch == temp)
		{
			ct++;
		}
	}

	return ct;
}
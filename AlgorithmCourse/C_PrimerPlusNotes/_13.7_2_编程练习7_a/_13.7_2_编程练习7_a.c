/*ʹ�������л��û����룬��2���ļ���
��ӡ��һ���ļ��ĵ�һ�С��ڶ����ļ��ĵ�һ��
	��һ���ļ��ĵڶ��С��ڶ����ļ��ĵڶ��У�
�������ƣ�ֱ����ӡ�������϶���ļ������һ�С�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 81
#define LSIZE 256

void adjust(FILE ** fa, FILE ** fb);
int getlines(FILE * fp);

int main(int argc, char * argv[])
{
	FILE * fa;
	FILE * fb;
	char file_a[SIZE];
	char file_b[SIZE];
	char line_a[LSIZE];
	char line_b[LSIZE];

	system("color 0A");
	//��ȡ�ļ���
	if (argc == 3)
	{
		strcpy_s(file_a, SIZE, argv[1]);
		strcpy_s(file_b, SIZE, argv[2]);
	}
	else
	{
		puts("Enter first file name:");
		gets_s(file_a, SIZE);
		puts("Second file name:");
		gets_s(file_b, SIZE);
	}

	//���ı�������
	if (fopen_s(&fa, file_a, "r"))					//ֻ�����ı���
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fb, file_b, "r"))					//ֻ�����ı���
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	//�����ļ�ָ��
	adjust(&fa, &fb);

	//��ӡ��Ϣ
	while (fgets(line_a, LSIZE, fa) != NULL)
	{
		fputs(line_a, stdout);
		if (fgets(line_b, LSIZE, fb) != NULL)
		{
			fputs(line_b, stdout);
		}
	}

	//����д����
	if (ferror(fa) != 0)
	{
		fprintf(stderr, "Error in reading %s\n", file_a);
		exit(EXIT_FAILURE);
	}
	if (ferror(fb) != 0)
	{
		fprintf(stderr, "Error in reading %s\n", file_b);
		exit(EXIT_FAILURE);
	}

	//�ر��ļ�������
	if (_fcloseall() == 0)
	{
		fprintf(stderr, "Failed in closing files!");
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;
}

//�����ļ�ָ�롣ǰ�߽�ָ���н�������ļ�����
void adjust(FILE ** fa, FILE ** fb)
{
	int ct_a = 0;
	int ct_b = 0;
	FILE * temp;

	ct_a = getlines(*fa);
	ct_b = getlines(*fb);
	if (ct_a < ct_b)
	{
		temp = *fa;
		*fa = *fb;
		*fb = temp;
	}
}

//��ȡ�ļ�������
int getlines(FILE * fp)
{
	int ch;
	int pre;
	int ct = 0;

	while ((ch = getc(fp)) != EOF)
	{
		if (ch == '\n')
		{
			++ct;						//�м���������
			pre = ch;
		}
	}
	if (pre != '\n')
	{
		++ct;							//ͳ�Ʋ���ȫ��
	}
	rewind(fp);							//�ļ�λ��ָʾ����λ���ļ�ͷ

	return ct;
}
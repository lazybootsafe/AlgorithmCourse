
/*�����״�����ʱ����һ����words���ļ������û��������Ϣ���浽�ļ���.
Ϊ¼��ĵ��ʱ�ţ��´�¼��ʱ����Ŵ�֮ǰ��һ��������ʼ��*/

#include <stdio.h>
#include <stdlib.h>					//�ṩ��exit()�ĺ���ԭ��
#include <ctype.h>
#include <string.h>

#define SIZE 41
#define CTRL_Z '\32'

void createID(char * str, int size, int ID);
int IDlen(int ID);

int main(void)
{
	FILE * fp;								//�ļ�ָ��
	char words[SIZE];						//��ʱ�ַ���
	int ch;
	int ID = 0;
	long pos = 0L;
	int prenum = 0;
	int index = 0;

	system("color 5A");
	//���ļ����״δ������Ժ�׷�ӣ�
	if (fopen_s(&fp, "words", "a+"))
	{
		fprintf(stderr, "Open file \"words\" failed");
		exit(EXIT_FAILURE);
	}
	//��ȡ���е��ʵ����һ�����
	while ((ch = getc(fp)) != EOF)
	{
		if (isdigit(ch))
		{
			ungetc(ch, fp);										//�Ż������ַ����ı�����
			fscanf_s(fp, "%d", &ID, SIZE);						//�������ĵ��ʱ�ţ������һ�����ʱ��,ͬʱ�ƶ�����ָ�뵽��һ���������ַ�
		}
	}

	//��ȡ���뵽�ļ�
	fprintf(stdout, "Enter words add to the file \"words\"\n");
	fprintf(stdout, "(press the CTRL+Z at the begining of a line to terminate): \n");

mark1:
	while (scanf_s("%s", words, SIZE) == 1 && words[0] != CTRL_Z)
	{
		while (words[index] != '\0')
		{
			if (isdigit(words[index++]))
			{
				fprintf(stderr, "Words must be consisted of letters.\n");
				goto mark1;
			}
		}
		createID(words, SIZE, ++ID);
		fprintf(fp, words);					//֮ǰ�򿪵�fpָ����ļ�������׷�ӵķ�ʽ�򿪵ģ��������ļ�д���ʽ���ַ���ʱ��ֻ�����ļ�β���
		putc('\n', fp);						//ÿ�����ʷ���д��
	}

	//�����ļ�����
	puts("File contents:");
	rewind(fp);								//���ļ��ڲ���ָ������ָ��һ�����Ŀ�ͷ
	while (fscanf_s(fp, "%s", words, SIZE) == 1)
	{
		puts(words);
	}

	//�ر��ļ�
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error closing file.\n");
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;
}

void createID(char * str, int size, int ID)
{
	int end;
	int idlen;
	char temp[SIZE];

	end = strlen(str);
	idlen = IDlen(ID);

	//ȷ�������ź��ַ���û�г����ַ�����ĳ���,������ȣ����һ��λ���������ַ�
	if (end + idlen + 1 < size)		//�ַ�������+��ų���+һ����.������
	{
		//�����ַ�����ƶ�idlen+1���ֽ�
		for (int i = end; i >= 0; i--)
		{
			str[i + idlen + 1] = str[i];
		}
		//�ճ�����ǰidlen���ֽ�λ��д����
		sprintf_s(temp, SIZE, "%d", ID);
		for (unsigned int i = 0; i < strlen(temp); i++)
		{
			str[i] = temp[i];
		}
		str[strlen(temp)] = '.';
	}
}

int IDlen(int ID)
{
	char dest1[SIZE];

	sprintf_s(dest1, SIZE, "%d", ID);

	return strlen(dest1);
}
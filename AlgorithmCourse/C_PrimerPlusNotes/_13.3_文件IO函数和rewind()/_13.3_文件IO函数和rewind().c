
/*�����״�����ʱ����һ����words���ļ������û��������Ϣ���浽�ļ���*/

#include <stdio.h>
#include <stdlib.h>					//�ṩ��exit()�ĺ���ԭ��

#define SIZE 41

int main(void)
{
	FILE * fp;								//�ļ�ָ��
	char words[SIZE];						//��ʱ�ַ���

	system("color 5A");
	//���ļ����״δ������Ժ�׷�ӣ�
	if (fopen_s(&fp, "words", "a+"))
	{
		fprintf(stderr, "Open file \"words\" failed");
		exit(EXIT_FAILURE);
	}

	//��ȡ���뵽�ļ�
	fprintf(stdout, "Enter words add to the file \"words\"\n");
	fprintf(stdout, "(press the Enter key at the begining of a line to terminate): \n");
	while (gets_s(words, SIZE) != NULL && words[0] != '\0')
	{
		fprintf(fp, words);					//֮ǰ�򿪵�fpָ����ļ�������׷�ӵķ�ʽ�򿪵ģ��������ļ�д���ʽ���ַ���ʱ��ֻ�����ļ�β���
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

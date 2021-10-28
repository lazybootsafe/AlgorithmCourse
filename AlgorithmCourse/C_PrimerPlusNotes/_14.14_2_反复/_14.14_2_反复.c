#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
#define AMOUNT 10
#define FNAME "book.dat"


struct book
{
	char title[SIZE];
	char author[SIZE];
	float value;
};

int main(void)
{
	struct book library[AMOUNT];
	FILE * fp;
	int count = 0;
	int filecount;
	size_t size = sizeof(struct book);

	system("color 0A");
	//���ļ���
	if (fopen_s(&fp, FNAME, "a+b") != 0)
	{
		fputs("���ļ�ʧ�ܣ�", stderr);
		exit(EXIT_FAILURE);
	}

	//�����ļ���ͼ���¼����д��ṹ����
	rewind(fp);															//ȷ���ļ�λ��ָʾ�����ļ���
	while (count < AMOUNT && fread(&library[count], size, 1, fp) == 1)
	{
		if (count == 0)
		{
			printf("�����ļ��ڵ�ͼ���¼:\n", FNAME);
		}
		printf("��%s�� ���ߣ�%s �۸�%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;													//�ļ��ڵļ�¼��

	//����Ƿ�ﵽ���ͼ������
	if (count == AMOUNT)
	{
		fputs("The file is full.", stderr);
		exit(EXIT_FAILURE);
	}

	//����¼��
	puts("�������������ͼ���¼��");
	puts("�������µ�������");
	puts("��һ�еĿ�ͷ���»س���ֹͣ¼��:");
	while (count < AMOUNT && gets_s(library[count].title, SIZE) != NULL && library[count].title[0] != '\0')
	{
		puts("������������:");
		gets_s(library[count].author, SIZE);
		puts("������۸�");
		scanf_s("%f", &library[count].value);
		while (getchar() != '\n')
		{
			;
		}
		count++;
		puts("��������һ��������ֱ�Ӽ�����н�������");
	}

	//�����ܼ�¼
	if (count > 0)
	{
		puts("�������ڵ���Ŀ�嵥��");
		for (int i = 0; i < count; i++)
		{
			printf("��%s�� ���ߣ�%s �۸�%.2f\n", library[i].title, library[i].author, library[i].value);
		}
		//���µ�ͼ���¼��ӵ��ļ�

		if (fwrite(&library[filecount], size, count - filecount, fp) != count - filecount)
		{
			fputs("д���ļ���Ϣʧ�ܣ�", stderr);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		puts("û��ô���Ǿͺã�");
	}

	system("pause");
	return 0;
}
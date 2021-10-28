#include <stdio.h>
#include <stdlib.h>

#define FILENAME "book.dat"
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10							//ͼ�����౾��

struct book									//����ṹģ�壬���Ϊbook
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];					//�ṹ����
	int count = 0;
	int filecount;									//�ļ���ͼ����Ŀ
	FILE * pbooks;
	size_t size = sizeof(struct book);

	system("color 0A");

	//��ö����Ƹ�����
	if (fopen_s(&pbooks, FILENAME, "a+b") != 0)		//�״δ������ɸ��£��ı�β׷�ӣ�������ģʽ
	{
		fprintf(stderr, "Can't open file %s\n", FILENAME);
		exit(EXIT_FAILURE);
	}
	rewind(pbooks);									//��λ���ļ���
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
		{
			fprintf(stdout, "Current contents of %s:\n", FILENAME);
		}
		printf("%s by %s: $%.2f\n", library[count].title,
			library[count].author, library[count].value);
		count++;
	}
	filecount = count;								
	if (count == MAXBKS)
	{
		fputs("The %s file is full.\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("Please add new book titles.");
	puts("Press [enter] key at the start of a line to stop:");
	while (count < MAXBKS
		&& gets_s(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		gets_s(library[count].author, MAXTITL);
		puts("Now enter the value:");
		scanf_s("%f", &library[count].value);		//��©���з�
		while (getchar() != '\n')
		{
			;			//���������
		}
		count++;
		printf("Enter the next title:\n");
	}
	if (count > 0)
	{
		puts("Here is the list of your books:");
		for (int i = 0; i < count; i++)
		{
			printf("%s by %s: $%g\n", library[i].title,
				library[i].author, library[i].value);
		}
		fwrite(&library[filecount], size, count - filecount, pbooks);

	}
	else
	{
		puts("No books? Too bad.");
	}
	printf("Bye!\n");
	fclose(pbooks);

	system("pause");
	return 0;
}
/*
	��д�����ܴ򿪡�����һ���ı��ļ���ͳ���ļ���ÿ�����ʳ��ֵĴ�����
	�øĽ��Ķ����������洢���ʼ�����ֵĴ�������������ļ��󣬻��ṩ
	һ��������ѡ��Ĳ˵���
	��һ��ѡ��Ϊ�г����еĵ�����ͬ����ֵĴ�����
	�ڶ���ѡ��Ϊ��������һ�����ʣ����򱨸�õ������ļ��г��ֵĴ�����
	������ѡ��Ϊ�˳���*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void show(Item item);
void find(Tree * pt);

int main(void)
{
	Tree wTree;
	FILE * fp;
	Item input;
	char choice;
	
	system("color 0A");

	InitializeTree(&wTree);
	//���ļ�
	if (fopen_s(&fp, "test.txt", "r"))
	{
		fprintf(stderr, "Failed open file.");
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_SET);		//��λ���ļ���
	while (fscanf_s(fp, "%s", input.word, MAXWORDLENGTH) == 1)
	{
		AddItem(&input, &wTree);
	}
	fclose(fp);

	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
		case 's':
			Traverse(&wTree, show);
			break;
		case 'f':
			find(&wTree);
			break;
		default:
			fprintf(stderr, "Error in switching.\n");
			break;
		}
	}
	puts("Bye!");
	EmptyAll(&wTree);

	system("pause");
	return 0;
}


char menu(void)
{
	char ch;

	puts("Please select a option:");
	puts("s) show the list of words       f) find a word");
	puts("q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
		{
			;
		}
		if (strchr("sfq", ch) == NULL)
		{
			printf("Please enter s, f, or q\n");
		}
		else
		{
			break;
		}
	}
	if (ch == EOF)
	{
		ch = 'q';
	}
	return ch;
}

void show(Item item)
{
	printf("%*s has %d\n", MAXWORDLENGTH, item.word, item.count);
}

void find(Tree * pt)
{
	int count;
	Item temp = {"", 0};

	puts("Please enter the word you want to find:");
	if (scanf_s("%s", temp.word, MAXWORDLENGTH) == 1)
	{
		count = GetItems(&temp, pt);
		printf("%s has %d\n", temp.word, count);
	}
	else
	{
		printf("Error in entering.\n");
	}
}

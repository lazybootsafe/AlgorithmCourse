/*7.��дһ�����򣬴򿪺Ͷ�ȡһ���ı��ļ�����ͳ���ļ���ÿ�����ʳ�
�ֵĴ������øĽ��Ķ�����������浥�ʼ�����ֵĴ����������ڶ����ļ�
�󣬻��ṩһ����3��ѡ��Ĳ˵�����1��ѡ�����г����еĵ��ʺͳ��ֵĴ�
������2��ѡ�������û�����һ�����ʣ����򱨸�õ������ļ��г��ֵĴ�
������3��ѡ�����˳���*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "17.7.h"
#include "17.7word.c"

#define LEN 10000
#define SIZE 10000

char get_choice(void);
char * s_gets(char * st, int n);
void count_word(Tree * pt, Item * item);
void print_word(Item temp);

int main(void)
{
	Tree words;
	Item temp;
	FILE * fp;
	char ch;
	char name[LEN];
	char word[SIZE];

	//���ļ�
	printf("�������ļ���:\n");
	s_gets(name, LEN);
	if ((fp = fopen(name, "r")) == NULL)
	{//�뽫�ļ���.cԴ���һ��
		fprintf(stderr, "���ܴ�%s�ļ�.\n", name);
		exit(1);
	}

	//���ļ���ȡ����
	InitializeTree(&words);
	while (fscanf(fp, "%s", word) == 1)
	{
		strcpy(temp.word, word);
		temp.num = 1;
		AddItem(&words, &temp);
		if (TreeIsFull(&words))
		{
			fprintf(stderr, "����������.\n");
			break;
		}
	}
	fclose(fp);

	while ((ch = get_choice()) != 'q')
	{
		if (ch == 'a')
		{
			if (TreeIsEmpty(&words))
				printf("�ļ���û�е���.\n");
			else
				Traverse(&words, print_word);
		}
		else
			count_word(&words, &temp);
	}

	DeleteAll(&words);
	printf("�ټ�.\n");

	return 0;
}

char get_choice(void)
{
	char ch;

	printf("\na. ��ʾ�����б�\n");
	printf("b. ��Ѱһ������\n");
	printf("q. �뿪\n");

	ch = getchar();
	while (strchr("abq", tolower(ch)) == NULL)
	{
		while (getchar() != '\n')
			continue;
		printf("������a , b �� q .\n");
		ch = getchar();
	}
	while (getchar() != '\n')
		continue;

	return ch;
}

void print_word(Item temp)
{
	printf("����: %s\t\t\t��: %-5d��\n", temp.word, temp.num);
}

void count_word(Tree * pt, Item * item)
{
	int count;

	printf("�������������ĵ���:\n");
	s_gets(item->word, SIZE);
	item->num = 1;
	count = ItemCount(pt, item);
	if (!count)
		printf("�Ҳ����������.\n");
	else
		printf("��: %d��\n", ItemCount(pt, item));
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
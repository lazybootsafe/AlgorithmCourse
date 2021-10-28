/*8.�޸ĳ�����ֲ����򣬰�����ͬ���ĳ��ﶼ������ͬһ���ڵ��С���
�û�ѡ����ҳ���ʱ������Ӧѯ���û��ó�������֣�Ȼ���г������ֵ���
�г���������ࣩ��*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "17.8.h"
#include "17.8pet.c"

char get_choice(void);
char * s_gets(char * st, int n);
void addpet(Tree * pt);
void printpet(Item temp);
void findpet(const Tree * pt);
void droppet(Tree * pt);
void showpet(const Tree * pt);

int main(void)
{
	Tree pet;
	char ch;

	InitializeTree(&pet);
	while ((ch = get_choice()) != 'q')
	{
		switch (ch)
		{
		case 'a': addpet(&pet);
			break;
		case 'l': showpet(&pet);
			break;
		case 'f': findpet(&pet);
			break;
		case 'n': printf("%d �������ھ��ֲ���.\n",
			TreeItemCount(&pet));
			break;
		case 'd': droppet(&pet);
			break;
		default: puts("�л�����");
		}
		printf("\n");
	}

	DeleteAll(&pet);
	printf("�ټ�.\n");

	return 0;
}

char get_choice(void)
{
	char ch;

	puts("������ֲ���ӭ��");
	puts("����������ѡ�����Ӧ����ĸ:");
	puts("a) ���һ������\t\t\t  l) ��ʾ�����б�");
	puts("n) ��������    \t\t\t  f) Ѱ�ҳ���");
	puts("d) ɾ��һ������ \t\t  q) �뿪");

	ch = getchar();
	while (strchr("alnfdq", tolower(ch)) == NULL)
	{
		while (getchar() != '\n')
			continue;
		printf("������ a, l, n, f, d ���� q.\n");
		ch = getchar();
	}
	while (getchar() != '\n')
		continue;

	return ch;
}

void showpet(const Tree * pt)
{
	if (TreeIsEmpty(pt))
		printf("���ֲ���û�г���.\n");
	else
		Traverse(pt, printpet);
}

void findpet(const Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
		puts("���ֲ���û�г���.\n");
	else
	{
		printf("�����������:\n");
		s_gets(temp.name, LEN);
		FindItem(pt, &temp);
	}
}

void addpet(Tree * pt)
{
	Item temp;

	if (TreeIsFull(pt))
		puts("���ֲ�û������.\n");
	else
	{
		printf("�����������:\n");
		s_gets(temp.name, LEN);
		printf("�����������:\n");
		s_gets(temp.kind[0], LEN);
		temp.num = 1;
		AddItem(pt, &temp);
	}
}

void droppet(Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("û����Ŀ.\n");
		return;
	}

	printf("�����������:\n");
	s_gets(temp.name, LEN);
	if (DelItem(pt, &temp) == 0)
	{
		printf("�Ҳ�����ĳ���.\n");
	}
}

void printpet(Item temp)
{
	int i;

	printf("����: %s\t\t����: ", temp.name);
	for (i = 0; i < temp.num; i++)
		printf("%s ", temp.kind[i]);
	printf("\n");
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
//petclub.c -- ���ļ���ʹ�ö�����������Ӧ�ó���

/*
	�����������ó�����ά��Nerfville������ֲ��Ļ����ᡣÿһ����Ŀ�ɳ�������ֺ�������ɡ�
	�����ܣ��ó���ʹ�ò˵���ѡ������ֲ���Ա��������ӳ����ʾ��Ա�б������Ա��������Ա���˳���*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include "tree.h"


//����ԭ��
char menu(void);
void addpet(Tree * ptree);
void showpets(const Tree * ptree);
void findpet(const Tree * ptree);
void droppet(Tree * ptree);
void printitem(Item item);
void uppercase(char * str);


int main(void)
{
	Tree pets;
	char choice;

	system("color 0A");
	InitializeTree(&pets);					//��ʼ��
	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
		case 'a':
			addpet(&pets);
			break;
		case 'l':
			showpets(&pets);
			break;
		case 'f':
			findpet(&pets);
			break;
		case 'n':
			printf("%d pets in club.\n", TreeItemCount(&pets));
			break;
		case 'd':
			droppet(&pets);
			break;
		default:
			puts("Switching error.");
			break;
		}
	}
	EmptyAll(&pets);
	puts("Bye!");

	system("pause");
	return 0;
}


char menu(void)
{
	char ch;

	puts("-----NerFville Pet Club Membership Program-----");
	puts("Enter the letter corresponding to your choice: ");
	puts("a) add a pet            l) show list of pets");
	puts("n) number of pets       f) find pets");
	puts("d) delete a pet         q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
		{
			continue;
		}
		ch = tolower(ch);
		if (strchr("alnfdq", ch) == NULL)
		{
			puts("Please enter an a, l, f, n, d, or q:");
		}
		else
		{
			break;
		}
	}
	if (ch == EOF)
	{
		ch = 'q';				//��EOF���³����˳�
	}
	return ch;
}


void addpet(Tree * ptree)
{
	Item temp;

	if (TreeIsFull(ptree))
	{
		puts("No room in the club!");
	}
	else
	{
		puts("Please enter name of pet:");
		gets_s(temp.petname, 20);
		puts("Please enter pet kind:");
		gets_s(temp.petkind[0], 20);
		uppercase(temp.petname);
		uppercase(temp.petkind[0]);
		AddItem(&temp, ptree);
	}
}


void showpets(const Tree *ptree)
{
	if (TreeIsEmpty(ptree))
	{
		puts("No entries!");
	}
	else
	{
		Traverse(ptree, printitem);
	}
}


void findpet(const Tree * ptree)
{
	Item temp;

	if (TreeIsEmpty(ptree))
	{
		puts("No entries!");
		return;
	}
	
	puts("Please enter name of you wish to find:");
	gets_s(temp.petname, 20);
	uppercase(temp.petname);
	
	if (InTree(&temp, ptree))
	{
		printf("Pet: %s Kind: ", temp.petname);
		for (int i = 0; i < MAXKINDS; i++)
		{
			printf("%s ", temp.petkind[i]);
		}
		putchar('\n');
	}
	else
	{
		printf("%s the %s is not a member.\n", temp.petname, temp.petkind[0]);
	}
}


void droppet(Tree * ptree)
{
	Item temp;

	if (TreeIsEmpty(ptree))
	{
		puts("No entries.");
		return;
	}

	puts("Please enter name of pet you wish to delete:");
	gets_s(temp.petname, 20);
	puts("Please enter pet kind:");
	gets_s(temp.petkind[0], 20);
	uppercase(temp.petname);
	uppercase(temp.petkind[0]);
	printf("%s the %s ", temp.petname, temp.petkind[0]);
	if (DeleteItem(&temp, ptree))
	{
		printf("is dropped from the club.\n");
	}
	else
	{
		printf("is not a member.\n");
	}
}


void printitem(Item item)
{
	printf("Pet: %-19s Kind: ", item.petname);
	for (int i = 0; i < MAXKINDS; i++)
	{
		printf("%s ", item.petkind[i]);
	}
	putchar('\n');
}


void uppercase(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

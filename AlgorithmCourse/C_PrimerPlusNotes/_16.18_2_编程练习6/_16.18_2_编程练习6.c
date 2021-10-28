/*
	�޸ĳ����嵥16.15��ʹ��ʹ����struct names��ɵ����飬������ʹ��double���顣ʹ�ý���Ԫ�ز���ʾ��ʼ������Ϊ�ɺ���������ɵ����顣*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10
#define NAMESIZE 41

struct names
{
	char first[NAMESIZE];
	char last[NAMESIZE];
};

typedef struct names NAME;

void showarray(NAME [], int);
int comp(const void *, const void *);

int main(void)
{
	NAME  stuff[MAXSIZE] = {
		{ "KOBE", "BRYAN" },
		{ "Tracy", "McGrady" },
		{ "Cristiano", "Ronaldo" },
		{ "Barack", "Obama" },
		{ "Justin", "Eric" },
		{ "Andre", "Drummond" },
		{ "DeMarcus", "Cousins" },
		{ "Monty", "Williams" },
		{ "Nate", "McMillan" },
		{ "Kevin", "Durant" }
	};

	system("color 5A");
	puts("Original list:");
	showarray(stuff, MAXSIZE);
	qsort(stuff, MAXSIZE, sizeof(NAME), comp);
	puts("\nSorted list:");
	showarray(stuff, MAXSIZE);
	system("pause");
	return 0;
}

void showarray(NAME ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("               %s %s\n", ar[i].first, ar[i].last);
	}
}

//����ASICII˳����������
int comp(const void * p1, const void * p2)
{
	const NAME * a1 = (const NAME *)p1;
	const NAME * a2 = (const NAME *)p2;
	int res;

	res = strcmp(a1->last, a2->last);			/*�Ƚ���*/
	if (res)
	{
		return res;
	}
	else
	{
		return strcmp(a1->first, a2->first);	/*����ͬʱ���Ƚ���*/
	}
}
/*
	��дһ��transform()������������4������������double���͵�Դ��������double���͵�Ŀ����������
	��ʾ����Ԫ�ظ�����int�����Լ�һ�������������ߣ��ȼ۵�ָ������ָ�룩��transform()������
	ָ���ĺ���������Դ�����ÿ��Ԫ�أ���������ֵ�ŵ�Ŀ�������С����磺
	transform(source, target, 100, sin)
	����������ð�sin(source[0])����target[0]���ȵȣ�����100��Ԫ�ء���һ�������в��Ըú�����
	����4��transform()���ֱ�ʹ��math.h�������е����������Լ��Լ���Ƶ��������ʵĺ�����Ϊ������*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define FUNSIZE 4
#define DBLESIZE 5

typedef double(*pfun)(double);

void showmenu(double src[], int n);
char get_choice(void);
void eatline(void);

double Square(double);
double Opposite(double);
void transform(double src[], double dest[], int n, pfun _pfun);
void cpyarr(double src[], double dest[], int n);

int main(void)
{
	pfun pfuns[FUNSIZE] = { sin, cos, Square, Opposite };
	double src[DBLESIZE] = { 1.0, 1.5, 2.0, 2.5, 3.0 };
	double dest[DBLESIZE];
	double copy[DBLESIZE];
	char choice;

	system("color 0A");

	showmenu(src, DBLESIZE);
	choice = get_choice();
	while (choice != 'e')
	{
		cpyarr(src, copy, DBLESIZE);
		switch (choice)
		{
		case 'a':
			transform(copy, dest, DBLESIZE, pfuns[0]);
			break;
		case 'b':
			transform(copy, dest, DBLESIZE, pfuns[1]);
			break;
		case 'c':
			transform(copy, dest, DBLESIZE, pfuns[2]);
			break;
		case 'd':
			transform(copy, dest, DBLESIZE, pfuns[3]);
			break;
		}
		showmenu(src, DBLESIZE);
		choice = get_choice();
	}
	puts("Bye!");

	system("pause");
	return 0;
}

void showmenu(double src[], int n)
{
	puts("To change below array, enter a funtion's letter label:");
	puts("a) sin");
	puts("b) cos");
	puts("c) Square");
	puts("d) Opposite");
	puts("e) quit");
	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", src[i]);
	}
	putchar('\n');
}

char get_choice(void)
{
	char ch;

	ch = getchar();
	ch = tolower(ch);
	eatline();
	while (strchr("abcde", ch) == NULL)
	{
		puts("Please enter a, b, c, d or e:");
		ch = tolower(getchar());
		eatline();
	}

	return ch;
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		continue;
	}
}

void transform(double src[], double dest[], int n, pfun _pfun)
{
	for (int i = 0; i < n; i++)
	{
		dest[i] = (*_pfun)(src[i]);		//�﷨1
		//dest[i] = *_pfun(src[i]);		  �﷨2
	}

	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", dest[i]);
	}
	putchar('\n');
}

double Square(double _double)
{
	return (_double * _double);
}

double Opposite(double _double)
{
	return (_double * (-1.0));
}

void cpyarr(double src[], double dest[], int n)
{
	for (int i = 0; i < DBLESIZE; i++)
	{
		dest[i] = src[i];
	}
}
/*
	���˺��չ�˾�Ļ�Ⱥ����λ����Ϊ12�ķɻ���ɡ���ÿ�����һ�����ࡣ��������Ĺ��ܣ�дһ����λԤ������

	a.����ʹ��һ����12���ṹ�����顣ÿ���ṹ��Ҫ����һ�����ڱ�ʶ��λ�ı�š�һ����ʾ��λ�Ƿ��ѷ����ȥ
	  �ı�ǡ���λԤ���˵��պ���λԤ���˵�����

	b.������ʾ����Ĳ˵���
	  To choose a function, enter its letter label:
	  a) Show number of empty seats
	  b) Show list of empty seats
	  c) Show alphabetical list of seats
	  d) Assign a customer to a seat assignment
	  e) Delete a seat assignment
	  f) Quit

	c.����Ӧ��ִ�в˵��������Ĺ��ܡ�ѡ��d)��e)��Ҫ��������룬ÿһ��ѡ�Ӧ�������û���ֹ���롣

	d.ִ����һ���ض��Ĺ��ܺ󣬳����ٴ���ʾ�˵�������ѡ����f)��

	e.ÿ�����ж������ݱ��浽һ���ʼ��С��������ٴ�����ʱ�����ȴ��ļ����������ݣ�����еĻ�����

	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NAMESIZE 21
#define SEATSIZE 12
#define FILENAME "flight.dat"

struct name
{
	char fname[NAMESIZE];
	char lname[NAMESIZE];
};

typedef struct name NAME;

struct seat
{
	int number;
	bool assign;
	NAME passenger;
};

typedef struct seat SEAT;

bool get_info(SEAT seats[], int n);
void initial_num(SEAT seats[], int n);
void show_info(const SEAT seats[], int n);
void show_topmenu(void);
char get_topchoice(void);
void eatline(void);
void empty_number(const SEAT seats[], int n);						//������������
void empty_list(const SEAT seats[], int n);							//���������б�
void alpha_list(SEAT seats[], int n);								//���˿�����ĸ˳�����б�
void sort_alpha(SEAT seats[], int n);								//����
void assign(SEAT seats[], int  n);
void Delete(SEAT seats[], int  n);
void save(const SEAT seats[], int n);
int empty_seat(const SEAT seats[], int n);							//��ȡ��λ�б��е�һ������λ���±�

int main(void)
{
	SEAT seats[SEATSIZE] = { 0 };
	char choice;
	bool IsRecExist;

	system("color 5A");

	//��ȡ����
	IsRecExist = get_info(seats, SEATSIZE);
	if (IsRecExist)
	{
		show_info(seats, SEATSIZE);
	}
	else
	{
		initial_num(seats, SEATSIZE);
	}

	show_topmenu();
	while ((choice = get_topchoice()) != 'f')
	{
		switch (choice)
		{
		case 'a':
			empty_number(seats, SEATSIZE);
			break;
		case 'b':
			empty_list(seats, SEATSIZE);
			break;
		case 'c':
			alpha_list(seats, SEATSIZE);
			break;
		case 'd':
			assign(seats, SEATSIZE);
			break;
		case 'e':
			Delete(seats, SEATSIZE);
			break;
		}
		show_topmenu();
	}

	//��������
	save(seats, SEATSIZE);
	puts("Bye!");

	system("pause");
	return 0;
}

bool get_info(SEAT seats[], int n)
{
	FILE * fp;
	int count = 0;
	bool IsRecExist = false;
	size_t size = sizeof(SEAT);

	if (fopen_s(&fp, FILENAME, "a+b") != 0)
	{
		puts("Can't open file.");
		exit(EXIT_FAILURE);
	}
	rewind(fp);

	while (count < n && fread(&seats[count], size, 1, fp) == 1)
	{
		IsRecExist = true;
		count++;
	}
	fclose(fp);

	return IsRecExist;
}

void initial_num(SEAT seats[], int n)
{
	for (int i = 0; i < n; i++)
	{
		seats[i].number = i + 101;
	}
}

void show_info(const SEAT seats[], int n)
{
	if (n)
	{
		puts("Here is the list of all seats now:");
		printf("%6s %6s %11s\n", "number", "assign", "passenger");
		for (int i = 0; i < n; i++)
		{
			printf("%4d %6d %10s %-10s\n", seats[i].number, seats[i].assign,
				seats[i].passenger.fname, seats[i].passenger.lname);
		}
	}
	else
	{
		puts("Have no record.");
	}
}

void show_topmenu(void)
{
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignment");
	puts("f) Quit");
}

char get_topchoice(void)
{
	char ch;

	ch = getchar();
	ch = tolower(ch);
	eatline();
	while (strchr("abcdef", ch) == NULL)
	{
		puts("Please enter a, b, c, d, e, or f:");
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

void empty_number(const SEAT seats[], int n)
{
	int total = 0;

	for (int i = 0; i < n; i++)
	{
		if (seats[i].assign == false)
		{
			total++;
		}
	}

	if (total)
	{
		printf("The number of empty seats is %d\n", total);
	}
	else
	{
		puts("0");
	}
}

void empty_list(const SEAT seats[], int n)
{
	int total = 0;

	for (int i = 0; i < n; i++)
	{
		if (seats[i].assign == false)
		{
			printf("%6d %6d %20s %-20s\n", seats[i].number, seats[i].assign,
				seats[i].passenger.fname, seats[i].passenger.lname);
			total++;
		}
	}

	if (total = 0)
	{
		puts("Has no empty seat.");
	}
}

void alpha_list(SEAT seats[], int n)
{
	sort_alpha(seats, n);
	show_info(seats, n);
}

void sort_alpha(SEAT seats[], int n)
{
	SEAT temp;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(seats[j].passenger.fname, seats[j + 1].passenger.fname) > 0)
			{
				temp = seats[j];
				seats[j] = seats[j + 1];
				seats[j + 1] = temp;
			}
		}
	}
}

void assign(SEAT seats[], int  n)
{
	int index;

	index = empty_seat(seats, n);
	if (index != -1)
	{
		printf("Fund it, the number is %d\n", seats[index].number);
		puts("Please enter the first name of the passage:");
		gets_s(seats[index].passenger.fname, NAMESIZE);
		puts("Last name:");
		gets_s(seats[index].passenger.lname, NAMESIZE);
		seats[index].assign = true;
		puts("Assign success.");
	}
	else
	{
		puts("Sorry, all seats has been assigned.");
	}
}

int empty_seat(const SEAT seats[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (seats[i].assign == false)
		{
			return i;
		}
	}

	return -1;
}

void Delete(SEAT seats[], int  n)
{
	int number;
	NAME zero = { "", "" };

	puts("Please input the seat-number to delete assignment:");
	if (scanf_s("%d", &number, 10) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (seats[i].number == number)
			{
				seats[i].assign = false;
				seats[i].passenger = zero;
				puts("Delete success.");
			}
		}
	}

	eatline();
}

void save(const SEAT seats[], int n)
{
	FILE * fp;
	int count = 0;
	size_t size = sizeof(SEAT);

	if (fopen_s(&fp, FILENAME, "wb") != 0)
	{
		puts("Can't open file.");
		exit(EXIT_FAILURE);
	}
	rewind(fp);

	fwrite(&seats[0], size, n, fp);
	fclose(fp);
}
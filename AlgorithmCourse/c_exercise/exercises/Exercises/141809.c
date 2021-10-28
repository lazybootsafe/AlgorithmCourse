#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct seat
{
	int id;
	int booked;
	char fname[20];
	char lname[20];
};
struct seat list[4][12];

void get_menu(void);
void get_empty(struct seat list[]);
void show_empty(struct seat list[]);
void show_booked(struct seat list[]);
void book_seat(struct seat list[]);
void cancel_book(struct seat list[]);

int main(void)
{
	char selected;
	int air_no;
	printf("Please select airplane No1(102,311,444,519): ");
	scanf_s("%d", &air_no);
	while (air_no == 102 || air_no == 311 || air_no == 444 || air_no == 519)
	{
		if (air_no == 102)
		{
			printf("Now you select Air %d:\n", air_no);
			air_no = 0;
		}
		if (air_no == 311)
		{
			printf("Now you select Air %d:\n", air_no);
			air_no = 1;
		}
		if (air_no == 444)
		{
			printf("Now you select Air %d:\n", air_no);
			air_no = 2;
		}
		if (air_no == 519)
		{
			printf("Now you select Air %d:\n", air_no);
			air_no = 3;
		}
		while (getchar() != '\n')
			continue;
		get_menu();
		while ((selected = getchar()) != 'f')
		{
			switch (selected)
			{
			case 'a':
				get_empty(list[air_no]);
				break;
			case 'b':
				show_empty(list[air_no]);
				break;
			case 'c':
				show_booked(list[air_no]);
				break;
			case 'd':
				book_seat(list[air_no]);
				break;
			case 'e':
				cancel_book(list[air_no]);
				break;
			default:
				break;
			}
			//get_menu();
		}
		while (getchar() != '\n')
			continue;
		printf("Please select airplane No1((102,311,444,519)):");
		scanf_s("%d", &air_no);
	}
	puts("All done.");
	return 0;
}

void get_menu(void)
{
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignement");
	puts("f) Quit");
}

void get_empty(struct seat list[])
{
	int sum = 0;
	for (int i = 0; i < 12; ++i)
		if (list[i].booked == 0)
			sum++;
	printf("There are %d seats empty\n", sum);
}

void show_empty(struct seat list[])
{
	printf("Empty list: ");
	for (int i = 0; i < 12; ++i)
		if (list[i].booked == 0)
			printf("%d ", (i + 1));
	putchar('\n');
}

void show_booked(struct seat list[])
{
	struct seat *ptstr[12];
	for (int i = 0; i < 12; i++)
		ptstr[i] = &list[i];
	int top, seek;
	struct seat *temp;
	for (top = 0; top < 12 - 1; top++)
	{
		for (seek = top + 1; seek < 12; seek++)
		{
			if (strcmp(ptstr[top]->fname, ptstr[seek]->fname) > 0)
			{
				temp = ptstr[top];
				ptstr[top] = ptstr[seek];
				ptstr[seek] = temp;
			}
		}
	}
	puts("Alphabetcal list:");
	for (int i = 0; i < 12; i++)
		if (ptstr[i]->booked == 1)
			printf("Seat No:%d book by %s.%s\n", (i + 1),
				ptstr[i]->fname, ptstr[i]->lname);
}

void book_seat(struct seat list[])
{
	int id;
	char fname[20], lname[20];
	show_empty(list);
	puts("Please select the seat:");
	scanf_s("%d", &id);
	if (list[id - 1].booked == 1)
	{
		puts("Error selected.");
		return;
	}
	list[id - 1].id = id;
	puts("Please input you FIRST_NAME LAST_NAME.");
	scanf_s("%s %s", fname, 20, lname, 20);
	strcpy_s(list[id].fname, sizeof list[id].fname, fname);
	strcpy_s(list[id].lname, sizeof list[id].lname, lname);
	list[id - 1].booked = 1;
	puts("Booked!");
}

void cancel_book(struct seat list[])
{
	show_booked(list);
	int id;
	puts("Please select the seat to cancel:");
	scanf_s("%d", &id);
	if (list[id - 1].booked == 0)
	{
		puts("Error selected.");
		return;
	}
	list[id - 1].booked = 0;
}

#endif // 1
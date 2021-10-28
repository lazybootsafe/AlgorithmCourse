#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define  MAXBKS 100

typedef struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
}BOOK;

char * s_gets(char * st, int n);
void sortt(BOOK * pb[], int n);
void sortv(BOOK * pb[], int n);

int main(void)
{
	BOOK library[MAXBKS];
	BOOK *pbk[MAXBKS];
	int count = 0;
	int index;

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS&&s_gets(library[count].title, MAXTITL) != NULL &&
		library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf_s("%f", &library[count].value);
		pbk[count] = &library[count];
		count++;
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}
	printf("Here is  the list of your books:\n");
	for (index = 0; index < count; index++)
		printf("%s by %s: $%.2lf\n", library[index].title,
			library[index].author, library[index].value);
	printf("Here is the list of your books sorted by title:\n");
	sortt(pbk, count);
	for (index = 0; index < count; index++)
		printf("%s by %s: $%.2lf\n", pbk[index]->title,
			pbk[index]->author, pbk[index]->value);
	sortv(pbk, count);
	printf("Here is the list of your books sorted by value:\n");
	for (index = 0; index < count; index++)
		printf("%s by %s: $%.2lf\n", pbk[index]->title,
			pbk[index]->author, pbk[index]->value);

	return 0;
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

void sortt(BOOK * pb[], int n)
{
	int top, search;
	BOOK *temp;
	for (top = 0; top < n - 1; top++)
	{
		for (search = top + 1; search < n; search++)
		{
			if (strcmp(pb[search]->title, pb[top]->title) < 0)
			{
				temp = pb[search];
				pb[search] = pb[top];
				pb[top] = temp;
			}
		}
	}
}

void sortv(BOOK * pb[], int n)
{
	int top, search;
	BOOK * temp;
	for (top = 0; top < n - 1; top++)
	{
		for (search = top + 1; search < n; search++)
		{
			if (pb[search]->value < pb[top]->value)
			{
				temp = pb[search];
				pb[search] = pb[top];
				pb[top] = temp;
			}
		}
	}
}

#endif // 1

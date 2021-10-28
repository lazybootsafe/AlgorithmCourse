#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct month
{
	char name[10];
	char abbrev[4];
	int days;
	int month_number;
}MONTH;

const MONTH months[12] = {
	{  "January", "Jan", 31,  1},
	{ "February", "Feb", 28,  2},
	{    "March", "Mar", 31,  3},
	{    "April", "Apr", 30,  4},
	{      "May", "may", 31,  5},
	{     "June", "Jun", 30,  6},
	{     "July", "Jul", 31,  7},
	{   "August", "Aug", 31,  8},
	{"September", "Sep", 30,  9},
	{  "October", "Oct", 31, 10},
	{ "November", "Nov", 30, 11},
	{ "December", "Dec", 31, 12}
};

int days(char* m, int day);

int main(void)
{
	int year, day;
	char month[10];
	int result;
	printf("Enter the Year Month Day: ");
	scanf_s("%d %s %d", &year, month, 10, &day);
	while (year > 1000)
	{
		result = days(month, day);
		if (result < 0)
			printf("Error input, retry.\n");
		else
			printf("The %d/%s/%d is %d day.\n", year, month, day, result);
		printf("Enter the Year Month Day: ");
		scanf_s("%d %s %d", &year, month, 10, &day);
	}
	puts("Done.");
	return 0;
}

int days(char* m, int day)
{
	if (day < 1 || day>31)
		return -1;
	int total = 0;
	int temp = atoi(m);
	for (int i = 0; i < 12; i++)
	{
		if((temp==months[i].month_number)||
			(strcmp(m, months[i].abbrev)) == 0 ||
			(strcmp(m, months[i].name) == 0))
		{
			if (day > months[i].days)
				return -1;
			return total + day;
		}
	}
	return -1;
}

#endif
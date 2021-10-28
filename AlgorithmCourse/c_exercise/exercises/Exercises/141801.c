#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct month
{
	char name[10];
	char abbrev[4];
	int days;
	int month_number;
};
const struct month months[12] = {
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

int days(char* month);

int main(void)
{
	char name[10];
	int daytatol = 0;

	printf("Enter the name of a month: ");
	while (scanf_s("%s", name, 10) == 1 && name[0] != '\0'&&name[0] != 'q')
	{
		daytatol = days(name);
		if (daytatol > 0)
			printf("There are %d days through %s.\n", daytatol, name);
		else
			printf("%s is not valid input.\n", name);
		printf("Next month (q to quit): ");
	}
	puts("Done.");

	//char name[10];
	//printf("Enter the name of a month: ");
	//scanf_s("%s", name, 10);
	//while (strlen(name) > 2)
	//{
	//	printf("The total to %s, is %d\n", name, days(name));
	//	printf("Enter the name of a month: ");
	//	scanf_s("%s", name, 10);
	//}

	return 0;
}

int days(char * month)
{
	int total = 0;
	int mon_num = 0;
	//使用户不必区分大小输入
	month[0] = toupper(month[0]);
	for (int i = 1; month[i] != '\0'; i++)
		month[i] = tolower(month[i]);
	for (int i = 0; i < 12; i++)
	{
		if (strcmp(month, months[i].name) == 0)
		{
			mon_num = months[i].month_number;
			break;
		}
	}
	if (mon_num == 0)
		total = -1;
	else
		for (int i = 0; i < mon_num; i++)
			total += months[i].days;
	//for (int i = 0; i < 12; i++)
	//{
	//	if (strcmp(month, months[i].name) == 0)
	//		return total;
	//	else
	//		total += months[i].days;
	//}
	return total;
}

#endif
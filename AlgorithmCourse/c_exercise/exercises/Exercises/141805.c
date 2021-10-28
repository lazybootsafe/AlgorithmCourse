#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define    LEN 14
#define  CSIZE 4
#define SCORES 3

struct name
{
	char first[LEN];
	char last[LEN];
};
struct student
{
	struct name person;
	float scores[SCORES];
	float mean;
};

void get_scores(struct student ar[], int lim);
void find_means(struct student ar[], int lim);
void show_class(const struct student ar[], int lim);
void show_ave(const struct student ar[], int lim);

int main(void)
{
	struct student class[CSIZE] = {
		{ "Flip",  "Snide" },
		{"Clare", "Voyans" },
		{"Bingo",  "Higge" },
		{ "Fawn", "Hunter" }
	};

	get_scores(class, CSIZE);
	find_means(class, CSIZE);
	show_class(class, CSIZE);
	show_ave(class, CSIZE);

	return 0;
}

void get_scores(struct student ar[], int lim)
{
	for (int i = 0; i < lim; i++)
	{
		printf("Please enter %d scores for %s %s:\n", SCORES,
			ar[i].person.first, ar[i].person.last);
		for (int j = 0; j < SCORES; j++)
		{
			while (scanf_s("%f", &ar[i].scores[j]) != 1)
			{
				scanf_s("%*s");
				puts("Please use numeric input.");
			}
		}
	}
}

void find_means(struct student ar[], int lim)
{
	float sum = 0;
	for (int i = 0; i < lim; i++)
	{
		for (int j = 0; j < SCORES; j++)
			sum += ar[i].scores[j];
		ar[i].mean = sum / SCORES;
	}
}

void show_class(const struct student ar[], int lim)
{
	char wholename[2 * LEN];
	for (int i = 0; i < lim; i++)
	{
		strcpy_s(wholename,
			sizeof wholename,
			ar[i].person.first);
		//strcpy(wholename, ar[i].person.first);
		strcat_s(wholename, sizeof wholename, " ");
		//strcat(wholename, " "); 
		strcat_s(wholename,
			sizeof wholename,
			ar[i].person.last);
		//strcat(wholename, ar[i].person.last);
		printf("%27s: ", wholename);
		for (int j = 0; j < SCORES; j++)
			printf("%6.lf", ar[i].scores[j]);
		printf(" Average = %5.2f\n", ar[i].mean);
	}
}

void show_ave(const struct student ar[], int lim)
{
	float total = 0;
	printf("\n%27s: ", "QUIZ AVERAGES");
	for (int i = 0; i < SCORES; i++)
	{
		for (int j = 0; j < SCORES; j++)
			total += ar[j].scores[i];
		printf("%6.2f ", total / lim);
	}
	for (int i = 0; i < lim; i++)
	{
		total += ar[i].mean;
	}
	printf("     All = %5.2f\n", total / lim);
}

//typedef struct
//{
//	char fname[30];
//	char lname[30];
//}FULL_NAME;
//typedef struct
//{
//	FULL_NAME name;
//	float grade[3];
//	float average;
//}STUDENT;
//
//void set_grade(STUDENT list[]);
//void set_average(STUDENT list[]);
//void get_info_all(STUDENT list[]);
//void get_average_all(STUDENT list[]);
//
//int main(void)
//{
//	STUDENT stu_list[CSIZE];
//	set_grade(stu_list);
//	set_average(stu_list);
//	get_info_all(stu_list);
//	get_average_all(stu_list);
//
//	return 0;
//}
//
//void set_grade(STUDENT list[])
//{
//	char fname[15], lname[15];
//	int i = 0;
//	while (i < CSIZE)
//	{
//		printf("Enter the student name (FIRST_NAME LAST_NAME):");
//		scanf_s("%s %s", fname, 15, lname, 15);
//		if (strlen(fname) < 1 && strlen(lname) < 1)
//		{
//			puts("Error in student name! retry.");
//			printf("Enter the student name (FIRST_NAME LAST_NAME):");
//			scanf_s("%s %s", fname, 15, lname, 15);
//			break;
//		}
//		strcpy_s(list[i].name.fname, sizeof list[i].name.fname, fname);
//		strcpy_s(list[i].name.lname, sizeof list[i].name.lname, lname);
//		printf("Enter the 3 scores of %s: ", fname);
//		scanf_s("%f %f %f", &list[i].grade[0], &list[i].grade[1], &list[i].grade[2]);
//		i++;
//	}
//}
//
//void set_average(STUDENT list[])
//{
//	for (int i = 0; i < CSIZE; i++)
//		list[i].average = (list[i].grade[0] + list[i].grade[1] + list[i].grade[2]);
//}
//
//void get_info_all(STUDENT list[])
//{
//	for (int i = 0; i < CSIZE; i++)
//	{
//		printf("No.%d: %s.%s : %5.2f %5.2f %5.2f, average = %5.2f\n",
//			i + 1, list[i].name.fname,
//			list[i].name.lname,
//			list[i].grade[0],
//			list[i].grade[1],
//			list[i].grade[2],
//			list[i].average);
//	}
//}
//
//void get_average_all(STUDENT list[])
//{
//	float sum = 0;
//	for (int i = 0; i < CSIZE; ++i)
//		sum += list[i].average;
//	printf("Class average is %.2f\n", sum / 4);
//}

#endif // 1
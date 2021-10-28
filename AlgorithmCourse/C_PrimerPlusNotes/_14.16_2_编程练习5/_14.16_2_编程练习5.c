/*
	Ҫ��
	a.�ⲿ����һ��name�ṹģ�壬������2����Ա��һ���ַ������ڴ�����֣���һ���ַ����û�������ϡ�
	b.�ⲿ����һ��student�ṹģ�壬������3����Ա��һ��name�ṹ��һ�����3��������������grade���飬
	  �Լ�һ�������3��������ƽ���ֵı�����
	c.ʹmain()��������һ������CSIZE��CSIZE=4����student�ṹ�����飬�������ʼ����Щ�ṹ�����ֲ��֡�
	  ʹ�ú�����ִ��d��e��f��g������������
	d.�����û�����ѧ�������ͷ������Խ����ػ�ȡÿ��ѧ���ĳɼ����������ŵ���Ӧ�ṹ��grade�����Ա�С�
	  ����������ѡ����main()��һ��������ʵ�����ѭ����
	e.Ϊÿ���ṹ����ƽ���֣��������ֵ�����ʺϵĳ�Ա��
	f.���ÿ���ṹ����Ϣ��
	g.����ṹ��ÿ����ֵ��Ա�İ༶ƽ���֡�
	*/

#include <stdio.h>
#include <stdlib.h>

#define SIZENAME 21
#define SIZEGRAD 3
#define CSIZE 4

struct name
{
	char fname[SIZENAME];
	char lname[SIZENAME];
};

struct student
{
	struct name sname;
	float grade[SIZEGRAD];
	float average;
};

int getinfo(struct student students[], int n);
void eatline(void);
void makeinfo(struct student students[], int n);
void showinfo(const struct student students[], int n);

int main(void)
{
	struct student students[CSIZE] = {
		{ { "Bird", "Cing" } },
		{ { "Fish", "Down" } },
		{ { "Turtle", "Elfeo" } },
		{ { "Sea", "Flow" } },
	};
	int count;									//��¼��

	system("color 5A");

	count = getinfo(students, CSIZE);
	if (count > 0)
	{
		makeinfo(students, count);
		showinfo(students, count);
	}
	else
	{
		printf("No students? Good!");
	}

	system("pause");
	return 0;
}

int getinfo(struct student students[], int n)
{
	int count = 0;

	printf("Input  a name of the first student %s\n", students[count].sname.fname);
	printf("Press [enter] at the start of a line to quit:\n");

	while (count < n
		&& gets_s(students[count].sname.fname, SIZENAME) != NULL
		&& students[count].sname.fname[0] != '\0')
	{
		printf("Enter the Chinese-grade of %s:\n", students[count].sname.fname);
		if (scanf_s("%f", &students[count].grade[0]) != 1)
		{
			exit(EXIT_FAILURE);
		}
		printf("Math-grade:\n");
		if (scanf_s("%f", &students[count].grade[1]) != 1)
		{
			exit(EXIT_FAILURE);
		}
		printf("English-grade:\n");
		if (scanf_s("%f", &students[count].grade[2]) != 1)
		{
			exit(EXIT_FAILURE);
		}
		eatline();										//��������У����任�з���
		puts("Next name of student (empty line to quit):");
		count++;
	}

	return count;
}

void makeinfo(struct student students[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < SIZEGRAD; j++)
		{
			students[i].average += students[i].grade[j];
		}
		students[i].average /= SIZEGRAD;
	}
}

void showinfo(const struct student students[], int n)
{
	float totaverage = 0;

	printf("Here is the list grade:\n");
	printf("%10s%10s%10s%10s%10s\n", "Student", "Chinese", "Math", "English", "Average");
	for (int i = 0; i < n; i++)
	{
		printf("%10s%10.1f%10.1f%10.1f%10.1f\n", students[i].sname.fname,
			students[i].grade[0], students[i].grade[1], students[i].grade[2], students[i].average);
		totaverage += students[i].average;
	}
	printf("Class average: %.1f\n", totaverage / n);
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		;
	}
}
/*
	��дһ�����򣬰�Ҫ�󴴽��ṹģ�壺
	a.��һ����Ա����ᱣ�Ϻţ��ڶ�����Ա��һ����3����Ա�Ľṹ��
	  ���ĵ�һ����Ա�������ڶ�����Ա��������֮����֣����һ��
	  ��Ա���ա���������ʼ��һ������5������ṹ�����飬������
	  ������ʽ������ݣ�
	  Dribble, Flossie M. - 302039823
	  ������֮�����ֻ��������ĵ�һ����ĸ���������һ����㡣
	  ��������м������Ϊ�գ���ô���ĵ�һ����ĸ�;�㶼���������
	  дһ������ʵ��������ѽṹ���鴫�ݸ����������
	  */

#include <stdio.h>
#include <stdlib.h>

#define SIZENAME 20
#define SIZE 5

struct _name
{
	char fname[SIZENAME];			//��
	char mname[SIZENAME];			//��
	char lname[SIZENAME];			//��
};

struct person
{
	int indemnumb;					//��ᱣ�Ϻ�
	struct _name name;
};

void showinfo(struct person persons[], int n);

int main(void)
{
	struct person persons[SIZE] = {
		{ 302039823, { "Dribble", "Mond", "Flossie" } }, 
		{ 302134234, { "Mkdjie", "", "Ldsinw" } },
		{ 323424121, { "Lijei", "Lin", "Ijdsoiafsdj" } },
		{ 356745023, { "Jone", "", "Edsjfoisdj" } },
		{ 359900212, { "Long", "Adfs", "Ddjsoafisd" } }
	};

	system("color 5A");
	showinfo(persons, SIZE);
	getchar();
	return 0;

}

void showinfo(struct person persons[], int n)
{

	for (int i = 0; i < n; i++)
	{
		printf("%s, %s ", persons[i].name.fname, persons[i].name.lname);
		if (persons[i].name.mname[0] != '\0')
		{
			printf("%c. ", persons[i].name.mname[0]);
		}
		printf("- %d\n", persons[i].indemnumb);
	}
}
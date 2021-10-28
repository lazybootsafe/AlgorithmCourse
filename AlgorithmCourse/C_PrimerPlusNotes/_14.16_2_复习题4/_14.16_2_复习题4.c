
/*
	���һ���ṹģ�壬����һ���·�����һ��3����ĸ�ĸ��·ݵ���д�����·ݵ��������Լ��·ݺ�
	�����ṹ���飬��ʼ��һ����ݣ������꣩*/
#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 10
#define REDUCESIZE 4
#define MONTHSIZE 12

struct month
{
	char name[NAMESIZE];				//�·���
	char abbrev[REDUCESIZE];			//�·���д
	int days;							//����
	int monnumb;						//�·ݺ�
};

typedef struct month MONTH;

int main(void)
{
	MONTH year[MONTHSIZE] = {
		{ "January", "Jan", 31, 1 },
		{ "February", "Feb", 28, 2 },
		{ "March", "Mar", 31, 3 },
		{ "April", "Apr", 30, 4 },
		{ "May", "May", 31, 5 },
		{ "June", "Jun", 30, 6 },
		{ "July", "Jul", 31, 7 },
		{ "August", "Aug", 31, 8 },
		{ "September", "Sep", 30, 9 },
		{ "October", "Oct", 31, 10 },
		{ "November", "Nov", 30, 11 },
		{ "December", "Dec", 31, 12 } 
	};
	
	system("color 0A");
	for (int i = 0; i < MONTHSIZE; i++)
	{
		printf("%s has a total of %d days.\n", year[i].name, year[i].days);
		printf("%s is the %d month of a year.\n\n", year[i].abbrev, year[i].monnumb);
	}
	
	getchar();
	return 0;
}

/*
���һ���ṹģ�壬����һ���·�����һ��3����ĸ�ĸ��·ݵ���д�����·ݵ��������Լ��·ݺ�*/
#include <stdio.h>

#define NAMESIZE 10
#define REDUCESIZE 4
#define MONTHS 12

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
	MONTH year[MONTHS] = { [5] = { .name = "June", .abbrev = "Jun", .days = 30, .monnumb = 6 } };

	printf("%s has a total of %d days.\n", year[5].name, year[5].days);
	printf("%s is the %dth month of a year.\n", year[5].abbrev, year[5].monnumb);

	getchar();
	return 0;
}
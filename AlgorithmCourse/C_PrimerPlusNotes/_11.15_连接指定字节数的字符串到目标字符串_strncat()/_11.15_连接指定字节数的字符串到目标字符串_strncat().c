#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 31
#define BUGSIZE 13

int main(void)
{
	char flower[SIZE];
	char add_on[] = "s smell like old shoes.";
	char bug[BUGSIZE];
	int available;											

	system("color 1A");

	puts("What is your favourite flower?");
	gets_s(flower, SIZE);									//ɨ�������ַ���������������󳤶��Ƕ�����ַ���+1��C���������Խ�磬һ��Ԫ�س�������߽磬���������쳣

	if (strlen(flower) + strlen(add_on) + 1 <= SIZE)		//flower�ĳ���+addon�ĳ��Ȳ�����flower����󳤶�
	{
		strcat_s(flower, SIZE, add_on);						//��zddon�ַ���������flower���
	}
	puts(flower);											//��ӡ���ӳ���ģ�flower�ַ���

	puts("What is your favorite bug?");
	gets_s(bug, BUGSIZE);

	available = BUGSIZE - strlen(bug) - 1;					//bug�ַ����������ӵ�����ַ���
	strncat_s(bug, BUGSIZE, add_on, available);				//������available���ַ���bug, bug�������ΪBUGSIZE
	puts(bug);

	getchar();
	return 0;
}
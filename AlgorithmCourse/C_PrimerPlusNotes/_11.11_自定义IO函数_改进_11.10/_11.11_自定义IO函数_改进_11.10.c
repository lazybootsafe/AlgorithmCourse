#include <stdio.h>

#define MSG "CHANGE THE WORLD BY PROGRAMING!"

int put2(const char * string);

int main(void)
{
	int count;

	count = put2(MSG);

	printf("count = %d\n", count);

	getchar();
	return 0;
}

//��ӡһ���ִ�����ͳ�����е��ַ���

int put2(const char * string)
{
	int count = 0;

	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');		//���з���ͳ������

	return count;
}
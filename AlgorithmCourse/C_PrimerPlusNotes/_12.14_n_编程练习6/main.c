
//����1000��1-10�����������¼������10������ֵ���ֵĴ��������ش�ӡ�������
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define COUNT 1000

int main(void)
{
	int randnum;							//�����
	int rec[SIZE] = { 0 };					//��¼1-10ÿ����������ֵĴ����ļ�¼����

	system("color 5A");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < COUNT; i++)
	{
		randnum = rand() % SIZE + 1;
		rec[randnum - 1]++;					//���������Ӧ�ļ�¼+1
	}
	printf("Here are random-number and there count:\n");
	puts("    x   t");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%5d%5d\n", i + 1, rec[i]);
	}

	getchar();
	return 0;
}
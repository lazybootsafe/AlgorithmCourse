#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����һ��ö�����ͣ�ʹ��choicesΪ��ǣ���ö�ٳ���no��yes��maybe�ֱ�����Ϊ0��1��2.

enum choices		//ö������ģ�壬ʹ��Ĭ��ֵ�����Ϊchoices
{
	no,
	yes,
	maybe
};

int main(void)
{
	enum choices choice;

	system("color 5A");
	srand((unsigned int)time(NULL));
	choice = rand() % 10;
	switch (choice)
	{
	case no:	printf("%d\n", choice);
		break;
	case yes:	printf("%d\n", choice);
		break;
	case maybe:	printf("%d\n", choice);
		break;
	default:	printf("No.\n");
		break;
	}

	getchar();
	return 0;
	
}
#include <stdio.h>
#include <stdlib.h>

#define MAXTITL 41
#define MAXAUTL 31

struct book				//�ṹģ���������book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};


/*
	C99�����ĸ����������Բ����ʺ����飬Ҳʹ���ڽṹ��
	����ʹ�ø������ִ���һ����������Ϊ���������򱻸�ֵ����һ���ṹ�Ľṹ��
	�﷨��ʹ������ָ���������������д��Բ�����У����һ���û������������ĳ�ʼ����Ŀ�б����磺
	(struct book){"C Primer Plus", "Stephen Prata", 60.00f};
*/
int main(void)
{
	struct book readfirst;
	int score;

	system("color 0A");
	printf("Enter test score:\n");
	scanf_s("%d", &score, 10);
	
	if (score >= 84)
	{
		readfirst = (struct book){				//���������ֽ�������ת��ֱ�Ӹ�ֵ
			"Crime and Punishment",
				"Fyodor Dostoyevsky",
				9.99f
		};
	}
	else
	{
		readfirst = (struct book){
			"Mr.Bouncy's Nice Hat",
				"Fred Winsome",
				5.99f
		};
	}
	printf("Your assigned reading:\n");
	printf("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);

	system("pause");
	return 0;
}
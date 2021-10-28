#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void)
{
	int choice;
	void count(void);		//��ӡ�˵�����ȴ��û���Ӧ

	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
		case 'a':
			printf("Buy low, sell high.\n");
			break;
		case 'b':
			putchar('\a');
			break;
		case 'c':
			count();
			break;
		default:
			printf("Program error!\n");
			break;
		}
	}
	printf("Bye!\n");

	getchar();
	return 0;
}

//��ȡ�û�ѡ��Ĳ˵�ѡ��
char get_choice(void)
{
	int ch;

	printf("Enter the letter of your choice: \n");
	printf("a.advice               b.bell\n");
	printf("c.count                q.quit\n");
	ch = get_first();
	while ((ch < 'a' || ch > 'c') && ch != 'q')
	{
		printf("Please respond the a, b, c, or q.\n");		//����a, b ,c ,q ������ַ�ʱ����ʾ�û�
		ch = get_first();
	}

	return ch;
}

//��ȡ�����еĵ�һ���ǿհ��ַ�
char get_first(void)
{
	int ch; 

	ch = getchar();
	while (isspace(ch))
	{
		printf("Please respond the a, b, c, or q.\n");
		ch = getchar();
	}	
	while (getchar() != '\n')
		continue;		//�޳������е�ʣ�ಿ��

	return ch;
}

//ѭ��д��
void count(void)
{
	int n;

	printf("Count how far? Enter an integer: \n");
	n = get_int();
	for (int i = 1; i <= n; i++)
		printf("%d\n", i);
}

//ȷ������һ����Ч����
int get_int(void)
{
	int input;
	char ch;

	
	while (scanf_s("%d", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);	//ȡ�����������
		printf(" is not an integer value.\nPlease enter an ");
		printf("integer value, such as 25, -225, or 3: ");
	}

	return input;
}
#include <stdio.h>

int get_int(void);		

int main(void)
{
	int num;

	printf("Please enter an inter to calculate:\n");
	num = get_int();
	printf("Thank you for participation!\n");

	getchar();
	getchar();
	return 0;
}

//��ȡ���룬�������ʱ��ʾ�û�����������ֵ
int get_int(void)
{
	int input;
	char ch;

	while (scanf_s("%d",&input) != 1)
	{
		while ((ch = getchar()) != '\n')
		{
			putchar(ch);
		}
		printf(" is not an integer.\nPlease enter an ");
		printf("integer value, such as 25, -178 or 3: ");
	}
	return input;
}
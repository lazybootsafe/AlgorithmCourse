#include <stdio.h>

void display(char ch, int lines,int cols);

int main(void)
{
	//���Խ����bug1��scanfɨ�����룬�����հ��Է����������ݺ�scanf���������Ŀհ׻��з�����getchar���ȡ���˻��з��������ڻ�Ӧ�û�����������ʾ��Bye������ȡ���˻��з���
	//�޸Ľ����_8.6_Դ����
	int ch;
	int lines, cols;

	printf("Please enter a character\n");
	printf("Enter a new line to quit : ");
	while ((ch = getchar()) != '\n')
	{
		printf("Enter two integers : ");
		scanf_s("%d %d", &lines, &cols, 10);
		display(ch, lines, cols);
		printf("Please Enter another character\n");
		printf("Enter a new line to quit : ");
	}
	printf("Bye!\n");
	
	getchar();
	getchar();
	return 0;
}

void display(char ch, int lines, int cols)
{
	for (int i = 1; i <= lines; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			putchar(ch);
		}
		printf("\n");
	}
}
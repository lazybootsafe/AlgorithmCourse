#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ch = 'A';
	char c;
	int num = 0;
	int j = 0;
	printf("Enter a capital letter: ");
	scanf_s("%c", &c, 1);
	//计算'A'到用户输入大写字母之间的差
	num = c - ch + 1;
	for (int i = 1; i <= num; i++)
	{
		//左上三角
		/*
		  ****
		  ***
		  **
		  *
		*/
		for (int j = 0; j < (num - i); j++)
		{
			printf("*");
		}
		//中三角
		/*
		     A
			AB
		   ABC
		  ABCD
		 ABCDE
		*/
		ch = 'A';
		for (int k = 0; k < i; k++)
		{
			printf("%c", ch++);
		}
		//右下三角
		/*
		      A
			  BA
			  CBA
			  DCBA
		*/
		--ch;
		for (int n = 1; n < i; n++)
		{
			printf("%c", --ch);
		}
		printf("\n");
	}

	return 0;
}

#endif
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
	//����'A'���û������д��ĸ֮��Ĳ�
	num = c - ch + 1;
	for (int i = 1; i <= num; i++)
	{
		//��������
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
		//������
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
		//��������
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
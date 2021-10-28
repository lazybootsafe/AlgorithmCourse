/*
	��дһ�����򣬸ó��������������в�����ȡ�����������ַ���,����ӡ��ÿ���ַ���ʹ��~������Ľ����
	�Լ�����������ʹ��& | ^ ������Ľ����ʹ�ö������ַ�������ʽ��ʾ���*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void show_bstr(int n);
bool is_bstr(char * p[], int n);
int tonumber(char * bstr);

int main(int argc, char * argv[])
{
	int para1, para2;

	system("color 5A");
	if (argc < 3)
	{
		printf("The command line's paramater is not right.\n");				//û�м�������2�����ַ���ʱ�˳�
		exit(EXIT_FAILURE);
	}
	if (!is_bstr(argv, argc))
	{
		printf("These aren't binary characters.\n");
		exit(EXIT_FAILURE);
	}

	para1 = tonumber(argv[1]);
	para2 = tonumber(argv[2]);

	printf("~%d = %d: ", para1, ~para1);
	show_bstr(~para1);

	printf("~%d = %d: ", para2, ~para2);
	show_bstr(~para2);

	printf("%d & %d = %d: ", para1, para2, para1&para2);
	show_bstr(para1&para2);

	printf("%d | %d = %d: ", para1, para2, para1|para2);
	show_bstr(para1|para2);

	printf("%d ^ %d = %d: ", para1, para2, para1^para2);
	show_bstr(para1^para2);

	getchar();
	return 0;
}

void show_bstr(int n)
{
	int i, size = 8 * sizeof(int)+1;
	char bstr[8 * sizeof(int)+1];

	for (i = size - 2; i >= 0; i--, n >>= 1)
	{
		bstr[i] = (n & 01) + '0';
	}
	bstr[size - 1] = '\0';
	//printf("%s\n", bstr);
	i = 0;
	while (bstr[i])
	{
		putchar(bstr[i]);
		if (++i % 4 == 0 && bstr[i] != '\0')
			putchar(' ');
	}
	putchar('\n');
}

bool is_bstr(char * p[], int n)
{
	char * pstr;

	//��ָ��Ԫ���ǳ�������ָ�룬���Դ�p[1]��ʼ����
	for (int i = 1; i < n; i++)
	{
		pstr = p[i];
		while (*pstr)
		{
			if (*pstr++ > '1')
				return false;
		}
	}

	return true;
}

int tonumber(char * pbin)
{
	unsigned int bin = 0, size = strlen(pbin);

	for (unsigned int i = 0; i < size; i++)
	{
		bin &= ~01;					//λ0����
		bin |= *(pbin + i) - '0';	//д��λ0
		bin <<= 1;					//����1λ
	}
	bin >>= 1;						//д�����һλ֮�����������1λ�����������ƶ�һλ���ַ���ת��Ϊ������λ

	return bin;
}
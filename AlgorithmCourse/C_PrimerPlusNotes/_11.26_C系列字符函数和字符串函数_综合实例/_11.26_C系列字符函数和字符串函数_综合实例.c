#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 81

void ToUpper(char * str);
int CountPunct(const char * str);

int main(void)
{
	char line[SIZE];
	
	system("color 0A");
	puts("Enter a line:");
	gets_s(line, SIZE);
	ToUpper(line);
	puts(line);
	printf("That line has %d punctuation characters.\n",
		CountPunct(line));

	getchar();
	return 0;
}

//�ַ���ת������д��ʽ
void ToUpper(char * str)
{
	while (*str)					//���ָ��ָ��ǿ��ַ�
	{
		*str = toupper(*str);		//��ָ���char�ַ�ת��Ϊ��д
		str++;
	}
}

//ͳ���ַ����ı�������
int CountPunct(const char * str)
{
	int count = 0;

	while (*str)
	{
		if (ispunct(*str))
			count++;
		str++;
	}

	return count;
}
#include <stdio.h>

#define PERIOD '.'		//����ַ�

int main(void)
{
	char ch;
	int charCount = 0;		//����

	while ((ch = getchar()) != PERIOD)	//�������ַ����Ǿ�ţ��������ַ���δ����ʱ
	{
		if (ch != '"' & ch != '\'')
		{
			charCount++;
		}
	}
	printf("There are %d non-quote characters.\n", charCount);
	
	getchar();
	getchar();
	return 0;

}
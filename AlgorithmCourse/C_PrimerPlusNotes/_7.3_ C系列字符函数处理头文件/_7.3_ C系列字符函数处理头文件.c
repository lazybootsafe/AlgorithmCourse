#include <stdio.h>
#include <ctype.h>		//�ṩ�ˡ���\\ ԭ��

int main(void)
{
	//����7.2��Դ���룬���û��������ĸ�ַ���������ANCII���еĺ�һ�����������ĸ�ַ�ԭ�����

	char ch;

	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))		//�������ַ�ʱ
		{
			putchar(ch + 1);	//��ı���
		}
		else					//����
		{
			putchar(ch);		//ԭ����ӡ��
		}
	}
	putchar(ch);				//��ӡ�����ַ�

	getchar();
	getchar();
	return 0;
}
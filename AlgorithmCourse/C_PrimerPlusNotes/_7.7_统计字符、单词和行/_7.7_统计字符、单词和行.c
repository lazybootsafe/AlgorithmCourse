#include <stdio.h>
#include <ctype.h>		//�ṩissapce()�ĺ���ԭ��
#include <stdbool.h>	//�ṩbool,true,false�Ķ���

#define STOP '|'

int main(void)
{
	char ch;				//�����ַ�
	char prev;				//ǰһ�������ַ�
	long  n_chars = 0L;		//�ַ���
	int n_lines = 0;			//����
	int n_words = 0;			//������
	int p_lines = 0;			//������������
	bool inWord = false;	//���һ�����ʵĿ�ʼ�����ch��һ���������inWord == true

	printf("Please enter text to be analyzed (| to terminate):\n");
	prev = '\n';			//ʶ����������
	while ((ch = getchar())!= STOP)
	{
		n_chars++;		//ͳ���ַ�
		if (ch == '\n')
		{
			n_lines++;	//ͳ����
		}	
		if (!isspace(ch) && !inWord)		//���ch���ǿհ��ַ�������ch������һ��������
		{
			inWord = true;		//��ʼһ���µ���
			n_words++;			//ͳ�Ƶ���
		}
		if (isspace(ch) && inWord)		//���ch�ǿհ��ַ�������ch����һ��������
		{
			inWord = false;		//���ﵥ�ʵ�β��
		}
		prev = ch;				//�����ַ�ֵ
	}
	if (prev != '\n')
	{
		p_lines = 1;
	}
	printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
	printf("partical lines = %d\n", p_lines);

	getchar();
	getchar();
	getchar();
	return 0;
}
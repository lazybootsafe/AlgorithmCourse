#include <stdio.h>

void put1(const char * string);
int put2(const char * string);

int main(void)
{
	/*�ۺ�_11.11��11.10_ʵ���Զ���IO������Ӧ��*/

	put1("If I'd as much money");
	put1("as I could spend, \n");
	printf("I count %d characters.\n",
		put2("I never would cry old chairs to mend."));		//���������������ݲ���ѹջ,�Ƚ�����ѹ��ջ�У�Ȼ����ú���ʵ�ֹ���

	getchar();
	return 0;
}

//��ӡ�ַ���
void put1(const char * string)
{
	while (*string) /*Ӧ����Ϥ����C����Ա��ϰ��д����������Ч��
					  �ȼ���*string != '\n'*/
	{
		putchar(*string++);
	}
}

//��ӡ�ַ��������سɹ���ӡ���ַ���
int put2(const char * string)
{
	int count = 0;

	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');

	return count;
}
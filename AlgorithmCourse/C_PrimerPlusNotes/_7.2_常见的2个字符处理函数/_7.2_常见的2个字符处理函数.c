#include <stdio.h>
#define SPACE ' '		//�ַ����ո�

int main(void)
{
	//���û�������ַ����а���ÿ���ַ�����һ��ANCII�ַ�������ո��ַ����ֲ���

	int ch = getchar();		//����һ���ַ�
	while (ch != '\n')		//����һ����ʱ
	{
		if (ch == SPACE)
		{
			putchar(ch);		//����ո�ʱ��ԭ�����
		}
		else
		{
			putchar(ch + 1);	//�ı�������ַ�����һ��ANCII�ַ������
		}
		ch = getchar();			//������һ���ַ�
	}
	putchar(ch);

	getchar();
	return 0;
}
#if 0

#include <stdio.h>

int main(void)
{
	int count = 0;
	char ch;
	while ((ch = getchar()) != '#')	//�˳�����
	{
		if (count++ % 8 == 0)	//ÿ��ӡ�˸��ַ�����
			printf("\n");
		if (ch == '\n')			//��ӡ����ʮ������
			printf("'\\n'-%03d. ", ch);
		else if (ch == '\t')	//��ӡ�Ʊ��ʮ������
			printf("'\\t'-%03d. ", ch);
		else
			printf("'%c'-%03d. ", ch, ch);	//��ӡ�ַ�ʮ������
	}

	return 0;
}

#endif
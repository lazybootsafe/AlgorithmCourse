#include <stdio.h>

int main(void)
{
	/*��ʱΪ������ܳ�ʼ�������Ա�����������С�����Բ������������С��
	�ɱ������Զ�ƥ���������ѳ�ʼ���ĳ�Ա��Ŀ*/

	const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //����Ϊֻ������

	size_t size = sizeof days / sizeof days[0];		//�����Ա��, �������С���Ե�����Ա��С
	for (int i = 0; i < size; i++)	
	{
		printf("Month %2d has %2d days.\n", i + 1, days[i]);
	}

	getchar();
	return 0;
}
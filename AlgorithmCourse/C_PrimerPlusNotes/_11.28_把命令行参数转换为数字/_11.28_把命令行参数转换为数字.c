#include <stdio.h>
#include <stdlib.h>

/*���������л�����������в��������������Գ���*/

int main(int argc, char * argv[])
{
	int times;

	if (argc < 2 || (times = atoi(argv[1])) < 1)			//����û�ô�����������в����������������������
	{
		printf("Usage: %s positive-number\n", argv[0]);		//�����û�
	}
	else
	for (int i = 0; i < times; i++)
		puts("Hello, good looking!");

	getchar();
	return 0;
}
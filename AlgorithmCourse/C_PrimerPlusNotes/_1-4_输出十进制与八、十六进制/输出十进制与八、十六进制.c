#include <stdio.h>		//���øñ�׼�������ͷ�ļ��е�printf����
int main(void)
{
	int num = 100;

	printf("dec = %d, octal = %o, hex = %x, hex = %X\n", num, num, num, num);
	printf("dec = %d, octal = %#o, hex = %#x, hex = %#X\n", num, num, num, num);

	getchar();
	return 0;
}
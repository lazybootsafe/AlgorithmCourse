#include <stdio.h>

int main(void)
{
	//��ǰ20��������ƽ��������ѽ
	int number = 1;

	while (number <= 20)
	{
		printf("%4d %6d \n", number, number*number);
		number = number + 1;
	}
	getchar();
	return 0;
}
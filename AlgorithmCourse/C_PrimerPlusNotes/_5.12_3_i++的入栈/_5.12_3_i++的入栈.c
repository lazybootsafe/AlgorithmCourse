#include <stdio.h>

int main(void)
{
	int num = 1;

	while (num < 21)
	{
		printf("%10d %10d\n", num, num*num++);/*�����Ĵ���������ջ���£�num�����㱾���ƽ����֮���1��
											   ����num��Ϊ��һ���ֵ,����num+1ƽ��==num*num*/
	}
	getchar();
	return 0;
}
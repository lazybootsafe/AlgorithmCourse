#include <stdio.h>
#include <iso646.h>		//�ṩ���߼��������λ��������ַ�ƴд��ʽ

int main(void)
{
	int num = 1;
	int xorValue;

	/*if (num != 2 && num != 3)
	{
		xorValue = num ^ num;			
		printf("%d xor %d = %d", num, num, xorValue);
	}
	*/

	//�������ȼ��ڣ�
	if (num != 2 and num != 3)
	{
		xorValue = num xor num;			//1��1���Ϊ0
		printf("%d xor %d = %d", num, num, xorValue);
	}

	getchar();
	return 0;

}
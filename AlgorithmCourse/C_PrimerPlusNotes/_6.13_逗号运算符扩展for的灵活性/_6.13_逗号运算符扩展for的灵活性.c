#include <stdio.h>

int main(void)
{
	/*for(initilize;test;update)ÿ�����ʽ�������ɶ��Ÿ����Ķ�����ʽ���
	 for(expression1, espression2, ...; varible < length; expression1, espression2, ...)*/

	const int FIRST_OZ = 37;
	const int NEXT_OZ = 23;
	int ounces, cost;

	printf("ounces cost\n");
	for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
	{
		printf("%5d %4.2f\n", ounces, (float)cost / 100.0);
	}
	getchar();
	return 0;
}
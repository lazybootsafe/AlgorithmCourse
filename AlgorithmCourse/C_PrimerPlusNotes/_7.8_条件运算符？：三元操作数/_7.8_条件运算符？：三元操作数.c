#include <stdio.h>

#define COVETRAGE 200 /*ÿ��������ƽ��Ӣ����*/

int main(void)
{
	/*����������������������ʽ expression1 ? expression2 : expression3;
								���expression1Ϊ�棬�����������ʽ��ֵΪexpression2������Ϊexpression3*/
	//�����������ƽ��Ӣ�ߵ����Ϳ���ᣬȫ��Ϳ������ٹ�����.��ѧ������ƽ��Ӣ������ÿ�޿�Ϳ��ƽ��Ӣ�����������������ʱ��Ӧ�ý�1(��1.2ȡ2)

	int sq_feet;
	int cans;

	printf("Enter number of square feet to be painted(q to quit):\n");
	while (scanf_s("%d",&sq_feet) == 1)
	{
		cans = sq_feet / COVETRAGE;
		cans += (sq_feet % COVETRAGE == 0) ? 0 : 1;
		printf("You need %d %s of paint.\n", cans,
			(cans == 1) ? "can" : "cans");
		printf("Please enter next number of square feet to be painted(q to quit):\n");
	}
	
	return 0;
}
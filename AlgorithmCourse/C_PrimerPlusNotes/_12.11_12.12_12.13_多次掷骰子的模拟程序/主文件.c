//��������ӵ����ļ�

#include <stdio.h>		
#include "roll_dice.h"		//�ṩ��roll_more()��roll_count��ԭ��
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int dice;
	int sides;
	int roll;

	system("color 5A");
	printf("Enter sides of die (q to quit):\n");
	while (scanf_s("%d", &sides, 10) == 1)
	{
		printf("How many times to dice:\n");
		scanf_s("%d", &dice, 10);			//Ҫ���Ĵ���
		roll = dice_more(dice, sides);
		printf("You have rolled %d using %d-%d sides die.\n", roll, dice, sides);
		printf("Enter sides of die (q to quit):\n");
	}
	printf("The roll_once function has been called %d times\n", roll_count);
	printf("GOOD FUNTUEN TO YOU, BYE!\n");

	system("pause");
	return 0;
}
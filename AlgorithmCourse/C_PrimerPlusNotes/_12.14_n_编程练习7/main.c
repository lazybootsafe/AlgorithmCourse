
//_12.13_���°汾����n�����ӣ��ܹ���m�Σ�����ÿ�����õĵ���֮��

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dicedie(int dice, int sides, int dieamount);

int main(int argc, char * argv[])
{
	int dice;											//���Ĵ���
	int sides;											//��������
	int dieamount;										//���Ӹ���

	system("color 5A");
	srand((unsigned int)time(NULL));					//��ʼ������
	puts("Enter the number of sets: q to stop");
	while (scanf_s("%d", &dice, 10))
	{
		puts("How many sides and how many dice?");
		scanf_s("%d %d", &sides, &dieamount, 10);
		dicedie(dice, sides, dieamount);
		puts("Enter the number of sets: q to stop");
	}
	puts("Done!");

	system("pause");
	return 0;
}

void dicedie(int dice, int sides, int dieamount)
{
	int roll = 0;										//ÿ�����ĵ���֮��
	int i, j;

	printf("Here are %d sets of %d %d-sided throws.\n", dice, dieamount, sides);
	for (i = 0; i < dice; i++)							//��dice��
	{
		for (j = 0, roll = 0; j < dieamount; j++)		//ÿ����dieamount��
		{
			roll += rand() % sides + 1;
		}
		printf("%3d", roll);
		if (i % 15 == 14)
		{
			putchar('\n');
		}
	}
	if (i % 15 != 0)
	{
		putchar('\n');
	}
}
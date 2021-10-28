/*7.��дһ�����򣬰��ճ����嵥12.13���ʾ���������۵����ݣ��޸ĸ�
����ʹ��������ƣ�
Enter the number of sets; enter q to stop : 18
943
How many sides and how many dice? 6 3
Here are 18 sets of 3 6-sided throws.
12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
13 8 14
How many sets? Enter q to stop: q*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void roll_count(int sets, int sides, int dice);

int main(void)
{
    int sets;
    int sides, dice;

    srand((unsigned int)time(0));
    printf("��Ҫ�������� q�뿪: ");
    while (scanf("%d", &sets) == 1)
    {
        printf("�����棬����ɸ��? ");
        scanf("%d%d", &sides, &dice);
        printf("�ܹ�%d������%d��ɸ��%d����ĵ����ϼ�Ͷ��������¡�\n",
                sets, dice, sides);
        roll_count(sets, sides, dice);
        printf("��Ҫ�������� q�뿪: ");
    }
    printf("Bye.\n");
}

void roll_count(int sets, int sides, int dice)
{
    int i, j;
    int roll;

    if (sides < 2)
    {
        printf("����2����\n");
        return;
    }
    if (dice < 1)
    {
        printf("����1��ɸ��.\n");
        return;
    }
    srand((unsigned int)time(0));
    for (i = 0; i < sets; i++)
    {
        roll = 0;
        for (j = 0; j < dice; j++)
            roll += rand() % sides + 1;
        printf("%d ", roll);
    }
    printf("\n");
}

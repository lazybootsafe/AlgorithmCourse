#include<stdio.h> //����ת��Ϊ�ܺ���
#define WEEK_DAY 7
int main(void)
{
    int day=0,week=0,right=0;
    printf("������һ������:");
    scanf("%d",&day);
    while(day>0)
    {
        week=day/WEEK_DAY;
        right=day%WEEK_DAY;
        printf("%d����%d��,%d��.\n ",day,week,right);
        printf("��������0ʱ����\n");
        scanf("%d",&day);
    }
    system("pause");
    return 0;
}

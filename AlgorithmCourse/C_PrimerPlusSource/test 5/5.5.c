#include<stdio.h> //����ǰ20�������ĺ�

int main(void)
{
    int money=0,day=0,a=0;
    printf("������ÿ��׬����Ǯ:");
    scanf("%d",&money);
    a=money;
    while (day++<20)
    {
        printf("��%d��׬%dǮ.\n",day,money);
        money=money+a;
    }
    system("pause");
    return 0;
}

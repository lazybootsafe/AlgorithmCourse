/* 1.��ʹ��ȫ�ֱ�������д�����嵥12.4��*/
#include <stdio.h>
int critic(void);
int main(void)
{
    int units = 0;   /* �ⲿ���� */

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        units=critic();
    printf("You must have looked it up!\n");
    return 0;
}
int critic(void)
{
    int n=0;
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &n);
    return n;
}

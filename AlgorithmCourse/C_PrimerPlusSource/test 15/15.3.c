/*3.��дһ������������һ�� int ���͵Ĳ����������ظò����д�λ��
��������һ�������в��Ըú���*/
#include <stdio.h>
#include <limits.h>

int count_bit(int n);

int main(void)
{
    int n;

    puts("����һ��������");
    while( (scanf("%d",&n)) != 1)
    {
        printf("������һ������.");
        while(getchar() != '\n') continue;
    }
    while(getchar() != '\n') continue;
    printf("%d��λ��������%d.\n",n,count_bit(n));

    return 0;
}

int count_bit(int n)
{
    int i=0;
    while(n)
    {
        if(n&01)//n&01����n���һλ��ֵ
            i++;
        n>>=1;//��ͬ��n/=2
    }

    return i;
}

#include<stdio.h> //��������,��ӡ�ȸ�����10����

int main(void)
{
    long a,b=0;
    printf("������һ������:");
    scanf("%ld",&a);
    while(b++<11)
    {
        printf("%ld ",a++);
    }
    system("pause");
    return 0;
}

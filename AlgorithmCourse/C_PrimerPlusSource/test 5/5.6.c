#include<stdio.h> //����ǰn��������ƽ��

int main(void)
{
    long numble=0,a=0,b=0;
    printf("����һ������:");
    scanf("%d",&numble);
    while (a++<numble)
    {
        b=a*a;
        printf("%d��ƽ����%d.\n",a,b);

    }
    system("pause");
    return 0;
}

#include<stdio.h> //��������������,������������������ƽ����
int main(void)
{
    long a,b,i,j,k;
    printf("��������������(��С���):");
    while(scanf("%ld%ld",&a,&b)==2,a<b)
    {
        for(i=0,k=0;i<=b-a;i++)
        {
            j=(a+i)*(a+i);
            k+=j;
        }
    printf("%ld ��%ld ��ƽ������%ld\n",a*a,b*b,k);
    printf("������һ����:");
    }
    system("pause");
    return 0;
}


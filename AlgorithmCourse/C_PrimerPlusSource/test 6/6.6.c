#include<stdio.h> //��ӡ���޵�����֮�������,����ƽ��,��������
int main(void)
{
    long a,b,c,d,e;
    printf("������һ����������:");
    scanf("%ld",&a);
    printf("��������һ����������:");
    scanf("%ld",&b);
    printf("%20s%20s%20s%20s\n","���","����","ƽ��","����");
    for(c=1;c<=b-a+1;c++)
    {
        d=(a+c-1)*(a+c-1);
        e=(a+c-1)*(a+c-1)*(a+c-1);
        printf("%20d%20ld%20ld%20ld\n",c,a+c-1,d,e);
    }

    return 0;
}

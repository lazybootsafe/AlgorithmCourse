#include<stdio.h> //��ʽ�¶�ת�����¶ȺͿ�ʽ�¶�
void Temperatures(double n);
int main(void)
{
    float n;
    printf("����һ�������¶ȨH:");

    while(scanf("%f",&n)==1)
    {
        Temperatures(n);
        printf("������һ��(q��������뿪):");
    }
    system("pause");
    return 0;
}

void Temperatures(double n)
{
    const float a=5.0,b=9.0,c=32.0,d=273.16;
    float e=0,f=0;
    e=a/b*(n-c);
    f=e+d;
    printf("�����¶�:%.2f�H �����¶�:%.2f�� ��ʽ�¶�:%.2fK\n",n,e,f);
}

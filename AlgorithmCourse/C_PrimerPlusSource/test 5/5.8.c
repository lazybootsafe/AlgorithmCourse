#include<stdio.h> //����ģ

int main(void)
{
    int first,second;
    printf("����ģ�ĵڶ���:");
    scanf("%d",&second);
    printf("���������һ��:");
    scanf("%d",&first);
    while(first>0)
    {
        printf("%d %% %d �� %d\n",first,second,first%second);
        printf("������һ������Ϊģ�ĵ�һ��(С��0�˳�):");
        scanf("%d",&first);
    }
    system("pause");
    return 0;
}

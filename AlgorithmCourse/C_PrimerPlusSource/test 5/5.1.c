#include<stdio.h> //�ѷ���ת��ΪСʱ�ͷ���
#define SECOND 60
int main(void)
{
    int minute=0,hour=0,right=0;
    printf("�����������:");
    scanf("%d",&minute);
    while(minute>0)
    {
        hour=minute/SECOND;
        right=minute%SECOND;
        printf("%d������%dСʱ��%d����\n",minute,hour,right);
        printf("������һ��������(С�ڵ���0ʱֹͣ)\n");
        scanf("%d",&minute);
    }
    system("pause");
    return 0;
}

/*5.һ���Լ��3.156��10 7 �롣��дһ��������ʾ�û��������䣬Ȼ����
ʾ�������Ӧ��������*/
#include<stdio.h>
int main(void)
{
    int ages;
    double seconds;
    printf("������:");
    scanf("%d",&ages);
    seconds=ages*3.156e7;
    printf("��������Ӧ��������:%e��.",seconds);

    return 0;
}

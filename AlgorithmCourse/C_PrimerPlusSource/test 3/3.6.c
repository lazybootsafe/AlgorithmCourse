/*6.1��ˮ���ӵ�����ԼΪ3.0��10 -23 �ˡ�1����ˮ��Լ��950�ˡ���дһ��
������ʾ�û�����ˮ�Ŀ�����������ʾˮ���ӵ�������*/
#include<stdio.h>
int main(void)
{
    float water=0.0,n=0.0;
    double m;
    printf("������ˮ�Ŀ�����:\n");
    scanf("%f",&water);
    n=water*950;
    m=n/3.0e-23;
    printf("��ô����Ϊ%.2f�˵�ˮ��ˮ����������:%le\n",n,m);

    return 0;
}

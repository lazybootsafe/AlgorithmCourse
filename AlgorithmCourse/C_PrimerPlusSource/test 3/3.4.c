/*4.��дһ�����򣬶�ȡһ�����������ȴ�ӡ��С������ʽ���ٴ�ӡ��ָ
����ʽ��Ȼ�����ϵͳ֧�֣��ٴ�ӡ��p����������ʮ�����Ƽ���������
�����¸�ʽ�����ʵ����ʾ��ָ��λ����ϵͳ���죩��
Enter��a��floating-point��value:��64.25
fixed-point��notation:��64.250000
exponential��notation:��6.425000e+01
p��notation:��0x1.01p+6*/
#include<stdio.h>
int main(void)
{
    float a;
    printf("����һ��С��:(������64.25)");
    printf("_____\b\b\b\b\b");
    scanf("%f",&a);
    printf("Enter a floating-point value:%.2f\n",a); //64.25
    printf("fixed-point notation:%f\n",a);    //64.250000
    printf("exponential notation:%e\n");   //6.425000e+01
    printf("p notation:%.2a\n");    //0x1.01p+6

    return 0;
}

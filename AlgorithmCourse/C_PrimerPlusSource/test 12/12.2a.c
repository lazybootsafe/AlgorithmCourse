/* 2.��������ͨ����Ӣ��/�����������ͺģ���ŷ�ޣ�����/100 ��������
�㡣�����ǳ����һ���֣���ʾ�û�ѡ�����ģʽ�����ƻ��ƣ���Ȼ���
�����ݲ������ͺġ�
// pe12-2b.c
// �� pe12-2a.c һ�����
#include <stdio.h>
#include "pe12-2a.h"
int main(void)
{
    int mode;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
��������һЩ���ʾ����
Enter 0 for metric mode, 1 for US mode: 0
Enter distance traveled in kilometers: 600
Enter fuel consumed in liters: 78.8
Fuel consumption is 13.13 liters per 100 km.
Enter 0 for metric mode, 1 for US mode (-1 to quit): 1
Enter distance traveled in miles: 434
Enter fuel consumed in gallons: 12.7
Fuel consumption is 34.2 miles per gallon.
Enter 0 for metric mode, 1 for US mode (-1 to quit): 3
Invalid mode specified. Mode 1(US) used.
Enter distance traveled in miles: 388
Enter fuel consumed in gallons: 15.3
Fuel consumption is 25.4 miles per gallon.
Enter 0 for metric mode, 1 for US mode (-1 to quit): -1
Done.
����û������˲���ȷ��ģʽ���������û�������ʾ��Ϣ��ʹ����һ��
�������ȷģʽ�����ṩpe12-2a.hͷ�ļ���pe12-2a.cԴ�ļ���Դ�����ļ�Ӧ
����3�������ļ��������ڲ����ӵı�����һ����ʾģʽ��һ����ʾ��
�롢һ����ʾ���ĵ�ȼ�ϡ�get_info()���������û������ģʽ��ʾ�û�����
��Ӧ���ݣ������䴢�浽�ļ�����������С�show_info()�����������õ�ģ
ʽ���㲢��ʾ�ͺġ����Լ����û�����Ķ�����ֵ���ݡ�*/
#include <stdio.h>
#include "12.2.h"
#include "12.2b.c"
int main(void)
{
    int mode;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}



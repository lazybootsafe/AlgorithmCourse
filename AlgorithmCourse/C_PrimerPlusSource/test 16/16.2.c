/*2.�����ĵ���ƽ�����������㣺�ȵõ������ĵ�����Ȼ�������������
��ƽ��ֵ�����ȡ�������ĵ�����ʹ��#defineָ���һ���ꡰ��������ִ
�и����㡣��дһ���򵥵ĳ�����Ըúꡣ*/

#include <stdio.h>
#include <stdlib.h>

#define HARMONIC_AVERAGE1(X,Y)  1/( (1/(X)+1/(Y))/2 )
#define HARMONIC_AVERAGE2(X,Y)  (2*(X)*(Y))/((X)+(Y))

int main()
{
    double x,y;

    puts("������������(������ĸ�뿪����)");
    while( scanf("%lf%lf",&x,&y) ==2)
    {
        while(getchar() != '\n') continue;
        printf("�õ�һ����ʽ%.3lf��%.3lf�ĵ���ƽ������%.3lf\n",x,y,HARMONIC_AVERAGE1(x,y));
        printf("�õڶ�����ʽ%.3lf��%.3lf�ĵ���ƽ������%.3lf\n",x,y,HARMONIC_AVERAGE2(x,y));
        puts("������������(������ĸ�뿪����)");
    }
    puts("�ټ�.");

    return 0;
}

/*3.��������������ģ���������ĳ��ȣ����������x����ʱ����ת�Ľ�
����������������ֱ��������������x���y�����������������������ͼ
16.3������дһ�����򣬶�ȡ������ģ�ͽǶȣ���λ���ȣ���Ȼ����ʾx��
��y������ꡣ��ط������£�
x = r*cos A y = r*sin A
��Ҫһ�����������ת�����ú�������һ������������Ľṹ��������
һ������ֱ������Ľṹ���򷵻�ָ��ýṹ��ָ�룩��*/

#include "16.3.h"
int main()
{
    polar pv;//������ṹ
    rect rv;//ֱ������ṹ

    puts("�����뼫����Ĵ�С�ͽǶ�(q�뿪):");
    while( (scanf("%lf%lf",&pv.magnitude,&pv.angle) == 2))
    {
        rv=polar_to_rect(pv);
        printf("��Ӧ��ֱ��������x=%.3lf,y=%.3lf\n\n",rv.x, rv.y);
        puts("�����뼫����Ĵ�С�ͽǶ�(q�뿪):");
    }
    puts("�ټ�.");

    return 0;
}

rect polar_to_rect(polar pv)//������ת��Ϊֱ������
{
    rect rv;

    rv.x=pv.magnitude*cos(pv.angle*DEG_TO_RED);
    rv.y=pv.magnitude*sin(pv.angle*DEG_TO_RED);

    return rv;
}

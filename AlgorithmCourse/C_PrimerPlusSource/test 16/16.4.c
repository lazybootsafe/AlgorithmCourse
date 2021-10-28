/*4.ANSI����������clock()���������ԣ�
#include <time.h>
clock_t clock (void);
���clock_t�Ƕ�����time.h�е����͡��ú������ش�����ʱ�䣬�䵥
λȡ����ʵ�֣����������ʱ�䲻���û��޷���ʾ���ú���������-1����Ȼ
����CLOCKS_PER_SEC��Ҳ������time.h�У���ÿ�봦����ʱ�䵥λ����
������ˣ����� clock()����ֵ�Ĳ�ֵ���� CLOCKS_PER_SEC�õ����ε���
֮�侭�����������ڽ��г�������֮ǰ����ֵ������ǿ��ת����double��
�ͣ����Խ�ʱ�侫ȷ��С�����Ժ󡣱�дһ������������һ��double���͵�
������ʾʱ���ӳ�����Ȼ�������ʱ������һ��ѭ������дһ���򵥵ĳ���
���Ըú�����*/

#include <stdio.h>
#include <time.h>
#define CCS ((double)clock()/CLOCKS_PER_SEC)

void check_delay(double time);

int main()
{
    double time;

    puts("��������ʾ�˵����ӳ�(q�뿪):");
    while( scanf("%lf",&time) ==1 )
    {
        check_delay(time);
        puts("ʱ�䵽��.");
        puts("�ٴ������ӳ�(q�뿪):");
    }

    return 0;
}

void check_delay(double time)
{
    double start=CCS;
    while((CCS - start) <time )
        ;
}

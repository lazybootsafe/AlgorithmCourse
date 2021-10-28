/*4.��дmall.c�������嵥17.7��������������ģ������̯λ*/

#include <stdio.h>
#include <stdlib.h>       // �ṩ rand() �� srand() ��ԭ��
#include <time.h>        // �ṩ time() ��ԭ��
#include "17.4.h"
#include "17.4queue.c"
#define MIN_PER_HR 60.0

bool newcustomer(double x);  // �Ƿ����¹˿͵�����
Item customertime(long when); // ���ù˿Ͳ���

int main(void)
{
    Queue line1;
    Queue line2;
    Item temp;          // �µĹ˿�����

    int hours;          // ģ���Сʱ��
    int perhour;         // ÿСʱƽ������λ�˿�
    int wait_time1 = 0;     //̯λ1�ӵ�ǰ�����е�ʱ��
    int wait_time2 = 0;     //̯λ2�ӵ�ǰ�����е�ʱ��
    long cycle, cyclelimit;  // ѭ����������������������
    long turnaways = 0;     // ������������ܵĹ˿�����
    long customers = 0;     // ������еĹ˿�����
    long served = 0;      // ��ģ���ڼ���ѯ��Sigmund�Ĺ˿�����
    long sum_line = 0;     // �ۼƵĶ����ܳ�
    double min_per_cust;    // �˿͵�����ƽ��ʱ��
    long line_wait = 0;     // �����ۼƵĵȴ�ʱ��

    puts("����ģ���Сʱ��:");
    scanf("%d", &hours);
    puts("����ÿСʱ��ƽ���ͻ�����:");
    scanf("%d", &perhour);
    cyclelimit = MIN_PER_HR * hours;
    min_per_cust = MIN_PER_HR / perhour;

    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand((unsigned int) time(0)); // rand() �����ʼ��
    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line1)&&QueueIsFull(&line2))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                if(line1.items>line2.items)
                    EnQueue(temp, &line2);
                else if(line2.items>line1.items)
                    EnQueue(temp, &line1);
                else
                    (rand()%2) ? EnQueue(temp, &line1):EnQueue(temp, &line2);
            }
        }
        if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
        {
            DeQueue(&temp, &line1);
            wait_time1 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue(&temp, &line2);
            wait_time2 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }

        if (wait_time1 > 0)
            wait_time1--;

        if (wait_time2 > 0)
            wait_time2--;

        sum_line +=(long)QueueItemCount(&line1)
                    +(long)QueueItemCount(&line2);
    }
    if (customers > 0)
    {
        printf("���ܵĹ˿�: %ld\n", customers);
        printf("����Ĺ˿�: %ld\n", served);
        printf("�뿪�Ĺ˿�: %ld\n", turnaways);
        printf("ƽ�����д�С: %.2f\n",
            (double) sum_line / cyclelimit);
        printf("ƽ���ȴ�ʱ��: %.2f minutes\n",
            (double) line_wait / served);
    }
    else
        puts("û�й˿�!");
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");

    return 0;
}
// x�ǹ˿͵�����ƽ��ʱ�䣨��λ�����ӣ�
// ���1�������й˿͵������򷵻�true
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}
// when�ǹ˿͵�����ʱ��
// �ú�������һ��Item�ṹ���ù˿͵����ʱ������Ϊwhen��
// ��ѯʱ������Ϊ1��3�����ֵ
Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}

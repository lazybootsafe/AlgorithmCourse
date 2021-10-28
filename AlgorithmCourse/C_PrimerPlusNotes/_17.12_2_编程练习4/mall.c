//�Զ�������ģ��2������̯λ

//mall.c -- ʹ��Queue�ӿ�

#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>						//Ϊsrand()��rand()�ṩ����ԭ��
#include <assert.h>						//��assert()
#include <time.h>						//Ϊtime()�����ṩԭ��
#include "queue.h"						//�ı�Item��typedef

#define MIN_PER_HR 60.0

bool newcustomer(double x);				//���¹˿͵�����
Item customertime(long when);			//���ù˿Ͳ���

int main(void)
{
	Queue line[2];
	Item temp;							//�����¹˿͵�����
	int hours;							//ģ���Сʱ��
	int perhour;						//ÿСʱ�˿͵�ƽ����
	long cycle, cyclelimit;				//ѭ�������������������Ͻ�
	long turnaways = 0;					//��������������ܾ��Ĺ˿���
	long customers = 0;					//��������еĹ˿���
	long served = 0;					//��ģ���ڼ�õ�����Ĺ˿���
	long sum_line = 0;					//�ۼƵĶ��г���
	int wait_time = 0;					//�ӵ�ǰ��Siqmund���������ʱ��
	long line_wait = 0L;				//�����ۼƵȴ�ʱ��
	double min_per_cust;				//�˿͵�����ƽ�����ʱ��
	Queue current;


	InitializeQueue(&line[0]);
	InitializeQueue(&line[1]);
	
	srand((unsigned int)time(NULL));
	puts("Case Study: Siqmund Lander's Advance Booth.");
	puts("Enter the number of simulation hours:");
	assert(scanf("%d", &hours) == 1);

	cyclelimit = (long)MIN_PER_HR * (long)hours;
	puts("Enter average number of custmers per hour:");
	assert(scanf("%d", &perhour) == 1);

	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (QueueIsFull(&line[0]) && QueueIsFull(&line[1]))
				turnaways++;
			else
			{
				customers++;
				temp = customertime(cycle);
				if (!QueueIsFull(&line[0]))
				{
					EnQueue(temp, &line[0]);
				}
				else
				{
					EnQueue(temp, &line[1]);
				}
			}
		}
		if (wait_time <= 0)
		{
			if (!QueueIsEmpty(&line[0]))
			{
				DeQueue(&temp, &line[0]);
			}
			else
			{
				DeQueue(&temp, &line[1]);
			}
			wait_time = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += QueueItemCount(&line[0]) + QueueItemCount(&line[1]);
	}

	if (customers > 0)
	{
		printf("customers accepted: %ld\n", customers);
		printf("  customers served: %ld\n", served);
		printf("         turnaways: %ld\n", turnaways);
		printf("average queue size: %.2f\n", 
			(double)sum_line / cyclelimit);
		printf(" average wait time: %.2f minutes.\n", 
			(double)line_wait / served);
	}
	else
		puts("No customers!");

	EmptyTheQueue(&line[0]);
	EmptyTheQueue(&line[1]);
	puts("Bye!");

	system("pause");
	return 0;

}

/*x�ǹ˿͵�����ƽ�����ʱ�䣨����ƣ�
�����1�������й˿͵������򷵻�true*/
bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*when�ǹ˿͵�����ʱ��
��������һ��Item�ṹ���ýṹ�Ĺ˿͵���ʱ����Ϊwhen
��Ҫ��ѯ��ʱ����Ϊһ��1��3֮������ֵ*/
Item customertime(long when)
{
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
/*���Ժ���rand1()��srand()*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>		//Ϊtime()�����ṩANSCIIԭ��

extern void srand1(unsigned int x);		//�����������ⲿ����
extern int rand1(void);					//ͬ��
extern unsigned long int next;

int main(void)
{
	int count;
	unsigned seed;

	system("color 0A");
	
	//1.�û�����һ������ֵ
	/*printf("Please enter your choice for seed(q to quit): \n");
	while (scanf_s("%u", &seed, 10) == 1)
	{
		srand1(seed);
		for (count = 0; count < 5; count++)
		{
			printf("%hd \n", rand1());
		}
		printf("Please enter your choice for seed(q to quit): \n");
	}
	printf("Bye!\n");*/


	//2.ʹ��ϵͳʱ�ӳ�ʼ������ֵ
	printf("%d", 7);
	seed =  (unsigned int)time(NULL);		//����time()��ȡϵͳʱ�ӣ���Ϊ���������(ע�⣬time()�ķ���ֵ��time_t���ͣ�ǿ��ת�����ܳ��ֽض�)
	srand1(seed);
	printf("Here are some random number: \n");
	for (count = 0; count < 5; count++)
	{
		printf("%hd \n", rand1());
	}

	getchar();
	getchar();
	getchar();
	return 0;
}
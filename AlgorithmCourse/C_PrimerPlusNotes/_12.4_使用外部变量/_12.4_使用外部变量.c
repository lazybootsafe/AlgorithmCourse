#include <stdio.h>

int units = 0;					//�����ⲿ����������ʼ��ʱ��Ĭ��Ϊ0��, �Ժ��溯�����ã��ⲿ����ֻ���ڶ���ʱ�����г�ʼ��
	//��һ�����������������������洢�ռ䣩

void critic(void);

int main(void)
{
	extern int units;			//��߳���Ŀɶ��ԣ���ѡ�Ķ����������洢��˵����extern���߱������ڸú������õ���units����ָͬһ���ں����⣨�������ļ��⣩����� ������
	//�ڶ��������������������ؼ���extern�������������Ƕ��壬��Ϊ��ָʾ�������ο������ط���extern����һ���Ѿ����ڵ��ⲿ����

	printf("How many pounds to a firkin of butter?\n");
	scanf_s("%d", &units, 10);
	while (units != 56)
	{
		critic();
	}
	printf("You must have looked up!\n");

	getchar();
	getchar();
	return 0;
}

void critic(void)
{
								//��������˿�ѡ�Ķ�������
	printf("No luck, chumy.Try again!\n");
	scanf_s("%d", &units, 10);	//�ⲿ����
}
#include <stdio.h>
//�����ⲿ����������ʼ��ʱ��Ĭ��Ϊ0��, �Ժ��溯�����ã��ⲿ����ֻ���ڶ���ʱ�����г�ʼ��
//��һ�����������������������洢�ռ䣩

void critic(int * ptr);

int main(void)
{
	int units;

	printf("How many pounds to a firkin of butter?\n");
	scanf_s("%d", &units, 10);
	while (units != 56)
	{
		critic(&units);
	}
	printf("You must have looked up!\n");

	getchar();
	getchar();
	return 0;
}

void critic(int * ptr)
{
	//��������˿�ѡ�Ķ�������
	printf("No luck, chumy.Try again!\n");
	scanf_s("%d", ptr, 10);
}
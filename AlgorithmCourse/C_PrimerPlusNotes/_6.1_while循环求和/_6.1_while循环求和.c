#include <stdio.h>

int main(void)
{
	//�����û���������ֵĺ�
	long num, sum = 0L;		//��ʼ��longֵΪ0�������
	int status;				//��ʼ��scanf()�ķ���ֵ�����ɹ�ɨ���������Ŀ��

	printf("Please enter an integer to be sumed");
	printf("����q��to quit��:");
	status = scanf_s("%ld", &num,10);
	while (status == 1)		//ȷʵ����һ����ʱ������ѭ��
	{
		sum = sum + num;
		printf("Please enter next number to sum: ");
		status = scanf_s("%ld", &num);
	}
	printf("Those integers sum to %ld.\n", sum);
	getchar();
	getchar();
	getchar();
	return 0;
}
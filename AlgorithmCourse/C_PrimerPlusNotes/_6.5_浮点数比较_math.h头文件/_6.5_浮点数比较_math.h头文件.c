#include <stdio.h>
#include <math.h>

int main(void)
{
	const double ANSWER = 3.14159;
	double responce;

	printf("What is the value of pi?\n");
	scanf_s("%lf", &responce, 6);
	while (fabs(responce - ANSWER) > 0.0001)//�����û�����ֵ�������0.0001��ʱ��Ϊ��ȷ
	{
		printf("Try again!\n");
		scanf_s("%lf", &responce, 6);
	}
	printf("Close enough!\n");
	getchar();
	getchar();
	getchar();
	return 0;
}
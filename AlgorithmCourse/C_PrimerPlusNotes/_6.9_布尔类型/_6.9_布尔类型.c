#include <stdio.h>

int main(void)
{
	//�����û���������ֵĺ�
	long num, sum = 0L;		//��ʼ��longֵΪ0�������
	_Bool input_is_good;

	printf("Please enter an integer to be sumed");
	printf("����q��to quit��:");
	input_is_good = scanf_s("%ld", &num, 10);
	while (input_is_good)
	{
		sum = sum + num;
		printf("Please enter next number to sum: ");
		input_is_good = (1 == scanf_s("%ld", &num));/*��ʾ�û��������루�����ֱ�ʾֹͣ��*/
	}
	printf("Those integers sum to %ld.\n", sum);

	getchar();
	getchar();
	getchar();
	return 0;
}
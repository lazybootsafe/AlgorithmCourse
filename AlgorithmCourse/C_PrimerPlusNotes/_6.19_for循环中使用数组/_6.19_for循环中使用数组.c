#include <stdio.h>
#define SIZE 10		//10������
#define PAR 72		//��׼��

int main(void)
{
	//����10���߶��������������ͣ�ƽ���֣���ֵ��ƽ�������׼ֵ�Ĳ
	int score[SIZE];
	int sum = 0;
	float average;

	printf("Please enter %d golf scores: \n", SIZE);
	for (int i = 0; i < SIZE; i++)
		scanf_s("%d", &score[i]);		//��ȡ10������
	printf("The scores read in are as follows: \n");
	for (int i = 0; i < SIZE; i++)
		printf("%d,", score[i]);		//��֤����
	printf("\b \n");
	for (int i = 0; i < SIZE; i++)
		sum += score[i];				//���
	average = (float)sum / SIZE;
	printf("The sum of scores: %d, average = %.2f\n", sum, average);
	printf("That's a handicap of %.2f", average - PAR);

	getchar();
	getchar();
	return 0;

}
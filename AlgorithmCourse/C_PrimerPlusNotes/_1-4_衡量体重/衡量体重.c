#include <stdio.h>
int main(void)
{
	float weight,value;

	printf("Are you worth your weight in rhodium?\n");
	printf("Let's check it out.\n");
	printf("Please enter your weight in pounds��");
	/*ɨ���û�����*/
	scanf_s("%f", &weight);
	/*������Ϊÿ��˾770��Ԫ*/
	value = weight * 14.5833 * 770;
	printf("Your weight in rhodium is worth $%.2f\n",value);
	getchar();
	getchar();
	return 0;
}
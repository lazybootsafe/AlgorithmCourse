#include <stdio.h>
#include <stdbool.h>

int get_int(void);
bool bad_limits(int begin, int end, int low, int high);
double sum_squares(int a, int b);

int main(void)
{
	const int MIN = -1000;		//��Χ�½���Сֵ
	const int MAX = +1000;		//��Χ�Ͻ����ֵ
	int start;					//��Χ�½�
	int stop;					//��Χ�Ͻ�
	double answer;
	
	printf("This program compute the sum of the squares of "
		"integers in a range.\nThe lower bound should not "
		"be less than %+d and\nthe upper bound should not "
		"be more than %+d.\nEnter  the limits (enter 0 for"
		"both limits to quit):\nlower limit: ", MIN, MAX);
	start = get_int();
	printf("upper limit: ");
	stop = get_int();
	while (start != 0 || stop != 0)		//����������½粻��Ϊ0ʱ
	{
		if (bad_limits(start, stop, MIN, MAX))
		{
			printf("Please try again!\n");
		}
		else
		{
			answer = sum_squares(start, stop);
			printf("The sum of the squares of the integers from ");
			printf("%d to %d is %g\n", start, stop, answer);
		}
		printf("Enter the limits (enter 0 for both limits to quit): \n");
		printf("lower limit: ");
		start = get_int();
		printf("upper limit: ");
		stop = get_int();
	}
	printf("Done!\n");

	getchar();
	getchar();
	return 0;

}

//ȷ������һ������
int get_int(void)
{
	int input;
	char ch;

	while (scanf_s("%d", &input) == 0)
	{
		while ((ch = getchar()) != '\n')
		{
			putchar(ch);		//�޳����������
		}
		printf(" is not an integer.\nPlease enter an ");
		printf("integer value, such as 25, -178 or 3: ");
	}

	return input;
}

//ȷ�Ϸ�Χ�����½��Ƿ���Ч
bool bad_limits(int begin, int end, int low, int high)
{
	bool not_good = false;  //��Ч

	if (begin > end)
	{
		printf("%d isn't smaller than %d", begin, end);
		not_good = true;	
	}
	if (begin < low || end < low)
	{
		printf("Values must be %d or greater.\n", low);
		not_good = true;
	}
	if (begin > high || end > high)
	{
		printf("Values must be %d or less.\n", high);
		not_good = true;
	}

	return not_good;
}

//����a��b֮������������ƽ����
double sum_squares(int a, int b)
{
	double total = 0;

	for (int i = a; i <= b; i++)
	{
		total += i*i;
	}

	return total;
}
#if 0

#include <stdio.h>

int main(void)
{
	int odd_sum = 0;		//奇数总和
	int even_sum = 0;		//偶数总和
	int odd_count = 0;		//奇数总个数
	int even_count = 0;		//偶数总个数
	int input = 0;

	while (scanf_s("%d", &input))
	{
		if (input == 0)
			break;
		if (input % 2 == 0)
		{
			even_sum += input;
			even_count++;
		}
		else
		{
			odd_sum += input;
			odd_count++;
		}
		
	}
	printf("Have %d even number, average is %g\n", even_count, 1.0*even_sum / even_count);
	printf("Have %d odd number, average is %g\n", odd_count, 1.0*odd_sum / odd_count);
	printf("\n");

	return 0;
}

#endif
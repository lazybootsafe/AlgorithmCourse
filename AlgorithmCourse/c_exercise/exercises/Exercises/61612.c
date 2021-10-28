#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int size;
	double sum = 0;
	printf("请输入限制次数：");
	scanf_s("%d", &size);
	while (size > 0)
	{
		sum = 0;
		for (int i = 1; i <= size; i++)
		{
			sum += 1.0 / i;
		}
		printf("1.0 + 1.0/2.0...1.0/%d.0之和：%lf\n", size, sum);

		sum = 0;
		for (int i = 1; i <= size; i++)
		{
			if (i % 2 == 0)
				sum -= 1.0 / i;
			else
				sum += 1.0 / i;
		}
		printf("1.0 - 1.0/2.0 + 1.0/3.0...1.0/%d 之和：%lf\n", size, sum);

		sum = 0;
		for (int i = 1; i <= size; i++)
		{
			if (i % 2 != 0)
				sum += 2 * 1.0 / i;
		}
		printf("只计算奇数项：%lf", sum);

		printf("\n请输入限制次数：");
		scanf_s("%d", &size);

	}
	return 0;
}

#endif
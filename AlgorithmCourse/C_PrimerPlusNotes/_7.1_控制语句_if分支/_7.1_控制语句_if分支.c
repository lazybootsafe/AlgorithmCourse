#include <stdio.h>

int main(void)
{
	//�����û������һϵ��ÿ������¶ȣ�����������������Լ�����¶ȵ������������ռ�İٷ���

	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;

	printf("Enter the list of daily low temperatures\n");
	printf("Use Celsius, and enter q to quit.\n");
	while (scanf_s("%f", &temperature) == 1)
	{
		all_days++;
		if (temperature < FREEZING)
		{
			cold_days++;
		}
	}
	if (all_days != 0)
	{
		printf("%d days total: %.1f%% were below freezing.\n",
			all_days, 100.0 * cold_days / all_days);
	}
	if (all_days = 0)	//ʹ��esle�ؼ��֣���if else�ṹ���Լ����жϴ���
	{
		printf("You have no entered any letters!\n");
	}

	getchar();
	getchar();
	getchar();
	return 0;

	/*const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;

	printf("Enter the list of daily low temperatures\n");
	printf("Use Celsius, and enter q to quit.\n");
	while (scanf_s("%f", &temperature) == 1)
	{
		all_days++;
		if (temperature < FREEZING)
		{
			cold_days++;
		}
	}
	if (all_days != 0)
	{
		printf("%d days total: %.1f%% were below freezing.\n",
			all_days, 100.0 * cold_days / all_days);
	}
	else (all_days = 0��
	{
		printf("You have no entered any letters!\n");
	}

	getchar();
	getchar();
	getchar();
	return 0;*/
}
#if 0
#include <stdio.h>
#include <stdlib.h>

#define DAY_TO_WEEK 7

int main(void)
{
	int temp;
	int day;
	int week;
	printf("Enter the number of days(<= 0 to quit): ");
	scanf_s("%d", &temp);
	while (0 < temp)
	{
		week = temp / DAY_TO_WEEK;
		day = temp % DAY_TO_WEEK;
		printf("%d days are %d weeks, %d days\n", temp, week, day);
		printf("Please input the number of days(<= 0 to quit): ");
		scanf_s("%d", &temp);
	}

	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

#define MINUTE_TO_HOUR 60

int main(void)
{
	int hour = 0;
	int minute = 0;
	int temp = 0;
	printf("This program is convert minutes to hours.\n");
	printf("Enter the number of minutes(less than ro equal to 0 to quit): ");
	scanf_s("%d", &temp);
	while (temp > 0)
	{
		hour = temp / MINUTE_TO_HOUR;
		minute = temp % MINUTE_TO_HOUR;
		printf("Convert to %d hour and %d minutes.\n", hour, minute);
		printf("Please input the number of minutes(<= 0 to quit): ");
		scanf_s("%d", &temp);
	}

	return 0;
}

#endif
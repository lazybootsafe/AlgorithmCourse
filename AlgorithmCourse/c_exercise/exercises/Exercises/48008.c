#if 0
#include <stdio.h>
#include <stdlib.h>

#define GALLON_TO_LITER 3.785f
#define      MILE_TO_KM 1.609f

int main(void)
{
	float range;
	float oil;
	printf("Enter the range you traveled: ");
	scanf_s("%f", &range);
	printf("Enter the oil you spend: ");
	scanf_s("%f", &oil);
	printf("In USA %.2f M/G\n", range / oil);
	printf("In Europe %.2f L/100KM\n", (oil*GALLON_TO_LITER) / (range*MILE_TO_KM));

	return 0;
}

#endif
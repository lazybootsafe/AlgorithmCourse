#if 0
#include <stdio.h>
#include <stdlib.h>

#define FEET_TO_CM 30.48f
#define INCH_TO_CM 2.54f

int main(void)
{
	int feet;
	float inch;
	float cm;
	printf("Enter a height in centimeters: ");
	scanf_s("%f", &cm);
	while (0 < cm)
	{
		feet = cm / FEET_TO_CM;
		inch = (cm - (feet*FEET_TO_CM)) / INCH_TO_CM;
		printf("%.1f cm = %d feet, %.1f inches\n", cm, feet, inch);
		printf("Enter a height in centimeters (<= 0 to quit): ");
		scanf_s("%f", &cm);
	}
	printf("bye\n");

	return 0;
}

#endif
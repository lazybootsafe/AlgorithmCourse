#if 0
#include <stdio.h>
#include <stdlib.h>

#define INCH_TO_CM 2.54f

int main(void)
{
	float inch;
	float cm;
	printf("Enter the inch of your height: ");
	scanf_s("%f", &inch);
	cm = inch * INCH_TO_CM;
	printf("Your height is %.2f cm.\n", cm);

	return 0;
}

#endif
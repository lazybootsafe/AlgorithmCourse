#if 0
#include <stdio.h>
#include <stdlib.h>

#define INCHTOCM 2.54f

int main(void)
{
	float inch = 0;
	printf("Enter inch. The program converts inches to centimeters.\n");
	scanf_s("%f", &inch);
	printf("%.2f inch to %.2f cm", inch, (inch*INCHTOCM));

	return 0;
}

#endif
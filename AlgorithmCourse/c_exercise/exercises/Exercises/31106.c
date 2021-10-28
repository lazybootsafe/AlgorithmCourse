#if 0
#include <stdio.h>
#include <stdlib.h>

#define MOLECULE_TO_MASS 3.0e-23f
#define     QUART_TO_MAS 950

int main(void)
{
	float quart, quantity;
	printf("Enter how many quart: ");
	scanf_s("%f", &quart);
	quantity = quart * QUART_TO_MAS / MOLECULE_TO_MASS;
	printf("There are %e molecule.\n", quantity);

	return 0;
}

#endif
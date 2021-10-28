#if 0
#include <stdio.h>
#include <stdlib.h>

#define    PINT_CUP 2
#define   CUP_OUNCE 8
#define OUNCE_SPOON 2
#define   SPOON_TEA 3

int main(void)
{
	float pint;
	float cup;
	float ounce;
	float spoon;
	float tea_spoon;

	printf("Enter how many cup: ");
	scanf_s("%f", &cup);
	pint      =   cup / PINT_CUP;
	ounce     =   cup * CUP_OUNCE;
	spoon     = ounce * OUNCE_SPOON;
	tea_spoon = spoon * SPOON_TEA;

	printf("%.0f cup equals %.1f pint, %.1f ounce, %.1f spoon, %.1f tea spoon.\n", cup, pint, ounce, spoon, tea_spoon);

	return 0;
}

#endif
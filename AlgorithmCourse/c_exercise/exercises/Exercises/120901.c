#if 0
#include <stdio.h>
#include <stdlib.h>

void critic(int * n);
//int critic(void);

int main(void)
{
	int units;
	printf("How many pounds to a firkin of butter?\n");
	scanf_s("%d", &units);
	while (units != 56)
		critic(&units);
		//units = critic();
	printf("You must have looked it up!\n");

	return 0;
}

void critic(int * n)
{
	printf("No luck, my friend. Try again.\n");
	scanf_s("%d", n);
}

//int critic(void)
//{
//	int units;
//	printf("No luck, my friend. Try again.\n");
//	scanf_s("%d", &units);
//	return units;
//}

#endif
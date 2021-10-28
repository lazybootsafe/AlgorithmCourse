#if 0
#include <stdio.h>
#include "pe12-3a.h"

int main(void)
{
	int mode;
	double distance, fuel;
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf_s("%d", &mode);
	while (mode >= 0)
	{
		set_mode3a(&mode);
		get_info3a(mode, &distance, &fuel);
		show_info3a(mode, distance, fuel);
		getchar();
		printf("Enter 0 for metric mode, 1 for US mode: ");
		printf(" (-1 to quit): ");
		scanf_s("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}

#endif
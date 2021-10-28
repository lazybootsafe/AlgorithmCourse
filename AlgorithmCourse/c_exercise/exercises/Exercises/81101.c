#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count = 0;
	char c;
	puts("Enter Ctrl + Z end the input.");
	while ((c = getchar()) != EOF)
	{
		count++;
	}
	printf("The file has %d characters.\n", count);
	puts("Done!");
	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char name[20];
	char surname[20];
	int width1;
	int width2;
	printf("Enter your first name:");
	scanf_s("%s", &name, 19);
	printf("Enter your last name:");
	scanf_s("%s", &surname, 19);
	width1 = printf("%s ", name) - 1;
	width2 = printf("%s", surname);
	printf("\n%*d %*d", width1, width1, width2, width2);

	return 0;
}

#endif
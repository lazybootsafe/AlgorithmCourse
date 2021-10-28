#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char surname[20];
	char name[20];
	printf("Enter your first name: ");
	scanf_s("%s", &name, 19);
	printf("Enter your last name: ");
	scanf_s("%s", &surname, 19);
	printf("Hello, %s-%s", name, surname);

	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

#define YEAR_TO_SEC (3.156e7)

int main(void)
{
	int second, year;
	printf("Enter your age: ");
	scanf_s("%d", &year);
	second = year * YEAR_TO_SEC;
	printf("Your age is: %d years old.\n", year);
	printf("And you are %e second old.\n", second);

	return 0;
}

#endif
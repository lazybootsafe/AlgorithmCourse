#if 0
#include <stdio.h>

#define AGETODAY 365

int main(void)
{
	int age = 0;
	printf("Enter your age: ");
	scanf_s("%d", &age);
	printf("Your age is %d years old. You spent %d day.\n", age, (age*AGETODAY));

	return 0;
}

#endif
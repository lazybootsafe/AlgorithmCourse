#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float speed;
	float size;
	float time;

	printf("Enter the net speed: ");
	scanf_s("%f", &speed);
	printf("Enter the file size: ");
	scanf_s("%f", &size);
	time = size * 8 / speed;
	printf("At %.2f megabits per second, a file of %.2f megabytes download in %.2f second.", speed, size, time);


	return 0;
}

#endif
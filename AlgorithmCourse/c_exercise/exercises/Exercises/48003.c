#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float num;
	printf("Enter a float number: ");
	scanf_s("%f", &num);
	//输出格式取決於編譯器和操作系統
	printf("The input number is %.1f or %.1e\n", num, num);
	printf("The input number is %.3f or %.3e\n", num, num);

	return 0;
}

#endif
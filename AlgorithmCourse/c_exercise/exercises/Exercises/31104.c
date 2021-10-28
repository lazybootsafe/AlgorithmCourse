#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float num;
	printf("Enter a floating point value:");
	scanf_s("%f", &num);
	//打印一般形式
	printf("fixed point notation: %f\n", num);
	//打印科学记数法形式
	printf("exponential notation: %e\n", num);
	//打印十六进制记数法形式(根据系统和编译器打印可能跟书上不一致)
	printf("p notation: %a\n", num);

	return 0;
}

#endif
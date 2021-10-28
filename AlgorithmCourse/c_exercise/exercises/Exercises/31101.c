#if 0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>		//整型数据类型上下限头文件(char/int/long等)
#include <float.h>		//浮点型数据类型上下限头文件(float/double/long double)

int main(void)
{
	int      int_max = 2147483647;			//有符号整型最大值对应宏INT_MAX
	float  float_max = 3.402823466e+38F;	//float的最大值对应宏FLT_MAX
	float  float_min = 10.0f / 3;			//用一个除不尽的数查看float的有效位数
	
	printf("最大有符号int整型加1后：%d\n", int_max + 1);
	//inf是溢出表示方式
	printf("最大float浮点值乘10后：%f\n", float_max * 10);
	printf("打印10除3看float输出的有效位数：%f\n", float_min);

	return 0;
}

#endif
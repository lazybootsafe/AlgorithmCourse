#if 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	double base = 0.0;
	int index = 0;
	double result = 1.0;
	base = atof(argv[1]);
	index = atoi(argv[2]);
	//for (int i = 0; i < index; i++)
	//	result *= base;
	result = pow(base, index);
	printf("The %g's %d power is %g\n", base, index, result);
	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(void)
{
	float fnum = 1.0f / 3.0f;
	double dnum = 1.0 / 3.0;
	printf("float of one number(6)   = %.6f\n", fnum);
	printf("float of one number(12)  = %.12f\n", fnum);
	printf("float of one number(16)  = %.16f\n", fnum);
	printf("double of one number(6)  = %.6lf\n", dnum);
	printf("double of one number(12) = %.12lf\n", dnum);
	printf("double of one number(16) = %.16lf\n", dnum);
	printf("FLT_DIG in float.h is %d\n", FLT_DIG);
	printf("DBL_DIG in float.h is %d\n", DBL_DIG);

	return 0;
}

#endif
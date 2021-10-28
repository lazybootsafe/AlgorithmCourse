#if 0
#include <stdio.h>
#include <stdlib.h>

void fun(void);

int main(void)
{
	for (int i = 0; i < 10; i++)
		fun();
	return 0;
}

void fun(void)
{
	static int callback = 0;
	printf("The function call %d times.\n", ++callback);
}

#endif
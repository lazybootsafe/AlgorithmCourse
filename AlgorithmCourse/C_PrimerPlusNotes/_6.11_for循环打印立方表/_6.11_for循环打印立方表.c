#include <stdio.h>

int main(void)
{
	//��ӡ1-5������ֵ
	printf("    n n-cubed\n");
	for (int i = 0; i <= 6; i++)
	{
		printf("%5d %5d\n", i, i*i*i);
	}

	getchar();
	return 0;
}
#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float lucky = 100.0f;
	int year = 0;
	lucky += lucky * 0.08f;
	lucky -= 10.0f;
	for (year = 1; lucky > 10.0f; year++)
	{
		lucky += lucky * 0.08f;
		lucky -= 10.0f;
	}
	//do
	//{
	//	lucky += lucky * 0.08f;
	//	lucky -= 10.0f;
	//	year++;
	//	printf("%f\n", lucky);
	//} while (lucky > 9.0f);
	printf("%d 年后拿完账户上所有的钱。\n", year);

	return 0;
}

#endif
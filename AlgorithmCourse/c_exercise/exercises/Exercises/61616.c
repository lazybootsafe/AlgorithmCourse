#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float daphne = 100.0f;
	float deirdre = 100.0f;
	int year = 0;
	daphne += 100.0f*0.1f;
	deirdre += deirdre * 0.05f;
	for (year = 1; deirdre < daphne; year++)
	{
		daphne += 100.0f*0.1f;
		deirdre += deirdre * 0.05f;
	}
	printf("%d", year);

	return 0;
}

#endif
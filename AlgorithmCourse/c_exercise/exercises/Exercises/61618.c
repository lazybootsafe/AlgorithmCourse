#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int rabnud;
	int weeks;
	for (weeks = 1, rabnud = 5; rabnud < 150; weeks++)
	{
		printf("�� %d �ܣ�Rabnud �� %d λ����\n", weeks, rabnud);
		rabnud = 2 * (rabnud - weeks);
	}
	//rabnud = 5;
	//weeks = 1;
	//while (rabnud < 150)
	//{
	//	printf("�� %d �ܣ�Rabnud �� %d λ����\n", weeks, rabnud);
	//	rabnud = 2 * (rabnud - weeks++);
	//}

	return 0;
}

#endif
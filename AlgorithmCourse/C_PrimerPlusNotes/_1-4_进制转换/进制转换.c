#include <stdio.h>

int main(void)
{
	int cm, n, m;
	cm = 100;
	n = 1;
	m = 1;

	printf("%d����%d����\n", m, cm);
	printf("%d����%d����\n", m, n*cm);
	printf("%d����%d����\n", 5 * m, 5 * cm);

	getchar();
	return 0;

}
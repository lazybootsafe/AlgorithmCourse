#include <stdio.h>

int main(void)
{
	int a = 1, b = 1;
	int aplus, plusb;

	aplus = a++; /*��׺,aplus������a�ı�֮ǰ��ֵ*/
	plusb = ++b; /*ǰ׺,plusb������b�ı�֮���ֵ*/
	printf("a aplus b plusb \n");
	printf("%1d %3d %3d %3d\n", a, aplus, b, plusb);
	getchar();
	return 0;
}
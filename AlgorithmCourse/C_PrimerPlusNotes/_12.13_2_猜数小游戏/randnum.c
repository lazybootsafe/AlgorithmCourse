//randnum.c

#include <stdlib.h>			//Ϊrand()�ṩԭ��

int randnum(int max)
{
	unsigned num;
	 
	num = rand() % max;

	return num;
}
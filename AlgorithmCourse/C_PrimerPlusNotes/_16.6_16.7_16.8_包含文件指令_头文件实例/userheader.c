#include <stdio.h>
#include "names.h"		//��Ҫnames�ṹģ��
//��ס����names_st.c�ļ�

int main(void)
{
	names candidate;

	get_names(&candidate);
	printf("Let's welcome ");
	show_names(&candidate);
	printf(" to this program!\n");

	getchar();
	return 0;
}
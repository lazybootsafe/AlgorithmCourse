#include <stdio.h>

int main(void)
{
	//printf�ķ���ֵ
	int bph2o = 100;
	int rv;

	rv = printf("%d ��C is water's bolling point.\n",bph2o);//printf�ķ���ֵ������ӡ��Χ�ڵ������ַ������������ɽ��ַ���
	printf("This printf function printed %d characters.\n", rv);

	getchar();
	return 0;
}
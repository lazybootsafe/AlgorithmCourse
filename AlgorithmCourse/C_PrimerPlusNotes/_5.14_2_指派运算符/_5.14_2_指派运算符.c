#include <stdio.h>

int main(void)
{
	//ʹ�ã�type������ֱ��ת���������ͣ�ָ���������
	float fl_1 = 1.6, fl_2 = 1.7;
	int a;
	
	a = fl_1 + fl_2;
	printf("a=%d\n", a);
	a = (int)fl_1 + (int)fl_2;
	printf("a=%d\n", a);
	getchar();
	return 0;
}
#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float num;
	printf("Enter a floating point value:");
	scanf_s("%f", &num);
	//��ӡһ����ʽ
	printf("fixed point notation: %f\n", num);
	//��ӡ��ѧ��������ʽ
	printf("exponential notation: %e\n", num);
	//��ӡʮ�����Ƽ�������ʽ(����ϵͳ�ͱ�������ӡ���ܸ����ϲ�һ��)
	printf("p notation: %a\n", num);

	return 0;
}

#endif
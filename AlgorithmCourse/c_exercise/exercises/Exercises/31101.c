#if 0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>		//������������������ͷ�ļ�(char/int/long��)
#include <float.h>		//��������������������ͷ�ļ�(float/double/long double)

int main(void)
{
	int      int_max = 2147483647;			//�з����������ֵ��Ӧ��INT_MAX
	float  float_max = 3.402823466e+38F;	//float�����ֵ��Ӧ��FLT_MAX
	float  float_min = 10.0f / 3;			//��һ�������������鿴float����Чλ��
	
	printf("����з���int���ͼ�1��%d\n", int_max + 1);
	//inf�������ʾ��ʽ
	printf("���float����ֵ��10��%f\n", float_max * 10);
	printf("��ӡ10��3��float�������Чλ����%f\n", float_min);

	return 0;
}

#endif
#include <stdio.h>

int main(void)
{
	int i_a = 1;
	int i_b = 2;
	float f_c = 1.4f;

	printf("%d %d\n", i_a);		//����̫��
	printf("%d\n", i_b, i_b);		//����̫��
	printf("%f %d\n", i_b, f_c);		//��ʽ˵������ƥ�䣬��%d��ʾfloatֵ����ת��Ϊ���Ƶ�intֵ����ʾ����ֵ;(%f��ʾintֵͬ��),�������

	getchar();
	return 0;
}

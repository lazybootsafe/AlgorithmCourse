#include <stdio.h>
#include <limits.h>  //��������
#include <float.h>  //С������

int main(void)
{
	printf("���������С���Ĵ�С���ơ��\n\n");
	printf("������_���ֵ == %d\n\n", INT_MAX);
	printf("�޷��ų�����_��Сֵ == %lld������ == %d�ֽ�\n\n", LLONG_MIN, sizeof(long));
	printf("1�ֽ� == %dλ\n\n", CHAR_BIT);
	printf("˫����С��_���ֵ == %e\n\n", DBL_MAX);
	printf("������_��Сֵ == %e\n\n", FLT_MIN);
	printf("������_���� == %d\n\n", FLT_DIG);
	printf("˫���ȸ�����_���� == %d\n\n", DBL_DIG);
	printf("���������������鿴ͷ�ļ����\n\n");

	getchar();
	return 0;

}

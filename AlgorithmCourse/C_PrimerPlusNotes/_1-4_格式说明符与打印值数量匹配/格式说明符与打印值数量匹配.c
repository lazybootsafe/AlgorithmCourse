#include <stdio.h>
int main(void)
{
	int ten;
	int two;
	ten = 10;
	two = 2;

	printf("Doing it right:");
	printf("%d minus %d is %d.\n",ten,2,ten-two);
	printf("Doing it wrong:");
	printf("%d minus %d is %d.\n", ten);
	getchar();
	return 0;
	//��ʽ˵����������Ҫ��ӡֵ������ƥ�䣬�����и�ʽ˵������û���ṩ��ӡֵ��λ�û��ɱ��������ڴ���������ȡһ��ֵ���
}
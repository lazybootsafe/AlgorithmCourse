#include <stdio.h>
int main(void)
{
	int i = 2147483647;		//int������ȡֵ��Χ(-2147483648,2147483647)
	unsigned int j = 4294967295;		//unsigned int������ȡֵ��Χ(0, 4294967295)

	printf("%d %d %d\n", i, i + 1, i + 2);		//i+1�������Сֵ-2147483638
	printf("%u %u %u\n", j, j + 1, j + 2);		//j+1�������Сֵ0

	printf("\n��ܰ��ʾ��\n���������%d�ֽڴ��int����",sizeof(int));
	printf("��1�ֽ�ռ8λ");
	printf("������unsigned int���͵�32�޷������������ֵ��1111 1111 1111 1111 1111 1111 1111 1111����ʮ���Ƶ�4294967295");
	getchar();
	return 0;

}
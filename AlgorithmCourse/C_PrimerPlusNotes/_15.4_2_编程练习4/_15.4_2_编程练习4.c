/*
	��дһ���������ú�������2��int������1��ֵ��1��λ��λ�ã����ָ��λ�ϵ�ֵΪ1���򷵻�1�����򷵻�0
	�ڳ����в��Ըú�����*/

#include <stdio.h>
#include <stdlib.h>

int get_bit(int n, int bitindex);

int main(void)
{
	int num = 73, bitindex = 6, bit;

	system("color 5A");
	bit = get_bit(num, bitindex);
	printf("The %d's bit-%d: %d\n", num, bitindex, bit);

	getchar();
	return 0;
}

int get_bit(int n, int bitindex)
{
	n >>= bitindex;			//��ָ��λ��ֵ�Ƶ�λ0
	n &= 01;				//��01������ȡ��λ0

	return n;
}
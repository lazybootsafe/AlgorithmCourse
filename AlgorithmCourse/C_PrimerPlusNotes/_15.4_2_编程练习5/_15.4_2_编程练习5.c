/*
	��дһ���������ú�����һ��unsigned int�е�����λ������תָ��������λ������
	rotate_l(x,4)��x�е�����λ�����ƶ�4��λ�ã����Ҵ���˶�ʧ��λ�����³�����
	���Ҷˡ�Ҳ����˵���ѴӸ�λ�Ƴ���λ�����λ���ڳ����в��Ըú�����*/

#include <stdio.h>
#include <stdlib.h>

unsigned int rotate_l(unsigned int n, int bits);

int main(void)
{
	unsigned int num = 73, bits = 3,a;

	system("color 5A");
	printf("The %u after rotating is %u\n", num, a=rotate_l(num, bits));

	getchar();
	return 0;
}

unsigned int rotate_l(unsigned int n, int bits)
{
	unsigned int i = 0, end;

	while (i++ < bits)
	{
		end = (n & 01);			//ȡ��λ0
		n >>= 1;				//ע��n���޷���������������ʱ�ճ���λ��0���
		end <<= 8 * sizeof(int)-1;
		n |= end;				//д��λ31�����end���λֵ��1����򿪶�Ӧ��n��λ�����򲻱䣩
	}

	return n;
}
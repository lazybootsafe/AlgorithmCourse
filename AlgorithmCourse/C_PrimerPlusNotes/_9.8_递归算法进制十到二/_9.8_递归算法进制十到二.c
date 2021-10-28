#include <stdio.h>

void to_binary(unsigned long dec);
void to_octonary(unsigned long dec);
void to_hexadecimal(unsigned long dec);

int main(void)
{
	unsigned long dec;

	printf("Enter an integer (q to quit): \n");
	while (scanf_s("%ul", &dec) == 1)
	{
		printf("Binary equivalent: ");
		to_binary(dec);
		printf("\nOctonary equivalent: ");
		to_octonary(dec);
		printf("\nEnter an integer (q to quit): \n");
	}
	printf("Done!\n");

	return 0;

}

void to_binary(unsigned long dec)
{
	unsigned long result = dec % 2;		//��2����

	if (dec >= 2)
		to_binary(dec / 2);				//�������������2���������ã���2����
	putchar(result ? '1' : '0');		//��ӡ��������Ϊ�ڵݹ����֮�����������һ��������ϲſ�ʼ��ӡ���һ������1��0��Ȼ���𼶷��أ���ӡ������2����������3����......����1����ʵ���˳�2ȡ�࣬����д�����㷨���õ�2��������
}

void to_octonary(unsigned long dec)
{
	unsigned long result = dec % 8;

	if (dec >= 8)
		to_octonary(dec / 8);
	printf("%u", result);		
}
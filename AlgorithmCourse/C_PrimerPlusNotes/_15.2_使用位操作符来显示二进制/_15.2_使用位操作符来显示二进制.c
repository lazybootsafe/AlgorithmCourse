#include <stdio.h>
#include <stdlib.h>

char * itobs(int n, char * ps);				//д��������ַ���
void show_bstr(char * str);
int invert_end(int num, int bits);			//ת��num�����bitsλ

int main(void)
{
	char bin_str[8 * sizeof(int)+1];
	int number;

	system("color 0A");
	puts("Enter integers and see them in binary:");
	puts("Non-number input terminate program:");
	while (scanf_s("%d", &number, 10) == 1)
	{
		itobs(number, bin_str);
		printf("%d is \n", number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number, 4);
		printf("Inverting the last 4 bits gives:\n");
		show_bstr(itobs(number, bin_str));
		putchar('\n');
	}
	puts("Bye.");

	system("pause");
	return 0;
}

char * itobs(int n, char * ps)
{
	static int size = 8 * sizeof(int);
	 
	//����Ԫ�شӵ����ڶ�����ʼ�����������ƶ���n���������ƶ�һλ��n&01����ȡ��n�����һλ����'0'ת�����ַ������δӺ���ǰ�������
	for (int i = size - 1; i >= 0; i--, n >>= 1)
	{
		ps[i] = (n & 01) + '0';
	}
	ps[size] = '\0';

	return ps;
}

void show_bstr(char * str)
{
	int i = 0;

	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
		{
			putchar(' ');
		}
	}
}

int invert_end(int num, int bits)
{
	int mask = 0;
	int bitval = 1;
				
	while (bits-- > 0)		//ѭ��n�δ���������nλ
	{
		mask |= bitval;
		bitval <<= 1;
	}

	return num^mask;		//ת��num�����nλ
}
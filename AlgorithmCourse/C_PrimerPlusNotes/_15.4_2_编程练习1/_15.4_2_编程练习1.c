/*
	��дһ�����������ַ���ת��Ϊ����ֵ�ĺ�����Ҳ����˵�������������䣺
	char * pbin = "01001001";
	��ô���Խ�pbin��Ϊ�������ݸ�һ��������ʹ�ú�������һ��intֵ25*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tonumber(char * pbin);

int main(void)
{
	char * pbin = "01001001";
	int n;

	n = tonumber(pbin);	
	system("color 5A");
	printf("The \"%s\"'s value is %u.\n", pbin, n);

	getchar();
	return 0;
}

int tonumber(char * pbin)
{
	unsigned int bin = 0, size = strlen(pbin);

	for (unsigned int i = 0; i < size; i++)
	{
		bin &= ~01;					//λ0����
		bin |= *(pbin + i) - '0';	//д��λ0
		bin <<= 1;					//����1λ
	}
	bin >>= 1;						//д�����һλ֮�����������1λ�����������ƶ�һλ���ַ���ת��Ϊ������λ

	bin >>= 3;
	bin |= 0x10;					//��λ4

	return bin;
}
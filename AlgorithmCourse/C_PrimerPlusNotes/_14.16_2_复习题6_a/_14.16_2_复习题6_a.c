
//�������µ�typedef������һ��10��Ԫ�ص�ָ���ṹ�����顣
//Ȼ��ͨ��������Ա��ֵ����ȼ��ַ�������ʹ��3��Ԫ������һ�����೤��Ϊ500mm���׾�Ϊf/2.0��Remarkatar��ͷ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct lens			//��ͷ����
{
	float foclen;			//���೤�ȣ���mmΪ��λ
	float fstop;			//�׾�
	char brand[30];			//Ʒ������
} LENS;

int main(void)
{
	LENS bigeye[SIZE];

	bigeye[2].foclen = 500.0f;
	bigeye[2].fstop = 2.0f;
	//bigeye[2].brand = "Remarkatar";
	strcpy_s(bigeye[2].brand, 30, "Remarkatar");

	printf("Foclen: %.2f\n", bigeye[2].foclen);
	printf("Fstop: %.2f\n", bigeye[2].fstop);
	printf("Brand: %s\n", bigeye[2].brand);

	getchar();
	return 0;
}
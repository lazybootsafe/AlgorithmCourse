
//�������µ�typedef������һ��10��Ԫ�ص�ָ���ṹ�����顣
//ʹ��ָ����ʼ����Ŀ�б�ʹ��3��Ԫ������һ�����೤��Ϊ500mm���׾�Ϊf/2.0��Remarkatar��ͷ

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
	LENS bigeye[SIZE] = { [2] = { 500.0f, 2.0f, "Remarkatar" } };		//ָ����ʼ����Ŀ

	printf("Foclen: %.2f\n", bigeye[2].foclen);
	printf("Fstop: %.2f\n", bigeye[2].fstop);
	printf("Brand: %s\n", bigeye[2].brand);

	getchar();
	return 0;
}
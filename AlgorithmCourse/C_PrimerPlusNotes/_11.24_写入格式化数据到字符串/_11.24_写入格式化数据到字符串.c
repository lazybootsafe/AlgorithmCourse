#include <stdio.h>

#define MAX 20

int main(void)
{

	/*sprintf_s()д���ʽ�����ݵ��ַ��������뱣֤Ŀ���ַ�����Դ�ַ���û��λ���ص���Ŀ���ַ����Ŀռ��㹻����Ԫ�ַ���
	  �ú������Խ�����������͵��ַ�����ʽ��д�뵽һ���ַ��������ڻ���������͵��ռ��洢*/

	char first[MAX];
	char last[MAX];
	char formal[2 * MAX + 10];
	double prize;

	puts("Enter your first name:");
	gets_s(first, MAX);
	puts("Enter your last name:");
	gets_s(last, MAX);
	puts("Enter your prize money:");
	scanf_s("%lf", &prize, 10);

	sprintf_s(formal, 2 * MAX + 10 , "%s, %-19s: $%6.2f", last, first, prize);		//��ʽ����ӡ���ݵ��ַ�����д���ʽ�����ݵ��ַ���
	puts(formal);

	getchar();		//��scanf_s()���µ�\n����
	getchar();
	return 0;
}
/*
	��#�����һ����##��������������ຯ������滻���֡���##������������������滻���֣�
	##�������2�����Է�����ϳɵ��������Է��š�*/

/*˵�˻����ǣ�
			   #��������԰Ѻ����ת�����ַ���
			  ##���������ճ�ϳ�һ���µı�ʶ��
			  
			  һ��#���Դ����ַ���������#���Դ�����ʶ��*/

#include <stdio.h>
#include <stdlib.h>

#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n)

int main(void)
{
	int XNAME(1) = 14;		//��Ϊ int x1 = 14;
	int XNAME(2) = 20;		//��Ϊ int x2 = 20;

	system("color 5A");

	PRINT_XN(1);			//��Ϊ printf("x1 = %d\n", x1);
	PRINT_XN(2);			//��Ϊ printf("x2 = %d\n", x2);

	getchar();
	return 0;
}
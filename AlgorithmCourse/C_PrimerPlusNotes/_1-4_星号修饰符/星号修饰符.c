#include <stdio.h>

int main(void)
{
	//��printf()��%*d��*ָʾ�ֶο�ȣ������û�ָ��Ҫ����ֶο�ȣ���Ҫ�ڸ�ʽ���ַ�������dһ���ṩһ������ָ���ֶο��
	//��scanf()��%*d,*ָʾ���������������Ŀ���˴����������һ���з�����
	unsigned  width, precision;//��ȣ�����
	int number = 256;
	double weight = 242.5;

	printf("What filed weight?\n");
	scanf_s("%d", &width,6);
	printf("The number is: %*d: \n", width, number);
	printf("Now enter a width and a precision: \n");
	scanf_s("%d %d", &width, &precision,20);
	printf("Weight = %*.*f\n", width, precision, weight);

	getchar();
	getchar();
	return 0;
}
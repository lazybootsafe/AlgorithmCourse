#include <stdio.h>
#include <math.h>

//ʹ�ÿɱ�����ĺ꣺ʵ��˼������ʡ�ԺŴ�������б��е����һ������

/*
��ʵ������ʾ�˿ɱ���Ӧ�ã�...��__VA_ARGS__
�Լ�#Ԥ������������ַ��������ӹ��ܡ���##Ԥ�������ӷ����ô������ˣ�*/

#define PR(x, ...) printf("Message " #x ": "__VA_ARGS__)

int main(void)
{
	double x = 48.0;
	double y;

	y = sqrt(x);

	PR(1, "x = %g\n", x);
	PR(2, "x = %.2f, y = %.4f\n", x, y);

	getchar();
	return 0;
}

//ʡ�Ժ�ֻ�ܴ������ĺ����������Ķ����Ǵ���ģ�
#define WRONG(x, ..., y) #x #__VA_ARGS__ #y

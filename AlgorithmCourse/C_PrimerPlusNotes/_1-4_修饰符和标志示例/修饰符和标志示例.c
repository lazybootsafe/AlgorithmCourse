#include <stdio.h>

#define PAGES 931
#define FLT 9.12345

int main(void)
{
	printf("*%d*\n\n", PAGES);
	printf("*%2d*\n\n", PAGES);    	//��ӡ�������Ϊ2
	printf("*%10d*\n\n", PAGES);   	//��ӡ�������Ϊ10�����λ�ÿո����
	printf("*%010d*\n\n", PAGES);  	//��ӡ�������Ϊ10�����λ��0���
	printf("*%-10d*\n\n", PAGES);  	//��ӡ�������Ϊ10�����������
	printf("*%+10d*\n\n\n", PAGES);	//��ӡ�������Ϊ10����������
	printf("*%6.4f*\n\n", FLT);	//��ӡ�������Ϊ 6����ȷ��С�����4λ
	
	getchar();
	return 0;
}
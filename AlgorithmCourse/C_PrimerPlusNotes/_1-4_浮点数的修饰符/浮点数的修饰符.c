#include <stdio.h>

int main(void)
{
	const double RENT = 3852.99;

	printf("*%f*\n\n", RENT);
	printf("*%e*\n\n", RENT);	//����e-��������ӡ������
	printf("*%4.2f*\n\n", RENT);//��ӡ4�ֽڳ�����ȷ2λС�������Ҫ��ӡ���ֿ�ȳ��������Զ����䵽���ֿ�ȣ������Ϊ4�ֽڳ�����ȷ2λС��
	printf("*%3.1f*\n\n", RENT);//��ӡ�������Ϊ3�ֽڣ���ȷ1λС��
	printf("*%10.3f*\n\n", RENT);//��ӡ�������Ϊ10�ֽڣ���ȷ3λС�������λ�ÿո����
	printf("*%010.3f*\n\n", RENT);//��ӡ�������Ϊ10�ֽڣ���ȷ3λС�������λ��0���
	printf("*%-10.3f*\n\n", RENT);//���������
	printf("*%+10.3f*\n\n", RENT);//��ʾ������

	getchar();
	return 0;
}
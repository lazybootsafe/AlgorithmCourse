#include <stdio.h>

void interchange(int * u, int * v);

int main(void)
{
	int x = 5, y = 10;

	printf("Originally x = %d and y = %d\n", x, y);
	interchange(&x, &y);	//��������x��y�ĵ�ַ -> ���������Ͷ����е��β�u,v��ʹ�õ�ַ��Ϊ���ǵ�ֵ����ˣ����Ǳ�����Ϊָ�룬ͨ����ָ����ʸñ���
	printf("Now x = %d and y = %d\n", x, y);

	getchar();
	return 0;
}

void interchange(int * u, int * v)	//����ָ��ָ��ı�����Ȼ��������ݵĽ���
{
	int temp;	//�ṩ��ʱ����

	temp = *u;		//temp�õ�uָ���ֵ��temp = x
	*u = *v;		//vָ���ֵ����uָ���ֵ,x = y
	*v = temp;		//uָ���ֵ����vָ���ֵ,y = temp
	/*ע�⣺��������ͨ���ڴ��ַ����ӵõ���ֵ
	 ����������Ӳ�����ֵʵ����ֵ�Ľ�����©���ᵼ���ڴ��ַ���뽻��*/
}
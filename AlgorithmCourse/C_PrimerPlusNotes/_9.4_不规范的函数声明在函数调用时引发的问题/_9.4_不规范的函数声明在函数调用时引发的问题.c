#include <stdio.h>
#include <stdlib.h>

//���淶�ĺ�������
int imax();		/*����ʡ�Բ�����������ò�Ҫʡ�Բ������������ͣ�
				���δ�����������������ͣ��������޷���麯������ʱ�����Ĵ������������ͣ�
				���ɵı���汾������������Ԥ֪�Ĵ���*/

int main(void)
{
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3));		/*���ݺ������壬��������ʱ��
							push 3
							call &imax
							imax()��ջ��ȡ��2��������
							��1������������ջ��3���ڶ�����ջ�е��������ݣ�
							*/
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3.0, 5.0));/*����doubleֵ����16�ֽ�128λ������ջ�У�
							  imax()��ջ��ȡ��2��intֵ����8�ֽ�64λ������ǰ64λASCIIֵ����Ϊ2��intֵ��
							  ����֪�����ϴ�ֵ����Ϊ1074266112*/

	getchar();
	return 0;
}

int imax(n, m)
int n, m;		//�����������ͣ�����ڶ���ͷ������ȫ��
{
	int max;

	if (n > m)
		max = n;
	else
		max = m;

	return max;
}
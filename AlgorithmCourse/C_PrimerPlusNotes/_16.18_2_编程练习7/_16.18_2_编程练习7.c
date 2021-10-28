/*
	������ʹ���˿ɱ亯���ĳ���Ƭ�Σ�
	#include <stdio.h>
	#include <stdlib.h>
	#include <strarg.h>
	void show_qrray(const double arp[, int n);
	double * new_d_array(int n, ...);
	int main(void)
	{
		double * p1;
		double * p2;

		p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
		p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
		show_array(p1, 5);
		show_array(p2, 4);
		free(p1);
		free(p2);

		return 0;
	}
	new_d_array()��������һ��int�����������ɱ��double�������ú�������һ��ָ��malloc()������ڴ���ָ�롣
	int����ָ����̬�����е�Ԫ�ظ���;doubleֵ���ڳ�ʼ��Ԫ�أ���һ��ֵ�����һ��Ԫ�أ��Դ����ƣ���
	�ṩshow_arrary()��new_d_arrar()�Ĵ��룬ʹ����������
	*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double * new_d_array(int lim, ...);
void show_array(double ar[], int n);

int main(void)
{
	double * p1;
	double * p2;

	p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
	system("color 5A");
	puts("Array1:");
	show_array(p1, 5);
	puts("\nArray2:");
	show_array(p2, 4);
	free(p1);										//�ͷ�malloc()������ڴ�
	free(p2);

	system("pause");
	return 0;
}

double * new_d_array(int lim, ...)
{
	va_list ap;										//�������ڴ�ű�ҵ�va_list����
	double  * par;

	va_start(ap, lim)								//��ʼ�������б�
	par = (double *)malloc(lim * sizeof(double));	//Ϊ��̬��������ڴ��
	for (int i = 0; i < lim; i++)
	{
		par[i] = va_arg(ap, double);				//ȡ��������д��������ڴ��
	}
	va_end(ap);										//��ap��λ���ͷŷ�����ڴ�

	return par;
}

void show_array(double ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%g ", ar[i]);
	}
	putchar('\n');
}

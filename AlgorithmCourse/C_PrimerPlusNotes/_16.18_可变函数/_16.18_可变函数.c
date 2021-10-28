//-�ɱ�����ĺ���
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
	ͷ�ļ�stdarg.h�ṩ�˿ɱ����������֧�֣�������ʹ�ò��裺
	1.�ں���ԭ����ʹ��ʡ�Ժ�
	2.�ں��������д���һ��va_list���͵ı���
	3.�ú꽫�ñ�����ʼ��Ϊһ�������б�
	4.�ú������������б�
	5.�ú����������
	*/

double sum(int lim, ...);

int main(void)
{
	double s, t;

	s = sum(3, 1.1, 2.5, 13.3);
	t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
	system("color 5A");
	printf("return value for "
		"sum(3,1.1.2.5,13.3):             %g\n", s);
	printf("return value for "
		"sum(6,1.1,2.1,13.1,4.1,5.1,6.1): %g\n", t);

	system("pause");
	return 0;
}

double sum(int lim, ...)			//�����б���������һ�����ʡ�ԺŵĲ�����ASCI��׼ʹ��parmN��ʾʡ�Ժ�ǰ���Ҳ�Ĳ���lim����ָ����ʡ�ԺŲ����еĲ���������
{
	va_list ap;						//������Ų����б�ı���
	double tot = 0;

	va_start(ap, lim);				//��ap��ʼ��Ϊ�����б�
	
	for (int i = 0; i < lim; i++)
	{
		tot += va_arg(ap, double);	//���η��ʵ�һ�����ڶ���...����������va_arg()���ṩ���˻���ǰ�����ķ�����������ʱ�����ú�va_copy(dest, src)����va_list�����ĸ����Ա��ٴ�ʹ��
	}
	va_end(ap);						//�ͷŷ�������ڴ�Ų������ڴ�
	
	return tot;
}
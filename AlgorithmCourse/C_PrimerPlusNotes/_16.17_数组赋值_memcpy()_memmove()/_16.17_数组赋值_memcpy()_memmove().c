#include <stdio.h>
#include <stdlib.h>
#include <string.h>			//�ṩ���ڴ濽�������ĺ���ԭ��
//#include <memory.h>

#define SIZE 10

void show_array(const int ar[], int n);

/*
	�ڴ濽��������memcpy()��memmove()
	����ԭ�ͣ�void * memcpy(void * restrict s1, const void * resterct s2, size_t n);
			 void * memmove(void * s1, const * s2, size_t n);
	�������ܣ�����s1ָ���λ�ø���n�ֽڵ�s2ָ���λ��
			 ���ּ�Ĳ���ɹؼ���restrict��ɣ���memcpy()���Լٶ���ָ��ָ���λ��û���ص���memmove()û������ٶ������ĸ��ƹ��������ڽ�Դλ�������ֽڸ��Ƶ���ʱ���������ٸ��Ƶ�Ŀ��λ�á�
			 �������������ص���ʹ��memcpy()����Ϊ�ǲ���Ԥ֪�ģ�����������������Ҳ����ʧ�ܡ��ڲ�Ӧ��ʹ��memcpy()ʱ�������������ֹʹ��memcpy()������ʹ��ʱ����ȷ��û���ص�����
	��˵��ʹ��memcpy()��Ҫ���ص�����������ڴ��ص�����Ϊ����Ԥ֪��(restrict�ؼ��ּ�ס���ɣ�
		   ʹ��memmove()������ͨ����ʱ�����������ڴ�ķ�ʽ������Ч�����ڴ��ص����⡣
		   
	����,��ȫ�����������ڴ��ص��Ļ���ʹ��memmove()Ϊ�á�*/
int main(void)
{
	int values[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int target[SIZE];
	double curious[SIZE / 2] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

	system("color 5A");
	puts("memcpy() used:");
	puts("values (Original data");
	
	show_array(values, SIZE);
	memcpy(target, values, SIZE * sizeof(int));
	puts("targer (copy of values):");
	show_array(target, SIZE);

	puts("\nUsing memmove() with overlapping ranges:");
	memmove(values + 2, values, 5 * sizeof(int));					//���������ڴ��ص���ʹ��memmove()Ϊ��
	puts("values -- elememts 0-4 copied to 2-6:");
	show_array(values, SIZE);

	puts("\nUsing memcpy()to copy double to int:");
	memcpy(target, curious, (SIZE / 2) * sizeof(double));			//memcpy()ֻ�����ڴ棬��������������
	puts("target -- 5 double into 10 int positions:");
	show_array(target, SIZE);

	system("pause");
	return 0;
}

void show_array(const int ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
	}
	putchar('\n');
}
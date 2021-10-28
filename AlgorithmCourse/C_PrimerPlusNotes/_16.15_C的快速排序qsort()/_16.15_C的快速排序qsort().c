//C��ͨ�ù��߿����кܶຯ����Ʃ�����������rand(),srand()��������������������ת���������ڴ��������
//��ʵ���ǹ���C�Ŀ���������������qsort()��Ӧ�á�

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 40

void fillarray(double ar[], int n);
void showarray(double ar[], int n);
int mycomp(const void * p1, const void * p2);

/*
	Cʵ�ֿ��������㷨�ĺ�����qsort()��
	��һ��������ָ������ͷ����ָ�루���ָ����void���͵�ͨ��ָ�룩���������ָ��������κ��������͵�ָ�롣
	�ڶ��������ǲ����������Ŀ����
	��������������Ϊ��һ��������void���͵�ָ�룬�����ڴ��������ʧ����Ԫ�ش�С��Ϣ����˵���������������Ԫ�ص����ʹ�С��size_t����)
	���ĸ�������ָ������ָ�룬����ȷ������˳��ָ�����ͣ�int (* compar)(const void * p1, const void * p2)

	�ú���ָ��ָ��һ������ıȽϺ������ñȽϺ����ĺ��������ǣ�
	���p1ָ���ֵ����p2ָ���ֵ���򷵻�һ�����������������ȣ��򷵻�0�����ǰ��ָ���ֵС�ں���ָ���ֵ���򷵻�һ��������
*/
int main(void)
{
	double ar[NUM];

	system("color 5A");
	fillarray(ar, NUM);
	puts("Original array:");
	showarray(ar, NUM);
	qsort(ar, NUM, sizeof(double), mycomp);
	puts("\nSorted array:");
	showarray(ar, NUM);

	system("pause");
	return 0;
}

void fillarray(double ar[], int n)
{
	int i;

	srand((unsigned int)time(NULL));
	for (i = 0; i < NUM; i++)
	{
		ar[i] = (double)rand() / ((double)rand() + 0.1);
	}
}

void showarray(double ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%9.4Lf", ar[i]);
		if (i % 6 == 5)
		{
			putchar('\n');
		}
	}
	if (i % 6 != 0)
	{
		putchar('\n');
	}
}

//���մ�С�����˳������
int mycomp(const void * p1, const void * p2)
{
	//ת���ɺ��ʵ�ָ������
	const double * a1 = (const double *)p1;
	const double * a2 = (const double *)p2;

	if (*a1 > *a2)
	{
		return 1;
	}
	else if (*a1 == *a2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
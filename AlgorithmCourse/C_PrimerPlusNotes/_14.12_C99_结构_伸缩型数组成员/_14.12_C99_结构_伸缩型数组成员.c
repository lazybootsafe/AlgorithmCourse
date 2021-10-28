#include <stdio.h>
#include <stdlib.h>

//����һ�����������������Ա�Ľṹģ��
struct flex
{
	int count;
	double average;
	double scores[];			//�����������Ա��ֱ������struct flex���ͱ���ʱ����������scores��Ա���κ��£���Ϊû��Ϊ�������ڴ�ռ䣩
	//�����������Ա�����ͳ���Ϊ0,����sizeof(struct flex)= 16 ���ṹ�����ͳ���ȡ������ĳ�Ա�Ĵ�С��Ϊÿ����Ա�Ĵ�С���� 8 + 8 == 16�������������Ա���ͳ���Ϊ0��
};

/*
	һ�������������Ա���������ԣ�

	1.�������Ա�������ڣ����ٲ��������ڡ�
	2.���Ա�д����ʹ����������������Ա��
	
	�����ṹ������һ�������������Ա�Ĺ���

	1.�����������Ա���������һ�������Ա
	2.�ṹ�б���������һ��������Ա
	3.���������������ͨ����һ�����������������ķ��������ǿյ�

	����֮�������������Ա������ڶ�������Ա���
	
	����C99����ͼ��

	1.C99�ṩ���������������Ա�Ľṹflex������Ϊ�����û��������ֽṹ��������Ϊ�Ⲣ��Ϊ�����������Ա�����ڴ�ռ�
	2.C99�ṩ������ṹ��Ϊ�ˣ�����һ��ָ����������������Ա�Ľṹflex��ָ�룬Ȼ����malloc()�������㹻�Ŀռ䣬
	  �Դ��struct flex�ṹ�ĳ������ݺ������������Ա��Ҫ���κζ���ռ䡣*/

void showFlex(const struct flex * p);

int main(void)
{
	struct flex * pf1, *pf2;
	int n = 5;
	double tot = 0;

	//Ϊ�ṹ���������洢�ռ�

	system("color 5A");
	//1.�����������Ա����5��doubleԪ��
	pf1 = (struct flex *)malloc(sizeof(struct flex) + n * sizeof(double));		//���Ϊ���ṹ�Ķ������ͳ�Ա�����ͳ���+Ҫ����������������Ա�����ͳ���
	pf1->count = n;
	for (int i = 0; i < n; i++)
	{
		pf1->scores[i] = 20.0f - i;
		tot += pf1->scores[i];
	}
	pf1->average = tot / n;
	showFlex(pf1);

	//2.�����������Ա����9��doubleԪ��
	n = 9;
	tot = 0;
	pf2 = (struct flex *)malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for (int i = 0; i < n; i++)
	{
		pf2->scores[i] = 20.0f - i / 2.0f;
		tot += pf2->scores[i];
	}
	pf2->average = tot / n;
	showFlex(pf2);
	free(pf1);
	free(pf2);

	system("pause");
	return 0;
}

void showFlex(const struct flex * p)
{
	printf("Score: ");
	for (int i = 0; i < p->count; i++)
	{
		printf("%g ", p->scores[i]);
	}
	printf("\nAverage: %g\n", p->average);
}
#include <stdio.h>
#include <stdlib.h>			//�ṩ��malloc()��calloc()��free()�ĺ���ԭ��

int main(void)
{
	int * p1;
	int * p2;

	p1 = (int *)malloc(10 * sizeof (int));			//malloc()����10��int�ռ䣬����ʼ���ڴ��
	p2 = (int *)calloc(10, sizeof (int));			//calloc()����ͬ�ϣ�����ʼ���ڴ��Ϊ0������֤������0������0����ַ���ȫ��ͬ��

	for (int i = 0; i < 10; i++)
	{
		printf("%3d", p1[i]);						//��malloc()���������飬�ڷ�������Ԫ��ǰ����ȳ�ʼ�����������������Ƿ��ʼ����һ����
	}
	putchar('\n');
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", p2[i]);						//��calloc()���������飬����Ԫ�ض�����0
	}
	putchar('\n');

	getchar();
	return 0;
}

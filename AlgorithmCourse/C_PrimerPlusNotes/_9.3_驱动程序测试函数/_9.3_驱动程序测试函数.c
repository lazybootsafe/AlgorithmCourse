#include <stdio.h>
#include <stdlib.h>

int imin(int, int);		//�ں��������У�����ʽ����������������ʡ�Ա�����

int main(void)
{
	int evil1, evil2;

	system("color 0A");

	printf("Enter a pair of integer (q to quit) : \n");
	while (scanf_s("%d %d", &evil1, &evil2) == 2)
	{
		printf("The lesser of %d and %d is %d.\n",
			evil1, evil2, imin(evil1, evil2));
		printf("Enter a pair of integer (q to quit) : \n");
	}
	printf("Bye!\n");

	getchar();
	getchar();
	return 0;
}

int imin(int n, int m)
{
	return (n < m) ? n : m;		//���ظ���ֵ������������ȷ����ע���ѡһ�͵��жϷ�֧���������ʽ��Ϊ���;����������ٶ�Ҳ�죩
}

/*int imin(int n, int m)
{
	double min = (n < m) ? n : m;

	return min;			//����ֵ�������������Ͳ�һ�£�ʵ�ʵķ���ֵ����������ȷ�������Խض�Ϊint����
}*/

/*int imin(int n, int m)
{
	int min = (n < m) ? n : m;
	return min;
}*/

/*int imin(int n, int m)
{
	int min;

	if (n < m)
	{
		min = n;
	}
	else
	{
		min = m;
	}
	return min;
}*/

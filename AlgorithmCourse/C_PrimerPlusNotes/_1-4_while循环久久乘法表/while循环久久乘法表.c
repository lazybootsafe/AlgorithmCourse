#include <stdio.h>

int main(void)
{
	int n = 0, m = 0;

	while (++n <= 9)
	{
		while (++m <= n)
		{
			printf("%dx%d=%-2d ", m, n, m*n);
		}
		printf("\n");
		m = 0;//�ڲ�ѭ����ӡ��һ��֮��m==n+1����m��ʼ�����������ѭ����ӡ��һ�У�n����������m����������
	}

	
	//doѭ������˷���
	/*do
	{
		do
		{
			printf("%dx%d=%-2d ", m, n, m*n);
			m++;
		} while (m <= n);
		printf("\n");
		m = 1;
		n++;
	} while (n <= 9);*/


	//forѭ������˷���
	/*for (size_t i = 1; i <= 9; i++)
	{
		for (size_t j = 1; j <= i; j++)
		{
			printf("%dx%d=%-2d ", j, i, j*i);
		}
		printf("\n");
	}*/

	getchar();
	return 0;
}
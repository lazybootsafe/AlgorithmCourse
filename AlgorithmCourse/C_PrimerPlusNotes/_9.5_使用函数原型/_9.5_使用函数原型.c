#include <stdio.h>

int imax(int n, int m);	

int main(void)
{
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3, 5));		
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3.0, 5.0));		//��double��ת������int����ʧ���ȣ��ᾯ�浫���ᱨ������ʱ���Զ�ת�����ضϣ���

	getchar();
	return 0;
}

int imax(int n, int m)
{
	int max;

	if (n > m)
		max = n;
	else
		max = m;
	
	return max;
}
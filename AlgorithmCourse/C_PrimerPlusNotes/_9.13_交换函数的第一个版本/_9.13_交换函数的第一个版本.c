
//������ֵ������Դ�루_9.14 ��ȷԴ�룩

#include <stdio.h>

void interchange(int u, int v);

int main(void)
{
	int x = 5, y = 10;

	printf("Originally x = %d, y = %d\n", x, y);
	interchange(x, y);	//������ֵʱ���������������������������ڲ�ʵ�ֻ���Ϊ���������2�����������ڴ�ռ���ʱ���棬Ȼ�����뽻���ı������ڴ��ַ�ѷ����仯����������뽻��ǰ���ǲ�ͬ��ַ����2�Ա���
	printf("Now x = %d, y = %d\n", x, y);

	getchar();
	return 0;
}

void interchange(int u, int v)	
{
	int temp;

	temp = u;
	u = v;
	v = temp;
}
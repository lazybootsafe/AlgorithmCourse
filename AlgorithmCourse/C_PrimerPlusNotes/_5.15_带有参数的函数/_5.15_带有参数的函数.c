#include <stdio.h>

void pound(int n);	//ANSI���ĺ���ԭ��

int main(void)
{
	//�����Զ����вκ�����������������������ƥ�䣬���Զ�ת����Ҳ������ָ�������ǿ��ת��
	
	int times = 5;
	char ch = '!';	//ANCIIֵΪ33
	float fl = 6.0;
	
	pound(times);
	pound(ch);
	pound((int)fl);
	getchar();
	return 0;
}

//��ӡһ�������ġ�#����һ�����з�
void pound(int n)	
{
	while (n-- > 0)
	{
		printf("#");
	}
	printf("\n");
}
#include <stdio.h>

int main(void)
{
	/*ϣ����ѧ��Zeno���۵�һ֧����Զ���ܵ�������Ŀ��
	 ��Ҫ����Ŀ�꣬���ȵõ���Ŀ������һ�룬Ȼ���ֱ��뵽��ʣ������һ�룬������û���
	 ����forѭ����������ʱ���ǰ����ĺͿ���*/
	int t_ct;		//�����
	double time, x;
	int limit;

	printf("Enter the nuber of terms you want:");
	scanf_s("%d", &limit);
	for (time = 0, x = 1, t_ct = 1; t_ct <= limit; t_ct++, x *= 2.0)
	{
		time += 1.0 / x;
		printf("time = %f when terms = %d\n", time, t_ct);
	}

	getchar();
	getchar();
	return 0;
}
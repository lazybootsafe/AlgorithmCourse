/*
һλǿ��ͳ����Ҫ����һλ��������ͻ�����׵�ѧ�ߣ�ѧ��ָ������
	˵����һ���1��С�󣬵ڶ����2������......��������
*/

#include <stdio.h>

#define SQUARES 64	//���̵ķ�����
#define CROP 1e15	//�����Ƶ�����С�����

int main(void)
{
	double current, total;
	int count = 1;

	printf("square  grains added  total grains  fraction of\n");
	printf("				    US total\n");
	total = current = 1;	//��ʼʱ1��
	printf("%-6d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);

	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0*current;//�¸�����������ӱ�
		total = total + current;
		printf("%-6d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	}
	printf("That's all.\n");
	getchar();
	return 0;
}
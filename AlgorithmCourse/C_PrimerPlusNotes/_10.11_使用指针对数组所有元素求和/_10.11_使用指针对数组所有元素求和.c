
//C��֤��Ϊ�������ռ��ʱ��ָ������֮��ĵ�һ��λ��Ҳ�ǺϷ��ģ�������һ������ġ�Խ�硱ָ���־����Ľ�β��

#include <stdio.h>

#define SIZE 10

int sum_ptr(int * start, int * end);

int main(void)
{
	int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer;

	answer = sum_ptr(marbles, marbles + SIZE);		/*����������0��ʼ������marbles+SIZEָ�������β֮�����һ����Ԫ�ء���C��֤�����֡�Խ�硱ָ��ĺϷ��ԣ�
													ע��: ��ȻC��֤��ָ��marbles + SIZE�ĺϷ��ԣ�����marbles[SIZE]�����κα�֤*/
	printf("The total number of marbles is %ld.\n", answer);

	getchar();
	return 0;
}

//startָ��������Ԫ�أ�endָ���������һ��Ԫ��֮��
int sum_ptr(int * start, int * end)
{
	int total = 0;

	while (start < end)
	{
		total += *start++;	/*�� *��start++��������ָ��Ӽ�  ��*��++���ȼ���ȣ�������Դ�������
							��׺��ʽ��ʾ��ָ��ָ������ݼӵ�total�ϣ�Ȼ��ָ������1*/
	}

	return total;
}
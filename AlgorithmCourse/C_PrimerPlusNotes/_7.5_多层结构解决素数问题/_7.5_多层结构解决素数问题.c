#include <stdio.h>
#include <stdbool.h>		//ʹ��bool�ؼ��ִ���_Bool,Ҳ�ṩ��true��false�ı�ʶ��

int main(void)
{
	//Ŀǰ�ۺ�Ӧ�ã���һ��ѭ�������һ����������ʾ�����ܱ����������������û�У���������һ��������

	unsigned long num;		//�û��������
	unsigned long div;		//���ܵ�Լ��
	bool isPrime;			//�����ı�־��flag��

	printf("This is a program for adjusting prime.");
	printf("Please enter a integer to analysis\n");
	printf("q to quit\n");

	/*���û�����һ���޷��ŵ�long����ֵʱ
	�����߿��԰����ַ���������ͷ�ļ�
	����ԭ��isdigit()������������ж��û��Ƿ��ȷ����һ�����֣�
	*/
	while (scanf_s("%lu", &num) == 1)		
	{
		for (div = 2, isPrime = true; (div * div) <= num; div++)	//�жϴ�2�����������Ҫ��������ƽ����֮�����������,�����ÿ�������������ʼ��������־Ϊtrue
		{
			if (num % div == 0)		//���Ҫ��������������
			{
				if (div * div != num)
				{
					printf("The integer %lu is divisibled by %lu and %lu\n", num, div, num / div);	//��ӡ��Ҫ������������Լ����div �� num/div	
				}
				else
				{
					printf("The integer %lu is divisibled by %lu\n", num, div);		//��ӡ��������ΪҪ��������ƽ����	
				}
				isPrime = false;	//����һ������
			}
		}
		if (isPrime)
			printf("The integer %lu is a primer number\n", num);
		printf("Please enter another integer to analysis\n");
		printf("q to quit\n");
	}
	printf("Bye! Thanks for using!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}
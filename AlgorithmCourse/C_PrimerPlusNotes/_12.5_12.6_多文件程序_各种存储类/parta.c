
//����ļ�֮�����ҵı������ã����ӣ��Ҹ����飩�������Ѳݣ���Ȼ�Ҳ������ʵı������ҵ�����

//���ִ洢��
#include <stdio.h>
#include <stdlib.h>

void report_count(void);
void accumulate(int k);				//����ĺ���ԭ�ͣ�������������һ���ļ���֮����øú����������ṩ����ԭ�ͣ��ɱ�����ȥ��λ�������岢ִ�У�

int count = 0;						//�ļ��������ⲿ����

int main(int argc, char * argv[])
{
	int value;						//�Զ�����
	register  int i;				//�Ĵ�������

	system("color 0A");

	printf("Enter a positive integer (0 to quit): ");
	while (scanf_s("%d", &value, 10) == 1 && value > 0)
	{
		++count;					//ʹ���ļ����������
		for (i = value; i >= 0; i--)
		{
			accumulate(i);
		}
		printf("Enter a positive integer (0 to quit): ");
	}
	report_count();

	getchar();
	getchar();
	return 0;
}

void report_count(void)
{
	printf("Loop executed %d times\n", count);
}
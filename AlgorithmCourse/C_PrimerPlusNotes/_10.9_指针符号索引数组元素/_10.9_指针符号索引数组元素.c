#include <stdio.h>
#include <stdlib.h>
#define PAUSE system("pause")
#define COLOR system("color 0A")
#define MONTHS 12

int main(void)
{
	int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	COLOR;
	for (int i = 0; i < MONTHS; i++)
	{
		printf("Month %2d has %d days.\n", i + 1,
			*(days + i));  //*(days + i) = days[i] ����ⲻ�˿���Դ�ļ�����������Ĵ�����2��ĳ��ԣ�Ӱ���Ժ�
	}
	PAUSE;
	return 0;
}
/*���ڿ�ʼ��ʹ��ָ������������飬ֱ����ȫ��Ϥ���������á�*/

//���������Ľ�ˮ�����ݣ������꽵ˮ�������꽵ˮ�������Լ��½�ˮ����

#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12
#define YEARS 5

int main(void)
{
	system("color 0A");

	//�ö�ά�����ʼ��2000-2004��Ľ�ˮ������

	const float rain[YEARS][MONTHS] = {
		{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },		//��0����Ա
		{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },		//��1����Ա
		{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },		//��2����Ա
		{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },		//��3����Ա
		{ 7.6, 5.5, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.0, 5.2 }		//��4����Ա�����ԣ��������ǰ���5����12�������������������飨��5����Ա�ģ�ÿ����Ա��12�������������飻��5��12�еĶ�ά���飩
	};
	int year, month;
	float subtot, total;

	printf(" YEAR   RAINFALL (inches)\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{		 		//����ÿһ�꣬���µ��ܽ�ˮ��subtot
		for (month = 0, subtot =0 ; month < MONTHS; month++)
		{		
			subtot += rain[year][month];
		}
		printf("%5d%15.1f\n", 2000 + year, subtot);		//2000 - 2004 ��
		total += subtot;		//������ȵ��ܽ�ˮ��
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
	printf("MONTHLY AVERAGES: \n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");

	for (month = 0; month < MONTHS; month++)
	{				//����ÿ���£�������·ݵ��ܽ�ˮ��subtot
		for (year = 0, subtot = 0; year < YEARS; year++)
		{
			subtot += rain[year][month];
		}
		printf("%4.1f", subtot / YEARS);
	}
	printf("\n");

	getchar();
	return 0;
}
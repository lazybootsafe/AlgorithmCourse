#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NDEBUG
#include <assert.h>		/*ͷ�ļ�assert.h����������������Գ����С�Ϳ⡣*/

#pragma warning(disable: 4996)


int main(void)
{
	double x, y, z;

	system("color 5A");
	puts("Please enter a pair of numbers ( 0 0 to quit):");
	while (scanf("%lf %lf", &x, &y) == 2
		&& (x != 0 || y != 0))
	{
		z = x*x - y*y;	/*should be +*/
		assert(z >= 0);					/*assert()�Ƕ�������Ͽ�Ķ��Ժ꣬�������������ʽΪ������ͨ���ǹ�ϵ���߼����ʽ��
										������ʽ��ֵΪ�٣������׼������д��һ��������Ϣ������abort()������ֹ����
										����������Ϣ����������жϣ�����Ĳ������ʽ��������������ļ������кš�*/

		/*�����ŵ㣺1.������Ϣ��׼�����Զ�ʶ���ļ��ͷ���������к�
				   2.����ı���룬�ɿ�������ú�assert()�Ļ��ƣ��ڰ���assert.hͷ�ļ�֮ǰ��Ӻ궨�壺 #define NDEBUG �����ö��Ժ�assert()*/
		printf("answer is %lf\n", sqrt(z));
		puts("Nwxt pair of numbers:");
	}
	puts("Done!");

	system("pause");
	return 0;
}
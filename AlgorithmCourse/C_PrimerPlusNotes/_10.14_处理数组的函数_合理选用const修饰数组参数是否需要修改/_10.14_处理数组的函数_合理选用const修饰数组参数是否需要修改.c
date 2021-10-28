#include <stdio.h>
#include <stdlib.h>

#define COLOR system("COLOR 4F")
#define SIZE 5

void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);

int main(void)
{
	COLOR;

	double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
	printf("The original dip array: \n");
	show_array(dip, SIZE);
	mult_array(dip, SIZE, 2.5);
	printf("The dip array after calling mult_array(): \n");
	show_array(dip, SIZE);

	getchar();
	return 0;
}

//��ʾ��������
void show_array(const double ar[], int n)  /*����Ҫ�޸����飬�����const����Ϊ������ֻ�����飩��
										   ����ʱһ����ָ����ͼ�޸��������ݣ��������ͻ�����һ��������Ϣ��֪ͨ�û�������ͼ�޸ĳ���*/
{
	for (int i = 0; i < n; i++)
	{
		printf("%8.3f ", ar[i]);
	}
	putchar('\n');
}

/*��ͬһ����ȥ��ÿ������Ԫ��*/
void mult_array(double ar[], int n, double mult)	//��Ҫ�޸��������ݣ����ɼ�const����
{
	for (int i = 0; i < n; i++)
	{
		ar[i] *= mult;
	}
}
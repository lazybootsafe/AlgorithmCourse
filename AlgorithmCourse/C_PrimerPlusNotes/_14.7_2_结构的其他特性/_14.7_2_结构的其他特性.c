#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

int main(void)
{
	struct funds stan = {
		"bank_A",
		4545.00,
		"save_B",
		3423.89
	};
	
	//�ṹ�������ԣ�

	//1.���ڵ�C�����һ���ṹ��ֵ����һ���ṹ�����ܶ�������������
	struct funds o_data;

	o_data = stan;		//ʹ��o_data��ÿ����Աֵ��������stan��Ӧ��Ա��ֵ����ʹ��һ����Ա������Ҳ������ɸ�ֵ

	//Ҳ���԰�һ���ṹ��ʼ��Ϊ��һ��ͬ�����͵Ľṹ��
	struct funds right_filed = { "bank_A", 4545.00, "save_B", 3423.89 };
	struct funds caption = right_filed;		//��һ���ṹ��ʼ��Ϊ��һ���ṹ

	//2.���ڵ�C������ANSI C���У��ṹ����������Ϊ�������ݸ���ַ��Ҳ������Ϊ��������ֵ����

	//�ѽṹ��Ϊ�����������Խ�������Ϣ���ݸ���һ��������
	//ʹ�ú������ؽṹ���Խ��ṹ��Ϣ�ӱ����������ݸ����ú�����������������

	//3.�ṹָ��Ҳ����˫��ͨ�ţ�������Ϊ�����������д��ݣ�Ҳ������Ϊ��������ֵ���أ�

}
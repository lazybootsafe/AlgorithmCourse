#include <stdio.h>

#define BORDER 23
/*
	���ϣ���ͳһ�洢�ռ䣨����ͬʱ���洢��ͬ�������ݵ���������*/
union hold					//����ģ�壬���Ϊhold
{
	int digit;
	double bigfl;
	char letter;
};

int main(void)
{
	union hold fit;			//hold���͵����ϱ����������������㹻�Ŀռ��Ա��������������Ե������Ҫ��������£���������Ϊdouble�����ݣ�
	union hold save[10];	//10�����ϱ���������
	union hold * pu;		//ָ��hold�������ϵ�ָ��

	//���ϵĳ�ʼ����ֻ�ܴ洢һ��ֵ����ͬ�ڽṹ
	//1.��һ�����ϳ�ʼ��Ϊͬ�����͵���һ������
	union hold valA;
	valA.letter = 'R';			//��һ�����ϳ�ʼ��Ϊ��һ������

	union hold valB = valA;

	//2.��ʼ�����ϵĵ�һ��Ԫ��
	union hold valC = { 88 };	//��ʼ�����ϵ�digit��Ա

	//3.C99��׼��ָ����ʼ����Ŀ
	union hold valD = { .bigfl = 118.2f };

	//���ϵ�ͨ�����ڣ�
	//1.һ����Ա��ֵ�������������һ����Ա���鿴��Щ���ݣ���������ʱ�����ã�ʵ����_15.4��
	/*2.ĳЩ�ṹ��ʹ�����ϣ��ýṹ�洢����Ϣ���������е�һ����Ա��
		���磺�ٶ���һ����ʾһ�������Ľṹ�������������ʹ���ߣ�����һ���ṹ��Ա��������������ߡ�������������ޣ�����һ����Ա�����������Ĺ�˾��*/
	struct owner
	{
		char socsecurity;
		//...
	};

	struct leasecompany
	{
		char name[40];
		char headquarters[40];
		//...
	};

	union data
	{
		struct owner ownercar;
		struct leasecompany leasecar;
	};

	struct car_data
	{
		char name[40];
		int status;		//0==˽�У�1==����
		union data ownerinfo;
	};
	
	/*�ٶ�fits��һ��car_data���͵Ľṹ������
	  �����fits.status == 0�����������fits.ownerinfo.ownercar.socsecurity;
	  �����fits.status == 1�����������fits.ownerinfo.leasecar.name;	*/
}
//�����ӵ���غ����ļ�

#include <stdlib.h>							//�ṩ��rand()�ĺ���ԭ��
#include <time.h>							//�ṩ��time()�ĺ���ԭ��

int roll_count = 0;							//�ⲿ���ӡ��ļ�������

static int dice_once(int sides)				//��̬�������ļ�˽��
{
	unsigned int roll;						//�����ӵĵ���

	srand((unsigned int)time(NULL));		//��ϵͳʱ���ʼ��һ������ֵ
	roll = rand() % sides + 1;				//1-�����������������
	++roll_count;							//�����Ӵ���

	return roll;
}

 int dice_more(int dices, int sides)			//�ⲿ����()
{
	 int total = 0;

	 if (sides < 2)
	 {
		 printf("Need at least 2 sides.\n");	//����2�棨2��ʱģ����Ӳ�ң�
		 return -2;
	 }
	 if (dices < 1)
	 {
		 printf("Need at least 1 die.\n");		//����1������
		 return -2;
	 }
	 for (int i = 0; i < dices; i++)			//������dices�����ӣ����ۼ����
	 {
		 total += dice_once(sides);
	 }

	 return total;
}
#include <stdio.h>

const int S_PER_M = 60;		//ÿ���ӵ�����
const int S_PER_H = 3600;	//ÿСʱ������
double M_PER_K = 0.62137;	//ÿ�����Ӣ����

int main(void)
{	
	//���㳤�ܵ��˶�����

	double distK, distM;	//�Թ����Ӣ��Ƶľ���
	double rate;			//ƽ���ٶȣ���λ��Ӣ��ÿСʱ��
	int min, sec;			//������������
	int time;				//������
	double mTime;			//����1Ӣ�����ʱ����λ���룩
	int mMin, mSec;			//����1Ӣ�����ʱ������+����

	printf("This program converts your time for a metric race\n");
	printf("to a time for running a mile and to your average\n");
	printf("speed in miles per hour.\n");
	printf("Please enter, in kilometre, a distance run:\n");
	scanf_s("%lf",&distK,10);	//��ʽ��ɨ������һ��double����ֵ
	printf("Next enter the time in minutes and seconds.\n");
	printf("Bengin by entering the minutes:\n");
	scanf_s("%d", &min,10);
	printf("Now enter the seconds:\n");
	scanf_s("%d", &sec,10);
	//��ʱ��ת��Ϊ��
	time = min * S_PER_M + sec;
	//�ѹ���ת��ΪӢ��
	distM = distK * M_PER_K;
	//Ӣ��/��*��/С�� =Ӣ��/Сʱ
	rate = distM / time * S_PER_H;
	//ʱ��/����=����ÿӢ�����ʱ
	mTime = (double)time / distM;
	mMin = (int)mTime / S_PER_M;	//���������
	mSec = (int)mTime % S_PER_M;	//���ʣ������
	printf("You ran %1.2f kilometers(%1.2f miles) in %d min, %d sec\n",
		distK, distM, min, sec);
	printf("That pace corresponds to running a mile in %d min ",
		mMin);
	printf("%d sec.\nYour average speed was %1.2f mph\n",
		mSec, rate);

	getchar();
	getchar();
	return 0;
}
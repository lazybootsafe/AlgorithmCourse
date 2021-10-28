//����С��Ϸ�����ļ�

#include <stdio.h>
#include <stdlib.h>								//Ϊsrand()�ṩԭ��
#include <time.h>								//Ϊtime()�ṩ����ԭ��
#include "randum.h"
#include <stdbool.h>
#include <Windows.h>

void evaluate(void);
void changefontcolor(void);
int printf1(const char * str, ...);

static int guess_count = 0;						//��̬������,�ڲ�����

int main (void)
{
	float guess;
	int secret;
	bool right = false;

	srand((unsigned int)time(NULL));			//ȡϵͳʱ��Ϊ���������
	changefontcolor();
	printf( "********************************\n"
			"***   ����С��Ϸ - C����̨   ***\n"
			"********************************\n"
			"\nϵͳ�ѳ�ʼ��һ��0��%d������������������µ�����q�˳���Ϸ����\n", MAX);
	while (!right)
	{
		secret = randnum(MAX);					//���������
		while (!right && scanf_s("%f", &guess, 10))
		{
			if (guess < secret)
			{
				printf("��%d�Σ����������ƫС��\n", ++guess_count);
				right = false;
			}
			else if (guess > secret)
			{
				printf("��%d�Σ����������ƫ��\n", ++guess_count);
				right = false;
			}
			else
			{
				printf("��%d�Σ�Ŷ�ˣ����¶���(^_^)\n", ++guess_count);
				right = true;
			}
		}
		if (right)								//����¶�
		{
			putchar('\n');
			evaluate();
			changefontcolor();
			printf("\n��һ�ֿ�ʼ, ���������µ�����q�˳���Ϸ����\n");
			guess_count = 0;					//�µĴ�������
			right = false;						//�¶��ü�
		}
		else
			goto mark1;							//�û��������������
	}
mark1:
	printf("��Ϸ������\n");

	system("pause");
	return 0;
}

//���ۺ���
void evaluate(void)
{
	if (guess_count <= 5)
	{
		printf_evaluate("������Ϸ�����ĵȼ������� %c\n", 'A');
	}
	else if (guess_count >5 && guess_count <= 10)
	{
		printf_evaluate("������Ϸ�����ĵȼ������� %c\n", 'B');
	}
	else if (guess_count >10 && guess_count <= 20)
	{
		printf_evaluate("������Ϸ�����ĵȼ������� %c\n", 'C');
	}
	else
	{
		printf_evaluate("������Ϸ�����ĵȼ������� %c\n", 'D');
	}
}

//���Ŀ���̨�ı�ɫ
void changefontcolor(void)
{
	HANDLE hConsoleOutput;
	static WORD color = 0x09;						//�����ӡ�����������򡢾�̬��

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//color = (WORD)time(NULL) % 0x10;				//ȡ�����ǰ��ɫ0-F
	color += 0x1;
	color %= 0x1A;									//color��0��F�ı�ɫǰ��,����ɫΪ0(��ɫ)
	SetConsoleTextAttribute(hConsoleOutput, color);
}

//��ӡ��ɫ����
int printf_evaluate(const char * str, char ch)
{
	HANDLE hConsoleOutput;
	int retn;

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput, 0x4E);
	retn = printf(str, ch);

	return retn;

	//��������һ�ڵ�֪ʶ�㣺�����ڴ�malloc()��free()
	char * ptd;
	ptd = (char *)malloc(sizeof (char)* 10);		/*ע�⣬ANSCI C��׼�У��ڴ���亯��ʹ��һ��ָ�������ڴ���ͨ��ָ����Ϊ����ֵ��
													�����ڷ����ڴ�ʱ��Ϊ�˳���������Ӧ�ö�ָ���������ָ��
													(������voidָ�븳ֵ����������ָ�룬����������ͳ�ͻ����һ���б���ƽ����ָ�븳ֵ�����Ժ�Ҫ��)*/
}
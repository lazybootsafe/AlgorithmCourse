#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

/*
	exit()�����Ѿ��ù������⣬main()�з���ʱ���Զ�����exit()������
	atexit()��ע����ֹ�������ڵ���exit()ʱִ�еĺ����б��н���ע�ᣬ�Ա�exit()�˳�ʱ�����Ƚ������˳��ִ���ض�����������ע��32����
	exit()ִ����atexit()ע��ĺ�����
	��ˢ����������ر����д򿪵������͹ر�ͨ�����ñ�׼IO����tmpfile()��������ʱ�ļ���
	���exit()������Ȩ���ظ��������������ܵĻ�����������������������ֹ״̬�������Ƿ������˳��ȵȣ�
	*/

void sign_off(void);
void too_bad(void);

int main(void)
{
	int n;

	atexit(sign_off);			//ע��sign_off()����
	puts("Enter an interger : ");
	if (scanf("%d", &n) != 1)
	{
		puts("That's no integer!");
		atexit(too_bad);
		exit(EXIT_FAILURE);
	}
	printf("%d is %s.\n", n, (n % 2 == 0) ? "even" : "odd");

	return 0;					//����ʱ����exit()����
}

void sign_off(void)
{
	puts("Thus terminates another magnificent program from");
	puts("SeeSaw Software!");
}

void too_bad(void)
{
	puts("SeeSaw Software extends its heartfelt condolences");
	puts("to you upon the failure of your program.");
}
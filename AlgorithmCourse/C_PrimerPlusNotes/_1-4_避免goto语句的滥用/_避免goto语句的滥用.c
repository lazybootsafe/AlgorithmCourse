/*#include <stdio.h>

int main(void)
{
	����goto���ĳ������Σ�Ȼ��չ��һ��Cϰ�ߵķ�ʽ

	1.������Ҫ��������if����
	if (size > 12)
		goto a;
	goto b;
	a:
		cost *= 1.95;
		flag = 2;
	b:
		bill = cost * flag;

	�ھɷ���BASIC��FORTRAN�У�ֻ��ֱ�Ӹ���if��ĵ������������if��û�д�����������Ĺ涨����ת��Ϊ����ʹ�ô����򸴺����ı�׼C����������ʹ��
	if (size > 12)
	{
		cost *= 1.95;
		flag = 2;
	}
	bill = cost * flag;

	2.��ѡһ
	if (ibex > 14)
		goto a;
	sheds = 2;
	goto b;
	a: 
		sheds = 3;
	b:
		help = 2 * sheds;

	��C��if else�����滻
	if (ibex > 14)
	{
		sheds = 3;
	}
	else
	{
		sheds = 2;
	}
	help = 2 * sheds;

	3.������ȷ��ѭ��
	readin: scanf_s("%d", &score);
	if (score < 0)
	{
		goto stage2;
	}
	losts of statements;
	goto readin;
	stage2: 
		more stuff;

	��whileѭ�����棺
	scanf_s("%d", &score);
	while (score <= 0)
	{
		losts of statement;
		scanf_s("%d", &score);
	}
	more stuff;

	4.����ѭ��ĩβ������ʼ��һ��ѭ������continue����

	5.����ѭ������break���档
	ʵ���ϣ�break��continue��goto��������ʽ��
	ʹ�����ǵĺô����ڣ����ǵ����ֱ������Ǹ���Ϊ��ʲô�����ң���Ϊ���ǲ�ʹ�ñ�ǩ�����Բ����ڱ�ǩ�Ŵ�λ�õ�Ǳ��Σ�ա�

	6.���Խ�ֹ���ҵص�������Ĳ�ͬ����
	������ʹ��goto�������ѭ��������breakֻ������������ѭ����
}*/
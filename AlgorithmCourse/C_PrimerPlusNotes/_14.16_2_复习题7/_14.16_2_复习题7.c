#include <stdio.h>
#include <stdlib.h>
#include "starfolk.h"		//�ṩ��BEM�Ľṹģ��

void show(BEM * pst);

int main(void)
{
	BEM * pst;
	BEM deb = {
		6,
		{ "Berbnaze", "Gwolkapwolk" },
		"Arcturan"
	};

	pst = &deb;

	//a.�������Ĵ�ӡ���
	printf("%d\n", deb.limbs);
	printf("%s\n", deb.type);
	printf("%s\n", deb.type + 2);

	//b.��ʾ��Arcturan��
	deb.title.last;
	pst->title.last;
	(*pst).title.last;
	
	//c.��������
	show(pst);
	
	getchar();
	return 0;

}

//c.��дһ����������һ��bem�ṹ�ĵ�ַΪ�������������е���ʽ��ӡ������ݡ��ṹģ�嶨����starfolk.h�ļ�
//Berbnaze Gwolkapwolk is a 6-limited Arcturan.

void show(BEM * pst)
{
	printf("%s %s is a %d-limited %s.\n", pst->title.first, pst->title.last, pst->limbs, pst->type);
}
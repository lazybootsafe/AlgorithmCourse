#include <stdio.h>
#include <stdlib.h>

typedef char * (*PCHAR_PFUN_PCHAR_CHAR)(char *, char);

char * test(char *, char);

int main(void)
{

	PCHAR_PFUN_PCHAR_CHAR p = test;

	(*p)("mifeng.", 'C');				//����ָ����ú������﷨1
	p("mifeng.", 'C');					//�﷨2
	getchar();
	return 0;
}

char * test(char * str, char ch)
{
	printf("%c %s\n", ch, str);

	return str;
}
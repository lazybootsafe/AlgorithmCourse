#include <stdio.h>
#include <stdlib.h>

#define COLOR system("color 0A")

int main(void)
{
	char * mesg = "Don't be a fool! ";
	char * copy;

	COLOR;
	
	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s, &mesg = %p, value = %p\n",	//��ӡָ��ָ����ַ�������ӡָ��ĵ�ַ����ӡָ���ֵ���ַ�����Ԫ�صĵ�ַ��
		mesg, &mesg, mesg);			
	printf("copy = %s, &copy = %p, value = %p\n",	//��ӡָ��ָ����ַ�������ӡָ��ĵ�ַ����ӡָ���ֵ���ַ�����Ԫ�صĵ�ַ��
		copy, &copy, copy);			
	
	getchar();
	return 0;
}
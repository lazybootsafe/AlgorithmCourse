#include <stdio.h>
#include <stdlib.h>

#define DEF "I am a #defined string."

int main(void)
{
	char str1[80] = "An array was initialized to me.";
	const char * str2 = "A pointer initialized to me.";

	//gets_s(str1, 80);			//gets_s()������ȡһ���ַ�������������СΪ80B�����з�����ȡ������

	puts("I'm an argument to puts().");		//puts()�������һ�зǷ����ַ����������ַ�������������ָ�����ַ���ָ�룩
	puts(DEF);			//���һ�з����ַ���������ͬ�ϣ�
	puts(str1);			//���һ���ַ�������һ��׷���˿��ַ����ַ������У�
	puts(str2);			//���һ��str2ָ����ַ���
	puts(&str1[5]);		//���һ��str1�ĵ�6��Ԫ�����ڵ�ַ�����ַ���
	puts(&str2 + 4);	//���һ��str2ƫ��4ָ����ַ���

	getchar();
	return 0;
}
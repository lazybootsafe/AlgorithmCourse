#include <stdio.h>
#include <stdlib.h>

#define MAX 81
int main(void)
{
	/*gets()������ȡ�ַ�����
	��ȡ���з�֮ǰ�������ַ�������β��׷��һ�����ַ����ظ����÷�
	ͬʱ����ȡ���з������䶪��


	ע�⣺ gets()����й¶�ڴ棬
	�ñ���������gets_s()���ƶ�ȡ�ַ����ĳ���*/

	char name[MAX];			//����ռ�

	system("color 0A");
	printf("Hi, what's your name?\n");
	gets_s(name, MAX);		//��ȡ�ַ�����name����
	printf("Nice name, %s!\n", name);

	getchar();
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>		//�ṩ��strchr()��ԭ��

#define MAX 81

int main(void)
{
	char name[MAX];
	char * ptr;

	system("color 0A");
	printf("Hi, what's your name?\n");
	fgets(name, MAX, stdin);	
	ptr = strchr(name, '\n');		//���һ��з�
	if (ptr)						//���ָ��ֵ��ΪNULL
		*ptr = '\0';				//ֲ����ַ�
	printf("%s? Ah, %s!\n", name, name);

	system("pause");
	return 0;
}
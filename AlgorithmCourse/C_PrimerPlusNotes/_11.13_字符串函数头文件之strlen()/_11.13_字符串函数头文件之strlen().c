#include <stdio.h>
#include <string.h>		/*�ṩ�ַ�����صĺ���ԭ��*/
#include <stdlib.h>

void ChangeStrlen(char * string, unsigned int size);

int main(void)
{
	char msg[] = "Hold on to your hats, hackers.";

	system("color 0A");
	puts(msg);		//��ӡ�ַ�����׷�ӻ��з�
	ChangeStrlen(msg, 7);
	puts(msg);
	puts("Let's look at some more of the string.");
	puts(msg + 8);		//��ӡmsgƫ��8�����ַ���

	getchar();
	return 0;
}


//���Դ�ַ����ĳ��ȴ���size��������Ϊsize��С
void ChangeStrlen(char * string, unsigned int size)
{
	if (strlen(string) > size)
	{
		*(string + size) = '\0';		//���ִ�size���Ⱥ󣬵�size+1����Ա��ֵΪ���ַ�
	}
}
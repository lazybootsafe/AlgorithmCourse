#include <stdio.h>
#include <stdlib.h>

#define MAX 81

int main(void)
{
	char name[MAX];
	char * ptr;

	system("color 0A");
	printf("Hi, what's your name?\n");
	ptr = gets_s(name, MAX);		/*gets_s()��ȡָ������-1���ַ�����׷�ӿ��ַ��������з���ȡ����
									��ȡ�����ַ������浽��һ������ָ��ĵ�ַ��
									��ȡ�ɹ�����ָ����ַ�����charָ�룬ʧ�ܷ��ؿ�ָ��

									ע��: gets_s()���ص�ָ��ʹ��ݹ�������ͬһ��ָ�룬�����岻ͬ��
									���ݸú������ܣ���֪name��Ϊ�ַ����ĵ�ַ����������ִ�������Լ����㣬����ᵼ���ַ����ĵ�ַ�����仯
									�����ص�ָ����ַ�����ָ��ptr����ִ���������㣬ʹ��ָ��ָ����һ���ַ�*/
	printf("%s? Ah! %s!\n", name, ptr);

	getchar();
	return 0;
}
#include <stdio.h>

int main(void)
{
	/*��ӡ���ַ���
	1.ʹ�ö��printf()
	2.*/
	printf("Here's one way to print a ");//���߱�������ӡ�ַ�����ǰ��Σ�
	printf("long string.\n");//���߱������ڵ�ǰ��괦������ӡ�ַ��������Σ�����Here's another way to print a long string����
	printf("Here's another way to print a \
					long string.\n");//\���߱�������ӡ�ַ���ʱ������\������п��ַ����ӵڶ�������߼�����ӡ����Here's another way to print a 		   long string����
	printf("Here's another way to print a \
long string.\n");//\���и��߱�������ӡ�ַ���ʱ������\������п��ַ����ӵڶ�������߼�����ӡ����Here's another way to print a long string����
	printf("Here's the newest way to print a "
		"long string.\n");//ANSI C������µ�һ�ִ�ӡ���ַ����ķ�����""���߱�������ӡ�ַ���ʱ���������ַ���������������Here's another way to print a long string����
	
	getchar();
	return 0;
}
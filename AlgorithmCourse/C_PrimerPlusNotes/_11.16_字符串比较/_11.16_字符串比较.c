#include <stdio.h>
#include <string.h>


#define SIZE 41
#define ANSWER "Grant"

int main(void)
{
	char try_[41];
	
	puts("Who is buried in Grant's tomb?");
	gets_s(try_, SIZE);
	while (try_ != ANSWER)		/*�������������Ȼ��������Ƚϵ�2���ַ�����һ������ʾ�û��������룬ֱ��һ��Ϊֹ��
								  ���ǣ�try��ANSWERʵ������char���͵�ָ�룬ָ��ֵ��2�ַ����ĵ�ַ����Զ����ȣ�
								  ������������ʲô����������ѭ��*/
	{
		puts("No, that's wrong. Try again.");
		gets_s(try_, SIZE);
	}
	puts("That's right!");

	getchar();
	return 0;
}
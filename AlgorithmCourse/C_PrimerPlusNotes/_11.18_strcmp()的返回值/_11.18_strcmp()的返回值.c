#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//�۲�strcmp()�ķ���ֵ�ܽ᷵��ֵ����

	system("color 4E");

	printf("strcmp (\"A\", \"A\") is ");
	printf("%d\n\n", strcmp("A", "A"));					//0

	printf("strcmp (\"A\", \"B\") is ");
	printf("%d\n\n", strcmp("A", "B"));					//-1

	printf("strcmp (\"B\", \"A\") is ");
	printf("%d\n\n", strcmp("B", "A"));					//1

	printf("strcmp (\"C\", \"A\") is ");	
	printf("%d\n\n", strcmp("C", "A"));					//1

	printf("strcmp (\"Z\", \"a\") is ");
	printf("%d\n\n", strcmp("Z", "a"));					//-1

	printf("strcmp (\"mingcxx\", \"mingc\") is ");
	printf("%d\n\n", strcmp("mingcxx", "mingc"));		//1
	
	/*
	�ܽ᣺strmp()���β������ַ�����Ӧ��ÿһ���ַ���ANSCIIֵ��
	ǰ�ߴ��ں��߷���1����C�����£�,
	ǰ��С�ں��߷���-1,
	������������������һ���ַ�ֱ���ҵ�һ��ANSCII������ַ����ط�0ֵ���κ�һ���ַ����Ľ�β��
	���ÿһ���ַ���ANSCIIֵ��ȣ��򷵻�0

	����strcmp()���αȽ����ַ�����ÿһ���ַ���ANSCII��ֵ��ǰ�߼�ȥ���ߣ�С��0���ظ�ֵ������0������ֵ������0�����������һ���ַ�
	��˵��;ǰһ���ַ����ĸ��ַ���ǰ�棩

	ANSI��׼�涨�������һ���ַ�������ĸ���е�˳�����ڵڶ����ַ��������ظ�ֵ��ȷ������ֵ�����ڲ�ͬ��Cʵ�֣�
	*/
	
	getchar();
	return 0;
}
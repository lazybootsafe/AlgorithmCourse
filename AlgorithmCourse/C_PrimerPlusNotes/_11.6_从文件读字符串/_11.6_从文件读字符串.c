#include <stdio.h>
#include <stdlib.h>

#define MAX 81

int main(void)
{
	char name[MAX];
	char * ptr;

	system("color 0A");
	printf("Hi, what's your name?\n");
	ptr = fgets(name, MAX, stdin);		/*�ӱ�׼��������ȡ�ַ�����name���飬����ָ���ַ�����ָ��ֵ
										ע�⣺ ���Ǵ��ļ���ȡ�ַ����ĺ��������ԣ�
										1.һ������ļ�ָ�루������ܼ������룬�ļ�ָ���Ϊ��׼��������
										2.��Ϊ��ȡ�ļ����ݣ����Ի��з�ͬ����ȡ
										����ͬ�ڴӱ�׼��������ȡ�ִ���gets_s()(��ȡ���з�֮ǰ�������ִ��������з���ȡ����)��*/
	printf("%s? Ah, %s!\n", name, ptr);

	system("pause");
	return 0;
}
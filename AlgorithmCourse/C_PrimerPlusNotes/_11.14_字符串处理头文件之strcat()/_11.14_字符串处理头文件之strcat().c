#include <stdio.h>
#include <string.h>

#define SIZE 81

int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";

	puts("What is your favorite flower?");
	gets_s(flower, SIZE);
	strcat_s(flower, SIZE, addon);		/*�ַ������Ӻ����İ�ȫ�汾����Դ�ַ���������Ŀ���ַ�����β����
										 �������ֽ������ٵ������ַ����ĳ���+1,
										 ���Դ�ַ����ռ䲻������������ַ�����������ڵĴ洢��Ԫ������һЩ����*/
	puts(flower);
	puts(addon);

	getchar();
	return 0;
}
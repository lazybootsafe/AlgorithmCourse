#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

int main(int argc, char * argv[])
{

	/*ǰ��: 
				��Ŀд���ˣ�����ԡ��������в�����������
	  �������ܣ�
				 strtol(const char * Str, char ** EndPtr, int Radix)
	  �������ܣ�
				���ַ�ָ��ָ����ַ���ת��Ϊlong��ֵ��
				������ָ����ַ�����ʼ�������ĵ�һ���������ַ���ָ��ֵ�����䱣����һ������ָ���
				ͬʱ���ṩ�˶Բ�ͬ�������ִ���ת���������ֵĻ�������������36���ƣ�ʹ��һֱ����z������ĸ��Ϊ����	 
	  ��غ�����
				strtod(const char * Str, char ** EndPtr) 
				�������ܣ�ת���ַ����е�����Ϊʮ����double��ֵ�������������ĵ�һ����double�ַ�

			    strtoul(const char * Str, char ** EndPtr, int Radix)
				�������ܣ�ת���ַ����е�����Ϊ�޷���long��ֵ�������������ĵ�һ����long���ַ�������ת�����ֽ��Ƹ�ʽ
				
				�������ȵȡ�����
		��¼��
				�ܶ�Cʵ�ֶ���itoa()��ftoa()�������͸�����ת��Ϊ�ַ�����
				���ڼ������ϣ�Ӧʹ��sprintf()�����������*/

	char num_str[SIZE];
	char * end;
	long num_val;

	system("color 4A");
	puts("Enter a number (empty to quit) :");
	while (gets_s(num_str, SIZE) && num_str[0] != '\0')
	{
		num_val = strtol(num_str, &end, 10);		//���ַ�ָ��ָ����ַ�������ת��Ϊlong��ֵ��������һ������ָ�루ָ��һ��ָ���ַ���ָ�룩
		printf("value: %ld, stopped at %s (%d)\n", num_val, end, *end);
		num_val = strtol(num_str, &end, 16);		/*����16*/
		printf("value: %ld, stopped at %s (%d)\n", num_val, end, *end);
		puts("Next number:");
	}
	puts("Bye!");

	getchar();
	return 0;
}
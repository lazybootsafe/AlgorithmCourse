#include <stdio.h>

#define SIZE 41

struct book											
{
	char title[SIZE];
	char author[SIZE];
	float value;
};

int main(void)
{
	/*�ṹ��ָ����ʼ����Ŀ���﷨����������ָ����Ա�ĳ�ʼ���������ź��±��ָ��Ԫ�س�ʼ������
		�ṹ��Ա�����(.)�ͳ�Ա����ָ��Ԫ�س�ʼ����.member
	*/

	//1.���ֳ�ʼ��
	struct book library1 = { .value = 10.99 };

	//2.��������˳���ָ����Ŀ��ʼ��
	struct book library2 = {
		.value = 25.99f,
		.author = "Philionna Pestle",
		.title = "Rue for the Toad"
	};

	//3.������һ��������һ��ָ����ʼ����Ŀ֮��ĳ����ʼ����ĿΪ����ָ����Ա��ĳ�Ա�ṩ�˳�ʼֵ
	struct book library3 = {
		.value = 18.90f,				//ָ����ʼ����Ŀ����ʼ��value��Ա
		.author = "Philionna Pestle",	//ָ����ʼ����Ŀ����ʼ��author��Ա
		0.25f							/*�����ʼ����Ŀ����ʼ��author��ĳ�Աvalue(�����˾ɵĸ�ֵ18.90)
				  
										  ��һ�����������飺���һ��ָ��Ԫ�غ��ж��ֵ����Щֵ�����ζԺ���Ԫ�س�ʼ��������ֻ������ĳ��Ա�����һ�γ�ʼ�������Ǿ�ֵ��
										  int num[10] = {1, 2 ,3 ,4 ,[5] = 4��2��3��0}�������Ե�6��Ԫ�س�ʼ��4������Ԫ�����α�����ֵ��ʼ�����ұ������һ�γ�ʼ����*/			
	};

	printf("Title: %s\n", library1.title);
	printf("Author: %s\nValue?��", library1.author);
	scanf_s("%f", &library1.value, 10);		
	printf("Value: $%.2f\n", library1.value);

	getchar();
	getchar();
	return 0;
}

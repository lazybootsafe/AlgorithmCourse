#include <stdio.h>

#define SIZE 41

struct book												/*1.�����ṹ���壬�ýṹģ�����������к���֮�⣬
															���ԣ����ı�ǿ��Ա����ļ��и�����֮������к���ʹ��
														  2.book�ǿ�ѡ�ı�ǣ������ڿ��ٷ�������ṹ��
															���ýṹ�Ŀ��ٱ��
															��������Ҫ��������ýṹ���͵ı���ʱ������Ҫʹ�ñ��*/
{
	char title[SIZE];
	char author[SIZE];
	float value;
};

int main(void)
{
	struct book library = {								/*1.��ʼ��һ��book���͵Ľṹ��������һ�Ի������������ġ����ŷָ��ĳ�ʼ����Ŀ�б��ʼ�������ṹ��Ա��
														  2.�ṹ����library�����Զ��洢����������ڵ�C����������洢�࣬ANSI֮ǰ��C���������Զ�������
														  3.��ʼ����Ŀ�б�ĳ�Ա����ƥ��ṹ��Ա����������*/
		"Chicken of the Alps",
		"Bismo Lapoult",
		14.95f
	};

	printf("Title: %s\n", library.title);				//�ṹ��Ա�������(.)���Է��ʽṹ�ĸ�����Ա��library.title��Ա��ʹ��������char []������ͬ
	printf("Author: %s\nValue?��", library.author);		//�ṹ��Ա���������author��Ա��library.author��Ա��ʹ��������char []������ͬ
	scanf_s("%f", &library.value, 10);					/*1.�ṹ��Ա���������value��Ա��library.value��Ա��ʹ��������float������ͬ
														  2.�ṹ��Ա�����(.)�����ȼ����ڵ�ַ�����(&)��
															���� &library.value���ʽ��
																 &(library.value)���ʽһ��*/
	printf("Value: $%.2f\n", library.value);

	getchar();
	getchar();
	return 0;
}
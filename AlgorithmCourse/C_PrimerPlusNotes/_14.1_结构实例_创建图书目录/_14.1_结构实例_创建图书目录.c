#include <stdio.h>
#include <stdlib.h>

#define MAXTITL 41				//��������󳤶�+1
#define MAXAUTL 31				//����������󳤶�+1

//����ṹ���
struct book						//�ṹģ�壬���Ϊbook(�������ѡ���ṩ�˶Ըýṹ�Ŀ��ٷ��ʡ���һ���ýṹ�Ŀ��ٱ��)
{
	char title[MAXTITL];		//member1/field1
	char author[MAXAUTL];		//member2/field2
	float value;				//member3/field3
};								//�ṹģ�����

int main(void)
{
	//����һ���ṹ����
	struct book library;		/*1.��library����Ϊһ��book���͵ı���
								  2.��library����Ϊһ��ʹ��book�ṹ��ƵĽṹ����*/

	system("color 5A");
	printf("Please enter the book title:\n");
	gets_s(library.title, MAXTITL);
	printf("Now enter the author:\n");
	gets_s(library.author, MAXAUTL);
	printf("Now enter the value:\n");
	scanf_s("%f", &library.value, 20);
	printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);

	system("pause");
	return 0;
}
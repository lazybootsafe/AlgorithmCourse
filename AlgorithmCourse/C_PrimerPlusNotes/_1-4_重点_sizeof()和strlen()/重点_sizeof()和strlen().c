#include <stdio.h>
#include <string.h>  //Ŀ�ģ�����ȡ�ַ�������strlen()
#define NUM 56  //����int����
#define STR "Hello"
#define CH 'A'

int main(void)
{
	/*sizeof()�Ǽ��������б�����������ռ�Ĵ���ռ�(����������)
	*strlen()�Ǽ������ֵΪ�����ڴ��ַ����һ�����ַ�'\0'�ľ��룬���ֽ�Ϊ��λ���ַ���β��Ϊ'\0'
	*����⣺
	*sizeof()�����͵ĳ��ȣ�
	*strlen()����Ч�ַ����ĳ��ȣ����������ַ�*/

	int n = 56;
	printf("int n = 56��sizeof��%d\n\n", sizeof(n));

	/*char a[5] = {'a', 'b', 'c', 'd', 'e'};
	printf("char a[5] = \"Hello\"��sizeof��%d\n", sizeof(a));
	printf("char a[5] = \"Hello\"��strlen��%d\n\n", strlen(a));*/

	char m = 'A';
	printf("char m = \'A\'��sizeof��%d\n\n", sizeof(m));  //�ַ���int���ͱ��棬����sizeof(CH)=4

	int array1[50] = { 4, 4, 4, 4 };
	printf("int array1[50]��sizeof��%d\n\n", sizeof(array1)); //int������int���ͱ��棬����sizeof(array)=4*50=200

	long long array2[50] = { 4, 4, 4, 4 };
	printf("long long array2[50]��sizeof��%d\n\n", sizeof(array2));  //long long������int���ͱ��棬����sizeof(array)=8*50=400

	char array3[50] = { 4, 4, 4, 4 };
	printf("char array3[50] = { 4, 4, 4, 4 }��sizeof��%d\n\n", sizeof(array3));
	printf("char array3[50] = { 4, 4, 4, 4 }��strlen��%d\n\n", strlen(array3));

	char *s = "0123456789";
	printf("char *s = \"0123456789\"��sizeof��%d\n\n", sizeof(s));
	printf("char *s = \"0123456789\"��strlen��%d\n\n", strlen(s));

	char ss[] = "0123456789";
	printf("char ss[] = \"0123456789\" ��sizeof��%d\n\n", sizeof(ss));
	printf("char ss[] = \"0123456789\" ��strlen��%d\n\n", strlen(ss));

	getchar();
	return 0;

}
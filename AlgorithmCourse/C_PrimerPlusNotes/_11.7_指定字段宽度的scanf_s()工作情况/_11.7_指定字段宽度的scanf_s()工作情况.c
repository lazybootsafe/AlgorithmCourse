#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char name1[11], name2[11];
	int count;
	
	system("color 0A");
	printf("Please enter 2 names:\n");
	count = scanf_s("%s %s", name1, 6, name2, 11);		/*��Ϊscanf()�İ�ȫ�汾���ú�����ԭ�л����ϻ������Ĵ�С���ƣ����ٵ��ڶ����ֽ���+1*/
	printf("I have read %d names %s and %s\n", count, name1, name2);

	system("pause");
	return 0;
}
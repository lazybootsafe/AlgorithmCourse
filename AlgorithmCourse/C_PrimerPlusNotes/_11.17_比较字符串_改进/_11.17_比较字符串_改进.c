#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSWER "Grant"
#define MAX 41

int main(void)
{
	char try_[MAX];

	puts("Who is bureied in Grant's tomb?");
	gets_s(try_, MAX);
	while (strcmp(try_, ANSWER) != 0)		//strcmp()�Ƚ�2�ַ����Ƿ���ȣ���ȷ���0ֵ,�����ڻ��ָ�jz oprd1, oprd2
	{
		puts("No, that's wrong. Try again.");
		gets_s(try_, MAX);
	}
	puts("That's right.");

	getchar();
	return 0;
}
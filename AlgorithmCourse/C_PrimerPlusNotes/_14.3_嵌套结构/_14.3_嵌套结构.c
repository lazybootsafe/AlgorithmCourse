#include <stdio.h>
#include <stdlib.h>

//ע��;��������ͳ�Ա�����Է��ʽṹ������ָ����Ա

#define LEN 21

const char * msgs[5] = {
	"    Thank you for the wonderful evening, ",
	"You certainly prove that a ",
	"is a special kind of guy. We must get together",
	"over a dicilious ",
	" and hanve a few laughs"
};

struct names				//��һ���ṹ
{
	char first[LEN];
	char last[LEN];
};
struct guy					//�ڶ����ṹ
{
	struct names handle;	//Ƕ�׽ṹ
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	struct guy fellow = {	//��ʼ��һ��guy���͵Ľṹ����
		{ "Ewen", "Villard" },
		"grilled salmon",
		"personality coach",
		58112.00f
	};

	system("color 5A");

	//��ӡ�ŵĿ�ͷ
	printf("Dear %s, \n\n", fellow.handle.first);
	//��ӡ�ŵ�����
	printf("%s%s.\n", msgs[0], fellow.handle.first);
	printf("%s%s\n", msgs[1], fellow.job);
	printf("%s\n", msgs[2]);
	printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
	//��ӡ��ĩ���
	if (fellow.income > 150000.0f)
	{
		puts("!!");
	}
	else if (fellow.income > 75000.0f)
	{
		puts("!");
	}
	else
	{
		puts(".");
	}
	//��ӡ��β
	printf("\n%40s%s\n", " ", "See you soon, ");
	printf("%40s%s\n", " ", "Shalsls");
	
	system("pause");
	return 0;
}
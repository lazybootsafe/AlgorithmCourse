#include <stdio.h>
#include <string.h>

#define LISTSIZE 5

int main(void)
{

	/*��������ĳ��ǰ׺���ַ���ʱ��
	������strncmp()�Ƚ��ַ�����ǰ�����ַ��Ƿ���ͬ�ﵽĿ��*/

	char * list[LISTSIZE] = {
		"astronomy",
		"astounding",
		"astrohpysics",
		"ostracize",
		"asterism"
	};
	int count = 0;

	for (int i = 0; i < LISTSIZE; i++)
	{
		if (strncmp(list[i], "astro", 5) == 0)		//���2���ַ�����ÿһ���ַ���ANSCIIֵ����ȣ����ҵ���astro_ǰ׺�ĵ���ʱ��ӡ����
		{
			printf("Found: %s\n", list[i]);
			count++;
		}
	}
	printf("The list contained %d words beginning"
		" with astro.\n", count);

	getchar();
	return 0;
}
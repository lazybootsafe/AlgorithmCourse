#include <stdio.h>

int main(void)
{
	const int NUMBER = 22;
	
	for (int i = 1; i <= NUMBER; i++)	/*"int i = 1"��ʼ�����ʽ��ѭ����ʼǰִ��һ��
										"i <= NUMBER"�ж���������ÿ��ѭ��֮ǰ��Ҫ������ֵ��
										"i++"���Ʊ����ĸ��£�ÿ��ѭ������ʱ���м���*/
	{
		printf("Be my Valentine!\n");
	}

	getchar();
	return 0;
}
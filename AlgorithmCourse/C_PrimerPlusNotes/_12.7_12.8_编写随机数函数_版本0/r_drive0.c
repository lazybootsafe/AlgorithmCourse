//�������򡢲������������rand0()

#include <stdio.h>
#include <stdlib.h>

extern int rand0(void);			//extern�����ú�����һ���ⲿ�����������ڶԱ������������������������������ļ��ڣ�

int main(void)
{
	int count;

	system("COLOR 0A");
	for (count = 0; count < 5; count++)
	{
		printf("%hd\n", rand0());		//rand0()�ķ���ֵ��0��32767
	}
	
	getchar();
	return 0;
}
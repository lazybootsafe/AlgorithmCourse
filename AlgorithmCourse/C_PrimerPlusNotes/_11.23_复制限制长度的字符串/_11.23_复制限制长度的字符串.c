#include <stdio.h>
#include <string.h>

#define SIZE 40
#define MARGSIZE 7
#define LIM 5

int main(void)
{
	char qwords[LIM][MARGSIZE];
	char temp[SIZE];
	int i = 0;

	printf("Enter %d words bengining with q:\n", LIM);
	while (i < LIM && gets_s(temp, SIZE))
	{
		if (temp[0] != 'q')
			printf("%s doesn't begining with q.\n", temp);
		else
		{
			/*�������ܣ���Դ�ַ�����ǰn���ַ����߿��ַ�֮ǰ�������ַ����������ַ������Ƶ����ռ�ΪSizeInByte��Ŀ���ַ�����
			���Դ�ַ����������ַ�û�г���Ҫ���Ƶ��ַ���n����ֵ����Դ�ַ����������ַ�
			���Դ�ַ����������ַ�����Ҫ���Ƶ��ַ���n����ֻ����ǰn���ַ������Ŀ��ַ�����
			��ʱ����Ҫ��Ŀ���ַ�����β����ӿ��ַ�������ֵ��ȥ��ǰn���ַ���־Ϊ�ַ���*/

			strncpy_s(qwords[i],MARGSIZE ,temp, MARGSIZE - 1);		

			/*������볬��ָ�����ȣ�6������ô�ڿ�����ǰN���ַ�֮�󣬱���
			���ַ���������һ��Ԫ����ֲ����ַ���־һ����Ч���ַ����������ַ�����*/

			qwords[i][MARGSIZE - 1] = '\0';			
			i++;
		}
	}

	printf("Here are the words accepted:\n");
	for (i = 0; i < LIM; i++)
		puts(qwords[i]);

	getchar();
	return 0;
}
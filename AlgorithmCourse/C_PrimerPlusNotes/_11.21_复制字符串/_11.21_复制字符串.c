#include <stdio.h>
#include <string.h>
#include <string.h>

#define SIZE 41
#define ROWS 5
int main(void)
{
	//strcpy_s()�����ַ�������������q��ͷ��5���ַ�����Ŀ��ָ�봦

	char qwords[ROWS][SIZE];
	char temp[SIZE];
	int i = 0;

	system("color 0A");
	
	printf("Enter %d words begin with q: \n", ROWS);
	while (i < ROWS && gets_s(temp, SIZE))
	{
		if (temp[0] != 'q')		
		//������if(strncmp(temp, "q", 1) != 0)
		{
			printf("%s donesn't begin with q.\n", temp);
		}
		else
		{
			strcpy_s(qwords[i], SIZE, temp);	//�����ַ�����������Դ�ִ�������Ŀ���ִ����������СΪҪ�������ַ���+1
			i++;
		}
	}
	printf("Here are the words accepted: \n");
	for (i = 0; i < ROWS; i++)
	{
		puts(qwords[i]);
	}

	getchar();
	return 0;
}
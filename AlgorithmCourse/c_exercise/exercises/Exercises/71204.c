#if 0
#include <stdio.h>

int main(void)
{
	int count = 0;
	char ch;
	while ((ch = getchar()) != '#')	//�˳�����
	{
		if (ch == '!')				//̾��ת˫̾��
		{
			printf("!!");
			count++;
		}
		else if (ch == '.')			//���ת̾��
		{
			printf("!");
			count++;
		}
		else
			printf("%c", ch);
	}
	printf("\nTotal replace %d times\n", count);

	return 0;
}

#endif
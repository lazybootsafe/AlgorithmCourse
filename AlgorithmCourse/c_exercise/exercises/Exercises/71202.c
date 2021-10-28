#if 0

#include <stdio.h>

int main(void)
{
	int count = 0;
	char ch;
	while ((ch = getchar()) != '#')	//退出条件
	{
		if (count++ % 8 == 0)	//每打印八个字符后换行
			printf("\n");
		if (ch == '\n')			//打印换行十进制码
			printf("'\\n'-%03d. ", ch);
		else if (ch == '\t')	//打印制表符十进制码
			printf("'\\t'-%03d. ", ch);
		else
			printf("'%c'-%03d. ", ch, ch);	//打印字符十进制码
	}

	return 0;
}

#endif
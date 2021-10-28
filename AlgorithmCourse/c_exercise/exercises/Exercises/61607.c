#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char words[30];
	printf("Enter the word: ");
	//scanf_s("%s", &words, 29);	//无法读取空格
	gets_s(words, 30);
	printf("You enter is: %s\n", words);
	printf("The reverse word is: ");
	//-1去掉杠零
	for (int i = strlen(words) - 1; i >= 0; i--)
		printf("%c", words[i]);

	return 0;
}

#endif
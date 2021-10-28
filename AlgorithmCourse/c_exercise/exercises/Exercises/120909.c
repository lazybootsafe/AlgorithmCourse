#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int amount = 0;
	char **word = NULL;

	printf("How many words do you wish to enter? ");
	scanf_s("%d", &amount);
	printf("Enter %d words now: ", amount);
	word = (char**)malloc(sizeof(char*)*amount);
	for (int i = 0; i < amount; i++)
	{
		char tmp[100];
		scanf_s("%s", tmp, 100);
		int length = strlen(tmp);
		char* str = (char*)malloc(sizeof(char)*length);
		strcpy_s(str, length + 1, tmp);
		*(word + i) = str;
	}
	puts("Here are you word:");
	for (int i = 0; i < amount; i++)
		puts(word[i]);

	free(word);
	return 0;
}

#endif
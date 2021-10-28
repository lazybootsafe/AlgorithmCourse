#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char array[26];
	char ch = 'a';
	for (int i = 0; i < 26; i++)
	{
		array[i] = ch;
		ch++;
	}
	for (int i = 0; i < 26; i++)
		printf("%c ", array[i]);

	return 0;
}

#endif
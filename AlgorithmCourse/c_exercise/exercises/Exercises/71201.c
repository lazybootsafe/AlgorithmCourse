#if 0
#include <stdio.h>
#include <iso646.h>

int main(void)
{
	int nLine = 0;
	int nChar = 0;
	int nSpace = 0;
	int nOther = 0;
	char cChar;

	while ((cChar = getchar()) != '#')
	{
		if ((cChar > 64 && cChar < 91) || (cChar > 96 && cChar < 123))
			nChar++;
		else if (cChar == ' ')
			nSpace++;
		else if (cChar == '\n')
			nLine++;
		else
			nOther++;
	}
	printf("��ĸ��%d��\n�ո�%d\n���У�%d\n������%d\n", nChar, nSpace, nLine, nOther);

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int start = 1;
	int end = 100;
	int guess = (end + start) / 2;
	int sum = 0;
	char c;
	printf("Pick and integer from 1 to 100. I will try to guess ");
	printf("it.\nRespond with a y if my guess is right and with\n");
	printf("an n  if it is wrong.\n");

	printf("Un...is your number %d?\n", guess);
	printf("Tell me %d is larger or smaller than yours?(l or s): ", guess);
	while ((c = getchar()) != 'y')
	{
		sum++;
		switch (c)
		{
		case 's':
		case 'S':
			start = guess + 1;
			guess = (start + end) / 2;
			break;
		case 'l':
		case 'L':
			end = guess - 1;
			guess = (start + end) / 2;
			break;
		default:
			break;
		}
		printf("Un...is your number %d?\n", guess);
		printf("Tell me %d is larger or smaller than yours?(l or s): ", guess);
		getchar();
		if (c == 'Y')
			break;
	}
	printf("I guess %d\n", sum);
	printf("I knew I could do it!\n");

	return 0;
}

#endif
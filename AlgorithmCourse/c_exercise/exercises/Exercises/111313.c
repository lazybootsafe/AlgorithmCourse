#if 0
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//for (int i = argc - 1; i > 0; i--)
	//{
	//	printf("%s ", argv[i]);
	//}
	if (argc < 2)
		puts("Error, not enough parameter to display!");
	else
		for (int i = argc; i > 1; i--)
			printf("%s ", argv[i - 1]);
	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bstr_to_dec(char *pbin)
{
	int num = 0;
	int len = strlen(pbin);

	for (int i = 0; i < len; i++)
	{
		num = num * 2 + (pbin[i] - '0');
	}

	return num;
}
int main(int argc, char *argv[])
{
	unsigned int number1 = 0;
	unsigned int number2 = 0;

	if (argc != 3)
	{
		printf("Usage: binary_string binarg_string\n");
		return 0;
	}

	number1 = bstr_to_dec(argv[1]);
	number2 = bstr_to_dec(argv[2]);

	int nega_number1 = ~number1;
	int nega_number2 = ~number2;

	// printf没有二进制输出，使用十六进制输出，将就看吧
	printf("The negative of %s and %s are %x and %x\n",
		argv[1], argv[2], nega_number1, nega_number2);

	int and = number1 & number2;
	printf("%s & %s = %x\n", argv[1], argv[2], and);

	int or = number1 | number2;
	printf("%s | %s = %x\n", argv[1], argv[2], or );

	int xor = number1 ^ number2;
	printf("%s ^ %s = %x\n", argv[1], argv[2], xor);

	return 0;
}

#endif

//#if 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#define LEN 32
//#define UINT unsigned int
//int bstoi(char *st);
//char *itobs(char *st, int n);
//
//int main(int argc, char *argv[])
//{
//	if (argc != 3)
//	{
//		printf("Usage:%s binary string binary string.\n", argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	char bs[LEN] = { 0 };
//	int result = 0;
//	result = (~bstoi(argv[1]));
//	itobs(result, bs);
//	printf("~%s result is: %s\n", argv[1], bs);
//	
//	result = (~bstoi(argv[2]));
//	itobs(result, bs);
//	printf("~%s result is: %s\n", argv[2], bs);
//
//	result = (bstoi(argv[1]) & bstoi(argv[2]));
//	itobs(result, bs);
//	printf("%s & %s result is: %s\n", argv[1], argv[2], bs);
//
//	result = (bstoi(argv[1]) | bstoi(argv[2]));
//	itobs(result, bs);
//	printf("%s | %s result is: %s\n", argv[1], argv[2], bs);
//
//	result = (bstoi(argv[1]) ^ bstoi(argv[2]));
//	itobs(result, bs);
//	printf("%s ^ %s result is: %s\n", argv[1], argv[2], bs);
//
//
//	return 0;
//}
//
//int bstoi(char *st)
//{
//	int sum = 0;
//	while (*st != '\0')
//	{
//		sum *= 2;
//		if (*st != '0' && *st != '1')
//		{
//			printf("The argument should be binary.\n");
//			exit(EXIT_FAILURE);
//		}
//		sum += *st++ - '0';
//	}
//	return sum;
//}
//
//char *itobs(char *st, int n)
//{
//	const static int size = CHAR_BIT * sizeof(int);
//	for (int i = 0; i >= 0; i--, n >>= 1)
//		st[i] = (01 & n) + '0';
//	st[LEN] = '\0';
//	return st;
//}
//
//#endif // 1
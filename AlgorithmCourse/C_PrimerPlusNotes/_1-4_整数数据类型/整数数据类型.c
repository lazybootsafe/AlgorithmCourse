#include <stdio.h>

int main(void)
{
	unsigned int un = 3000000000;			//(unsigned)int���ֽ�32λ
	//printf("%d\n", sizeof(unsigned int));  4
	short end = 200;						//short���ֽ�16λ��
	//printf("%d\n", sizeof(short));	2
	long big = 65537;						//long���ֽ�32λ
	//printf("%d\n", sizeof(long));  4
	long long verybig = 12345678765433345632;		//long long���ֽ�64λ
	//printf("%\nd", sizeof(long long));  8

	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and not %d\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("verybig = %lld and not %ld\n", verybig, verybig);
	printf("\n���ݵĴ洢��Χ��С������ short16λ<int32λ=long32λ<long long64λ");
	getchar();
	return 0;

}
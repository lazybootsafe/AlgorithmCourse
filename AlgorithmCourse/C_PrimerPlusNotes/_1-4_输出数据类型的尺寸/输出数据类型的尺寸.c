#include <stdio.h>

int main(void)
{
	//��������֧�ֵ��������ͳߴ�ĸ�ʽ˵����Ϊ%u(Ҳ������%d��ӡ�������ͳߴ�)
	printf("Type int has a size of %u bytes.\n", sizeof(int));
	printf("Type short has a size of %u bytes.\n", sizeof(short));
	printf("Type long has a size of %u bytes.\n", sizeof(long));
	printf("Type char has a size of %u bytes.\n", sizeof(char));
	printf("Type float has a size of %u bytes.\n", sizeof(float));
	printf("Type double has a size of %u bytes.\n", sizeof(double));
	printf("Type long double has a size of %d bytes.\n", sizeof(long double));

	getchar();
	return 0;

}

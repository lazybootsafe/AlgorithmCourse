#include <stdio.h>
#include <stdlib.h>

#define PSQR(X) printf("The square of " #X " is %d.\n", ((X)*(X)))

//�ں꺯���У����X��һ�����������ô#X�Ϳ��԰Ѻ����ת��Ϊ��Ӧ���ַ�����������̳�Ϊ�ַ�������stringgizing����
int main(void)
{
	int y = 5;

	system("color 0A");

	PSQR(y);		//��һ�ε��ú�ʱ���á�y������#X
	PSQR(2 + 4);	//�ڶ��ε��ú�ʱ���á�2 + 4������#X
					//Ȼ��ANSI C���ַ������ӹ��ܽ���Щ�ַ�������Ϊprintf�������ĸ�ʽ�ַ���
	getchar();
	return 0;
}
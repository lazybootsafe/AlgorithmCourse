#include <stdio.h>
#include <stdlib.h>

#define SIZE 81

int main(int argc, char * argv[])
{
	int ch;												//��ȡʱ�洢ÿ���ַ���λ��
	FILE * fp;											//�ļ�ָ��
	long count = 0;
	errno_t err;
	char file[SIZE];

	system("color 5A");
	printf("Enter file name to read:\n");
	gets_s(file, SIZE);
	if ((err = fopen_s(&fp, file, "rb")))				//ֻ����ʽ���ļ�����ô������˳���
	{
		printf("Can't open file.\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);									//����ַ�����׼�����
		count++;
	}
	fclose(fp);
	printf("\nFile has %d characters.\n", count);

	getchar();
	return 0;
}

//�����л����£��ṩ�����в�����ָ���ļ�������

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int ch;												//��ȡʱ�洢ÿ���ַ���λ��
	FILE * fp;											//�ļ�ָ��
	long count = 0;
	errno_t err;

	system("color 5A");
	if (argc != 2)										//û�������в���ʱ,�쳣�˳�
	{
		printf("Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((err = fopen_s(&fp, argv[1], "rb")))				//ֻ����ʽ���ļ�����ô������˳���
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
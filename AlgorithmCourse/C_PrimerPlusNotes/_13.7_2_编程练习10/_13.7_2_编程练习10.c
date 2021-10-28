
/*������ȡ�ļ�������һ��ѭ�����ȡ�ļ����Ķ�λ�ã���ӡ��λ�õ���ĩ���ַ�
�û����������λ���˳�ѭ��*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 81
#define LSIZE 256

int main(void)
{
	char file[SIZE];
	FILE * fp;
	int index;
	int last;
	long pos;
	char line[LSIZE];

	system("color 5A");
	puts("Enter a file name to access:");
	gets_s(file, SIZE);
	if (fopen_s(&fp, file, "rb") != 0)
	{
		fprintf(stderr, "Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	printf("Input index to read content of the file ( 0 - %d , q to quit):\n", last - 1);
	while (scanf_s("%d", &index) == 1)
	{
		if (index < 0 || index > last)
		{
			fprintf(stderr, "No valid index!\n");
			continue;
		}
		pos = index * sizeof(char);
		fseek(fp, pos, SEEK_SET);
		fgets(line, LSIZE, fp);
		fputs(line, stdout);	//��Ȼ�Ƕ����������ں�\r�ַ���������ִ�����Ӱ�죨��ĩ�Ļس���ֻ�ǽ�����Ƶ����ף����Ļ��з��ٽ�����Ƶ���һ�����ף���ʾ��Ϣ����һ���������Ӱ��������ļ����ݣ�
		printf("Next index( 0 - %d , q to quit):\n", last - 1);
	}
	puts("GOOD BYE!");
	system("pause");
	return 0;
}
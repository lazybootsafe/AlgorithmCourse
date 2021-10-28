#include <stdio.h>
#include <stdlib.h>

#define SIZEAR 1000

int main(int argc, char * argv[])
{
	/*�����ȡ�����ʹ�ö�����IOд��Ķ������ļ���
	�����ܣ�����һ��double������ֵ���ļ��������û������ļ��ڵ���ֵ����
	
	ע�⣺�ļ�IO����ö�����ģʽ�򿪡�������IO��������IO��Ҳ�ṩ���ļ���λ����׼ȷ�ֽڼ���ֵ*/

	double numbers[SIZEAR];
	double value;
	const char * file = "numbers.dat";
	int i;
	long pos;
	FILE * iofile;

	system("COLOR 0A");
	//����double����
	for (i = 0; i < SIZEAR; i++)
	{
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	}

	//���Դ��ļ���w��ʽ�򿪶���������
	if (fopen_s(&iofile, file, "wb") != 0)
	{
		fprintf(stderr, "Can't open %s for output.\n", file);
		exit(EXIT_FAILURE);
	}

	//�����������Զ�������ʽд���ļ�
	fwrite(numbers, sizeof(double), SIZEAR, iofile);
	if (ferror(iofile) != 0)
	{
		fprintf(stderr, "Error in writing %s.\n", file);
		exit(EXIT_FAILURE);
	}
	fclose(iofile);

	//�򿪶�������������rģʽ
	if (fopen(&iofile, file, "rb") != 0)
	{
		fprintf(stderr, "Can't open %s for random access.\n", file);
		exit(EXIT_FAILURE);
	}

	//��ȡ�±�
	printf("Enter an index in 0 - %d:\n", SIZEAR - 1);
	scanf_s("%d", &i, 10);

	//�±���������ʱ����λ��ָ��λ�ã���������ʽȡ��һ��doubleֵ
	while (i >= 0 && i < SIZEAR)
	{
		pos = (long)i * sizeof(double);			//����ƫ����
		fseek(iofile, pos, SEEK_SET);			//��λ��ָ��ƫ�ƴ�
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f\n", value);
		printf("Next index (out of range < 0 - %d> to quit):\n", SIZEAR - 1);
		scanf_s("%d", &i, 10);
	}
	fclose(iofile);
	puts("Bye!");

	system("pause");
	return 0;
}
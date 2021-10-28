#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define LSIZE 81

void append(FILE * src, FILE * dest);

int main(void)
{
	FILE * fa, * fs;					//faָ��׷�ӵ�Ŀ���ļ���fsָ��Դ�ļ�
	int files = 0;						//Դ�ļ�������
	char fname_a[LSIZE];
	char fname_s[LSIZE];

	system("color 0A");
	puts("������ҪΪ��׷�����ݵ�Ŀ���ļ���:");
	gets_s(fname_a, LSIZE);

	//��Ŀ���ļ�
	if (fopen_s(&fa, fname_a, "w") != 0)		//׷�ӷ�ʽ���ı���(�����)
	{
		fprintf(stderr, "�ļ�\"%s\"��ʧ�ܣ�\n", fname_a);
		exit(EXIT_FAILURE);
	}
	
	//�ڶ���������в���֮ǰ������������
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("�������������ʧ�ܣ�\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("������Դ�ļ�����������н�����");
	while (gets_s(fname_s, LSIZE) != NULL && fname_s[0] != '\0')
	{
		if (strcmp(fname_a, fname_s) == 0)
		{
			fputs("���棡�޷����ļ�����׷�����ݣ�\n", stderr);
		}
		else if (fopen_s(&fs, fname_s, "r") != 0)	//ֻ����ʽ���ı���(������)
		{
			fprintf(stderr, "�ļ�\"%s\"��ʧ�ܣ�\n", fname_s);
			exit(EXIT_FAILURE);
		}
		else
		{
			//�ڶ����������в���֮ǰ������������
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("���뻺��������ʧ�ܣ�\n", stderr);
				continue;
			}

			//��ʼ׷��
			append(fs, fa);

			//����д����
			if (ferror(fs) != 0)
			{
				fprintf(stderr, "��ȡ�ļ�\"%s\"����\n", fname_s);
			}
			if (ferror(fa) != 0)
			{
				fprintf(stderr, "��д�ļ�\"%s\"����\n", fname_a);
			}
			fclose(fs);
			files++;
			printf("��%d�����ļ�\"%s\"׷��������ϣ�\n", files, fname_a);
			puts("��������һ��Ŀ���ļ���:");
		}
	}
	fclose(fa);
	printf("���ļ�\"%s\"׷�����ݽ�����\n", fname_a);

	system("pause");
	return 0;
}

void append(FILE * src, FILE * dest)
{
	size_t bytes;
	static char temp[BUFSIZE];				//����һ�Σ���̬�洢

	//������I/O
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, src)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, dest);
	}
}
#include <stdio.h>
#include <stdlib.h>

// �ַ���
void getC(FILE *f)
{
	int letter = 0, num = 0;
	while (!feof(f)) {
		letter = fgetc(f);
		if (letter == '\n') {
			continue;
		}
		num++;
	}
	printf("\n���ַ�����: %d\n", num - 1);
}

// ����
void getW(FILE *f)
{
	int letter = 0, word = 0;
	int mark = 0;
	while (!feof(f)) {
		letter = fgetc(f);
		if ((letter >= 'a'&&letter <= 'z') || (letter >= 'A'&&letter <= 'Z') || letter == '_') {
			if (mark == 0)
				mark = 1;
		} else if (letter == '.') {
			continue;
		} else {
			if (mark == 1) {
				word++;
				mark = 0;
			} else {
				continue;
			}
		}	
	}
	printf("\n��������: %d\n", word);
}

// ����
void getL(FILE *f)
{
	int letter = 0, line = 0;
	int mark = 0;
	while (!feof(f)) {
		letter = fgetc(f);
		if (letter == '\n') {
			line++;
		}	
	}
	printf("\n��������: %d\n", line);
}

// ������
int main(int argc, char *argv[]) {
	char com;
	FILE * fp = NULL;
	char* func = (char*)malloc(sizeof(char) * 50);
	if (argv[2] != NULL && argv[1] != NULL) {
		fp = fopen(argv[2], "r");
		func = argv[1];
		com = func[1];
		if (fp == NULL)
		{
			printf("\n������: �ļ���ʧ��\n");
			exit(1);
		}
	} else {
		printf("\n������: �����������\n");
		return 0;
	}
	if (com == 'c')
		getC(fp);
	else if (com == 'w')
		getW(fp);
	else if (com == 'l')
		getL(fp);
	else {
		printf("\n������: ��������\n");
		return 0;
	}	
	rewind(fp);
	return 0;
}
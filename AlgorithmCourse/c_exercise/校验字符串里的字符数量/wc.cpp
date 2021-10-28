#include <stdio.h>
#include <stdlib.h>

// 字符数
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
	printf("\n【字符数】: %d\n", num - 1);
}

// 词数
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
	printf("\n【词数】: %d\n", word);
}

// 行数
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
	printf("\n【行数】: %d\n", line);
}

// 主程序
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
			printf("\n【错误】: 文件打开失败\n");
			exit(1);
		}
	} else {
		printf("\n【错误】: 参数输入错误\n");
		return 0;
	}
	if (com == 'c')
		getC(fp);
	else if (com == 'w')
		getW(fp);
	else if (com == 'l')
		getL(fp);
	else {
		printf("\n【错误】: 错误输入\n");
		return 0;
	}	
	rewind(fp);
	return 0;
}
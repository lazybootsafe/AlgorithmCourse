#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 81

typedef void(*V_FP_CHARP)(char *);				//���庯��ָ��������

int showmenu(void);
void eatline(void);								//�޳�ʣ����
void show(V_FP_CHARP fp, char *);
void ToUpper(char *);							//���ַ���ת��Ϊ��д
void ToLower(char *);							//���ַ���ת��ΪСд
void Transpose(char *);							//��Сдת��
void Dummy(char *);								//���ı��ַ���

int main(void)
{
	char line[SIZE];
	char copy[SIZE];
	int choice;
	V_FP_CHARP pfun[4] = { ToUpper, ToLower, Transpose, Dummy };		//����ָ�빹�ɵ�ָ������

	system("color 0A");
	puts("Enter a string (empty to quit):");
	while (gets_s(line, SIZE) && line[0] != '\0')
	{
		choice = showmenu();
		while (choice >= 0 && choice <= 3)
		{
			strcpy_s(copy, SIZE, line);			//Ϊshow����һ�ݿ����Թ��޸ģ�Դ�ִ������޸ģ�Ҫ�����´����µĿ������ÿ�����ȥ�޸Ĵ���������ʵ���˶�һ���ִ��Ķ�β�ͬ����		
			show(pfun[choice], copy);			//ִ���û�ѡ��Ĳ�ͬ����
			choice = showmenu();
		}
		puts("Enter a string (empty to quit):");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

int showmenu(void)
{
	char ans;
	int result;

	puts("Enter menu choice:");
	puts("u) uppercase l) lowercase");
	puts("t) transpose o) original case");
	puts("n) next string");
	ans = getchar();
	ans = tolower(ans);
	eatline();
	while (strchr("ulton", ans) == NULL)
	{
		puts("please enter a u, l, t, o, or n:");
		ans = tolower(getchar());
		eatline();
	}
	switch (ans)						//switch���
	{
	case 'u':result = 0; break;
	case 'l':result = 1; break;
	case 't':result = 2; break;
	case 'o':result = 3; break;
	case 'n':result = -1; break;
	}

	return result;
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		continue;
	}
}

void ToUpper(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char * str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char * str)
{
	while (*str)
	{
		if (islower(*str))
		{
			*str = toupper(*str);
		}
		else if (isupper(*str))
		{
			*str = tolower(*str);
		}
		str++;
	}
}

void Dummy(char * str)
{
	//���ı��ִ�
}

void show(V_FP_CHARP fp, char * str)
{
	(*fp)(str);
	puts(str);
}
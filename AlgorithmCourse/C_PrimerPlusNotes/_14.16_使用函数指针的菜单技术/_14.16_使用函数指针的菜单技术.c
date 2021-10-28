#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 81
typedef void(*V_FP_CHARP)(char *);				//void(*)(char *)����typedefΪV_FP_CHARP
 
char showmenu(void);
void eatline(void);								//�޳�ʣ����

void show(V_FP_CHARP fp, char *);
//void show(void(*fp)(char *), char * str);		//���ܺ���ָ����ַ�ָ����Ϊ����

void ToUpper(char *);							//���ַ���ת��Ϊ��д
void ToLower(char *);							//���ַ���ת��ΪСд
void Transpose(char *);							//��Сдת��
void Dummy(char *);								//���ı��ַ���

int main(void)
{
	char line[SIZE];
	char copy[SIZE];
	char choice;
	V_FP_CHARP pfun;							/*����ָ��pfun(�ȼ���void(*pfun)(char *);)
												(ָ��ĺ�������һ��char *������
												����û�з���ֵ)*/
		
	system("color 0A");
	puts("Enter a string (empty to quit):");
	while (gets_s(line, SIZE) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)						//switch��������ú���ָ��
			{
			case 'u':pfun = ToUpper; break;
			case 'l':pfun = ToLower; break;
			case 't':pfun = Transpose; break;
			case 'o':pfun = Dummy; break;
			}
			strcpy_s(copy, SIZE, line);			//Ϊshow����һ�ݿ����Թ��޸ģ�Դ�ִ������޸ģ�Ҫ�����´����µĿ������ÿ�����ȥ�޸Ĵ���������ʵ���˶�һ���ִ��Ķ�β�ͬ����		
			show(pfun, copy);					//ִ���û�ѡ��Ĳ�ͬ����
		}
		puts("Enter a string (empty to quit):");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

char showmenu(void)
{
	char ans;

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

	return ans;
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
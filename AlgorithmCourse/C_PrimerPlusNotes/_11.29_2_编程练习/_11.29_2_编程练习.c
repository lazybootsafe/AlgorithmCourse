#include <stdio.h>		//��׼I/Oͷ�ļ�
#include <string.h>		//�ַ���������
#include <stdlib.h>		//��׼��ͷ�ļ���atoi, atol, atof, strtol, strtoul, strtod, ...��
#include <ctype.h>		//Cϵ���ַ�����
#include <stdbool.h>	//����C++����׼����ͷ�ļ�

#define ANSWER "GRANT"
#define MAX 81
#define LIM 10

char * pr(char * str);
int readintput(char * str);
void readword(char * str);
int _strlen(const char * str);
char * _strchr(char * str, char ch);
char getfirst(void);
char * _strncpy(char * dest, rsize_t sizeinbyte, char * src, rsize_t MaxCount);
rsize_t get_min(rsize_t a, rsize_t b, rsize_t c);

int main(void)
{
	system("color 4A");

	//1.�ӵ�һ���𣬴�ӡ���1���ַ�����һ�д�ӡ���2���ַ�������һ�д�ӡ���3���ַ����Դ����ƣ�ֱ����ӡ�������ַ���Ϊֹ
	/*char str[]= "Fummy";
	char *p = str + strlen(str);

	while (--p >= str)
	{
	puts(p);
	}*/

	//2.�ַ������±���3�������ַ�ԭ�����������������ַ���ǰһ��ANSCII�ַ�
	/*char x[] = "Mingcxxsdfadsf";
	int i = 0;

	while (i < sizeof(x))
	{
	if (x[i] % 3 == 0)
	putchar(x[i]);
	else
	putchar(--x[i]);
	i++;
	}*/

	//3.�Ľ�_11.17,�ж����룬���Դ�Сд
	/*char try_[MAX];
	int i = 0;

	puts("Who is bureied in Grant's tomb?");
	gets_s(try_, MAX);
	while (try_[i])
	{
	try_[i] = toupper(try_[i]);
	i++;
	}
	while (strcmp(try_, ANSWER) != 0)
	{
	puts("No, that's wrong. Try again.");
	gets_s(try_, MAX);
	}
	puts("That's right.");*/


	//4.��ȡN���ַ�������
	/*char str[MAX];
	int count;

	puts("Enter some characters:");
	readintput(str);
	printf("Here's read string:\n%s\n", str);*/


	//5.����һ�е��׸�����
	/*char str[MAX];
	int count;

	puts("Enter a line sentence:");
	readword(str);
	printf("This is the first word:\n%s\n", str);*/

	//6.��дstrchr()
	/*char str[MAX] = "FishC.com", ch;
	char * ptr;

	puts("Enter a character to seek for its position");
	printf("from \"%s\" ( press | to quit): \n", str);
	while ((ch = getfirst()) != '|')
	{
	ptr = _strchr(str, ch);
	if (ptr)
	{
	printf("The index position of \"%c\" <%p> from \"%s\" <%p> is %d\n", ch, ptr, str, str, ptr - str);		//ָ��ֵ��ֱ�ۣ���ת��Ϊ���ƫ��
	}
	else
	{
	puts("Don't find it!");
	}
	puts("Enter next ( | to quit):");
	}
	puts("Bye!");*/


	//7.��дstrchr()
	/*char str[MAX] = "FishC.com", ch;
	char * ptr;

	puts("Enter a character to seek for its position");
	printf("from \"%s\" ( press | to quit): \n", str);
	while ((ch = getfirst()) != '|')
	{
	ptr = _strchr(str, ch);
	if (ptr)
	{
	puts("Find it!");
	}
	else
	{
	puts("Don't find it!");
	}
	puts("Enter next ( | to quit):");
	}
	puts("Bye!");*/


	//8.��дstrncpy_s()
	char dest[MAX], src[MAX / 2];
	char * ptr;

	printf("Enter a line (empty to quit and length must be not more than %d):\n", MAX);
	while (gets_s(src, MAX) && src[0] != '\0')
	{
		ptr = _strncpy(dest, MAX, src, 4);
		puts(ptr);
		puts("Enter next (empty to quit):");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

//���ַ�������ĩ�ַ������������ַ����Գƴ�ӡ
char * pr(char * str)
{
	char * ptr = str;

	while (*ptr)
	{
		putchar(*ptr++);
	}
	do
	{
		putchar(*--ptr);
	} while (ptr - str);

	return ptr;
}

//�Զ���strlen()�����������ַ���
int _strlen(const char * str)

{
	const char * ptr = str;
	int c = 0;

	while (*ptr)
	{
		c++;
		ptr++;
	}

	return c;
}

//����LIM���ַ����һ���հ׷�ʱ��ֹ��ȡ�����ַ����浽����
int readintput(char * str)
{
	char ch;
	int count = 0;

	while (count < LIM && !isblank(ch = getchar()))
	{
		str[count] = ch;
		count++;
	}
	str[count] = '\0';		//��ʶ�ַ���

	return count;
}

//��ȡ����ĵ�һ������
void readword(char * str)
{
	char ch;
	int count = 0;

	//��ʾ�û�����ǿյ���
	while (!isalpha(ch = getchar()))
	{
		puts("Please enter the first no-space character......");
	}
	//д���һ����ĸ�ַ�
	str[0] = ch;
	count++;
	//������ȡ��ĸ�ַ�
	while (isalpha(ch = getchar()))
	{
		str[count] = ch;
		count++;
	}
	str[count] = '\0';		//��ʶ�ַ���
}

//�Զ���strchr()
char * _strchr(char * str, char ch)
{
	char *ptr = str;
	while (*ptr && *ptr != ch)
	{
		ptr++;
	}

	return (*ptr == ch ? ptr : NULL);		//�ҵ��ͷ���ָ����ַ���ָ�룬ô�ҵ����ؿ�ָ��
}

//��ȡ���ַ�
char getfirst(void)
{
	char ch = getchar();
	while (getchar() != '\n')
	{
		;
	}

	return ch;
}

//�����Զ���strchr()������
bool is_within(const char ch, char * str)
{
	//��1�����ü��strchr()����ֵ
	return (strchr(str, ch) ? true : false);

	//��2��ָ������������ַ���
	/*char * ptr = str;

	while (*ptr && *ptr != ch)
	{
	ptr++;
	}

	return (*ptr == ch ? true : false);*/

	//��3:����취Ҳ�ܰ������ü��strrchr()����ֵ(^_^)
	//return (strrchr(str, ch) ? true : false);

	//��4:ָ�뻻���飬��2��һ�䣬�㶮��...
}

//�Զ���strncpy()
char * _strncpy(char * dest, rsize_t sizeinbyte, char * src, rsize_t MaxCount)
{
	rsize_t count;

	count = get_min(MaxCount, strlen(src), sizeinbyte);		//ȡ��󿽱����ȡ�Դ�ַ������ȡ���Ŀ���ַ������ȵ���СֵΪʵ�ʿ�������
	for (rsize_t i = 0; i < count; i++)
		dest[i] = src[i];

	for (rsize_t i = count; i < sizeinbyte; i++)
	{
		dest[i] = '\0';									//�����ַ�������ȥ����ѭ����dest[count] = '\0'��ʶ��Ч�ַ�����
	}

	return dest;
}

//
rsize_t get_min(rsize_t a, rsize_t b, rsize_t c)
{
	rsize_t min;

	if (a > b)
	{
		min = b;
	}
	else
	{
		min = a;
	}
	if (min > c)
	{
		min = c;
	}

	return min;
}
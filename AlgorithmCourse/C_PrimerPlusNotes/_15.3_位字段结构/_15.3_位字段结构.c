#include <stdio.h>
#include <stdlib.h>

//�Ƿ�͸�����Ƿ�ɼ�
#define YES		1
#define NO		0

//�߿�����ʽ
#define SOLID	0
#define DOTTED	1
#define DASHED	2

//��ԭɫ
#define BLUE	4
#define GREEN	2
#define RED		1

//�����ɫ
#define BLACK	0
#define YELLOW	(RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN	(GREEN | BLUE)
#define WHITE	(RED | GREEN | BLUE)

/*	λ�ֶνṹ;
	��λ���в����ĵڶ��ַ�����λ�ֶΡ�
	λ�ֶ���һ��signed int��unsigned int��һ�����ڵ�λ��C99��׼������_Bool����λ�ֶΣ���
	λ�ֶ���һ���ṹ�����������ýṹ����Ϊÿ���ֶ��ṩ��ǩ���������ֶεĿ��*/

struct box_props							//����λ�ֶεĽṹģ�壨ռ��һ��int�Ĵ洢�ռ��С��
{
	unsigned int opaque			: 1;
	unsigned int fill_color		: 3;
	unsigned int				: 4;		//ʹ��δ�������ֶο�����δ�����Ķ���ʹ�ÿ��Ϊ0��δ�����ֶν���ʹ��һ�ֶ�����һ�������룩
	
	//δ�����ֶε����ʹ��������йص���Ϣ����һ���ֽ��У���߿��йص���Ϣ������һ�ֽ���

	unsigned int show_border	: 1;
	unsigned int border_color	: 3;
	unsigned int border_style	: 2;
	unsigned int				: 2;
};

const char * colors[] = { "black", "red", "green", "yellow", 
						"blue", "magenta", "cyan", "white" };

void show_settings(const struct box_props * ps);

int main(void)
{
	/*�����ͳ�ʼ��box_props�ṹ*/
	struct box_props box = { YES, YELLOW, YES, GREEN, DASHED };

	system("color 0A");
	printf("Original box settings:\n");
	show_settings(&box);

	box.opaque = NO;
	box.border_color = MAGENTA;
	box.border_style = SOLID;
	printf("\nModefied box setting:\n");
	show_settings(&box);

	getchar();
	return 0;
}

void show_settings(const struct box_props * ps)
{
	printf("Box is %s.\n", 
		ps->opaque == YES ? "opaque" : "transparent");
	printf("The fill color is %s.\n", colors[ps->fill_color]);
	printf("Border %s.\n",
		ps->show_border == YES ? "shown" : "not shown");
	printf("The border color is %s.\n", colors[ps->border_color]);
	printf("The border style is ");
	switch (ps->border_style)
	{
	case SOLID:
		printf("solid.\n"); 
		break;
	case DOTTED:
		printf("dotted.\n");
		break;
	case DASHED:
		printf("dashed.\n");
		break;
	default:
		printf("unknown type.\n");
		break;
	}
}
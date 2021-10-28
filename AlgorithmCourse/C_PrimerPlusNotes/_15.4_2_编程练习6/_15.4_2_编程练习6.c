/*
	���һ��λ�ֶνṹ�����洢һ����Ϣ��
	Font ID��0-255֮���һ����
	Font Size:0-127֮���һ����
	Bold: Off �� on
	Italic: Off �� on
	Underline: Off �� on
	�ڳ�����ʹ������ṹ����ʾ�����������ʹ��ѭ���Ĳ˵������û��ı���������磬�����һ������ʾ�����£�
	ID SIZE ALIGNMENT B I U
	1 12 left off off off
	
	f)change font s)change size a)change alignment
	b)toggle bold i)toggle italic u)toggle underline
	q)quit
	s
	Enter fonr size (0-127): 36

	ID SIZE ALIGNMENT B I U
	1 12 left off off off
	f)change font s)change size a)change alignment
	b)toggle bold i)toggle italic u)toggle underline
	q)quit
	a
	Select alignment:
	l)left c)center r)right
	r
	
	ID SIZE ALIGNMENT B I U
	1 12 left off off off
	f)change font s)change size a)change alignment
	b)toggle bold i)toggle italic u)toggle underline
	q)quit
	i
	
	ID SIZE ALIGNMENT B I U
	1 12 left off off off
	f)change font s)change size a)change alignment
	b)toggle bold i)toggle italic u)toggle underline
	q)quit
	q
	Bye!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//alignmentֵ
#define LEFT 0
#define CENTER 1
#define RIGHT 2

//B��I��Uֵ
#define OFF 0
#define ON 1

#define ID_MASK 0xFF
#define SIZE_MASK 0x7F

enum choice
{
	f = 'f',
	s = 's',
	a = 'a',
	b = 'b',
	i = 'i',
	u = 'u',
	q = 'q'
};

typedef enum choice CHOICE;

struct _font					//ע�⣬λ�ֶνṹʹ��unsigned int��Ϊ�������ֵ�Ԫ
{
	unsigned int ID : 8;		//��һ�ֽڴ��ID
	unsigned int size : 7;		//�ڶ��ֽڴ��size
	unsigned int : 1;
	unsigned int alignment : 2;	//�����ֽڴ��alinment
	unsigned int : 6;	
	unsigned int bold : 1;		//�����ֽڴ��B��I��U
	unsigned int italic : 1;
	unsigned int underline : 1;
	unsigned int : 5;
};

typedef struct _font FONT;

void show_info(const FONT * pfont);
void show_menu(void);
CHOICE get_choice(void);
void eatline(void);
void change_font(FONT * pfont);
void change_size(FONT * pfont);
void change_alignment(FONT * pfont);
void toggle_bold(FONT * pfont);
void toggle_italic(FONT * pfont);
void toggle_underline(FONT * pfont);

int main(void)
{
	FONT font = {				//��ʼ��font��Ϣ
		1,
		12,
		LEFT,
		OFF,
		OFF,
		OFF,		
	};
	CHOICE ch;

	system("color 5A");
	show_info(&font);
	show_menu();
	while ((ch = get_choice()) != q)
	{
		switch (ch)
		{
		case f:
			change_font(&font);
			break;
		case s:
			change_size(&font);
			break;
		case a:
			change_alignment(&font);
			break;
		case b:
			toggle_bold(&font);
			break;
		case i:
			toggle_italic(&font);
			break;
		case u:
			toggle_underline(&font);
			break;
		}
		show_info(&font);
		show_menu();
	}
	puts("Bye!");

	system("pause");
	return 0;
}

void toggle_underline(FONT * pfont)
{
	pfont->underline ^= 01;
}

void toggle_italic(FONT * pfont)
{
	pfont->italic ^= 01;
}

void toggle_bold(FONT * pfont)
{
	pfont->bold ^= 01;
}

void change_alignment(FONT * pfont)
{
	char ch;

	puts("Select alignment:");
	puts("l)left c)center r)right");
	ch = getchar();
	eatline();
	while (strchr("lcr", ch) == NULL)
	{
		puts("Please enter l, c, or r.");
		ch = getchar();
		eatline();
	}
	if (ch == 'l')
	{
		pfont->alignment = LEFT;
	}
	else if (ch == 'c')
	{
		pfont->alignment = CENTER;
	}
	else
	{
		pfont->alignment = RIGHT;
	}
}

void change_size(FONT * pfont)
{
	unsigned int size;

	printf("Enter font size (0-127): ");
	while (scanf_s("%u", &size, 10) != 1)
	{
		puts("Please enter an integer in 0-127.");
	}
	eatline();
	size &= SIZE_MASK;					//ȡ��7λ
	pfont->size = size;
}

void change_font(FONT * pfont)
{
	unsigned int ID;

	printf("Enter font ID (0-255): ");
	while (scanf_s("%u", &ID, 10) !=1)
	{
		puts("Please enter an integer in 0-255.");
	}
	eatline();
	ID &= ID_MASK;						//ȡ��8λ
	pfont->ID = ID;
}

CHOICE get_choice(void)
{
	CHOICE ch;

	ch = getchar();
	eatline();
	while (strchr("fsabiuq", ch) == NULL)
	{
		puts("Please enter f, s, a, b, i, u, or q.");
		ch = getchar();
		eatline();
	}

	return ch;
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		;
	}
}

void show_menu(void)
{
	puts("f)change font s)change size   a)change alignment");
	puts("b)toggle bold i)toggle italic u)toggle underline");
	puts("q)quit");
}

void show_info(const FONT * pfont)
{
	puts("ID SIZE ALIGNMENT B I U");
	printf("%d %d ", pfont->ID, pfont->size);
	switch (pfont->alignment)
	{
	case LEFT:
		printf("left ");
		break;
	case CENTER:
		printf("center ");
		break;
	case RIGHT:
		printf("right ");
		break;
	}
	printf("%s", pfont->bold == OFF ? "off " : "on ");
	printf("%s", pfont->italic == OFF ? "off " : "on ");
	printf("%s", pfont->underline == OFF ? "off" : "on");
	putchar('\n');
}
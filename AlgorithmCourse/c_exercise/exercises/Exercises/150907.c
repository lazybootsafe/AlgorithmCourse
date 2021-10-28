//#if 1 //书上
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define     ID_MASK 0XFF
//#define   SIZE_MASK 0X7F00
//#define  ALIGN_MASK 0X18000
//#define   BOLD_MASK 0X20000
//#define ITALIC_MASK 0X40000
//#define  UNDER_MASK 0X80000
//
//unsigned int font_mode = 0;
//const char align_mode[][8] = { "left","center","right" };
//const char on_off[][4] = { "off","on" };
//
//void show_menu(void);
//void change_font(void);
//void change_size(void);
//void change_align(void);
//void change_others(char c);
//
//int main(void)
//{
//	char s;
//	show_menu();
//	scanf_s("%c", &s, 1);
//	while (s != 'q')
//	{
//		while (getchar() != '\n')
//			continue;
//		switch (s)
//		{
//		case 'f':
//			change_font();
//			break;
//		case 's':
//			change_size();
//			break;
//		case 'a':
//			change_align();
//			break;
//		default:
//			change_others(s);
//			break;
//		}
//		show_menu();
//		scanf_s("%c", &s, 1);
//	}
//
//	return 0;
//}
//
//void show_menu(void)
//{
//	int        id = font_mode & ID_MASK;
//	int      size = (font_mode&SIZE_MASK) >> 8;
//	int     align = (font_mode&ALIGN_MASK) >> 15;
//	int      bold = (font_mode&BOLD_MASK) >> 17;
//	int    italic = (font_mode&ITALIC_MASK) >> 18;
//	int underline = (font_mode&UNDER_MASK) >> 19;
//	puts("ID\tSIZE\tALIGN\tB\tI\tU");
//	printf("%-8d%-8d%-8s%-8s%-8s%-8s\n",
//		id,size,align_mode[align],
//		on_off[bold], on_off[italic],
//		on_off[underline]);;
//	puts("f) change font    s) change size      a) change alignment");
//	puts("b) toggle bold    i) toggle italic    u) toggle underline");
//	puts("q) quit");
//}
//
//void change_font(void)
//{
//	unsigned int n;
//	printf("Enter font id (0 - 255): ");
//	scanf_s("%d", &n);
//	while (getchar() != '\n')
//		continue;
//	font_mode &= ~ID_MASK;
//	font_mode |= n;
//}
//
//void change_size(void)
//{
//	unsigned int n;
//	printf("Enter font size (0 - 127): ");
//	scanf_s("%d", &n);
//	while (getchar() != '\n')
//		continue;
//	font_mode &= SIZE_MASK;
//	font_mode |= n << 8;
//}
//
//void change_align(void)
//{
//	char c;
//	puts("Select alignment:\nl) left   c) center   r) right");
//	scanf_s("%c", &c, 1);
//	while (getchar() != '\n')
//		continue;
//	font_mode &= (ALIGN_MASK);
//	if (c == 'l')
//		font_mode |= (0 << 15);
//	if (c == 'c')
//		font_mode |= (1 << 15);
//	if (c == 'r')
//		font_mode |= (2 << 15);
//}
//
//void change_others(char c)
//{
//	int bold = (font_mode & BOLD_MASK) >> 17;
//	int italic = (font_mode & ITALIC_MASK) >> 18;
//	int underline = (font_mode & UNDER_MASK) >> 19;
//	if (c == 'b')
//	{
//		font_mode &= (~BOLD_MASK);
//		font_mode |= ~(bold << 17);
//	}
//	if (c == 'i')
//	{
//		font_mode &= (~ITALIC_MASK);
//		font_mode |= ~(italic << 18);
//	}
//	if (c == 'u')
//	{
//		font_mode &= (UNDER_MASK);
//		font_mode |= ~(underline << 19);
//	}
//}
//
//#endif // 1

//#if 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void p15_7(void)
//{
//	/* practice 6中通过sizeof测出来的大小是3字节，所以其实使用int行就足够的了
//	   这里按要求使用unsigned long
//	   bit:0    表示下划线开关位
//	   bit:1    表示斜体开关位
//	   bit:2    表示加粗开关位
//	   bit:3-4  表示对齐
//	   bit:8-15 表示字体大小
//	   bit:16-23 表示字体ID
//	*/
//	unsigned long ch = 0;
//
//	char align[10] = "left";
//	char choice = 0;
//
//	while (1)
//	{
//		printf("ID SIZE ALIGNMENT%4s%4s%4s\n", "B", "I", "U");
//		if ((ch >> 3 & 0x3) == 0)
//		{
//			strcpy_s(align, sizeof align, "left");
//		}
//		else if (((ch >> 3) & 0x3) == 1)
//		{
//			strcpy_s(align, sizeof align, "center");
//		}
//		else if (((ch >> 3) & 0x3) == 2)
//		{
//			strcpy_s(align, sizeof align, "right");
//		}
//		printf("%2d%5d%8s%7s%4s%4s\n", ((ch >> 16) & 0xff), ((ch >> 8) & 0xff), align, (((ch >> 2) & 0x01) ? "on" : "off"),
//			(((ch >> 1) & 0x01) ? "on" : "off"), ((ch & 0x01) ? "on" : "off"));
//
//		printf("%-20s%-20s%-20s\n", "f)change font", "s)change size", "a)change alignment");
//		printf("%-20s%-20s%-20s\n", "b)toggle bold", "i)toggle italic", "u)toggle underline");
//		printf("%-20s\n", "q)quit");
//
//		scanf_s("%c", &choice, 1);
//		while (getchar() != '\n');
//		if (choice == 'q')
//		{
//			break;
//		}
//
//		switch (choice)
//		{
//		case 'f':
//			printf("Enter font id(0-255): ");
//			unsigned int font_id = 0;
//			scanf_s("%d", &font_id);
//			ch &= ~(0xff << 16);
//			ch |= (font_id << 16);
//			while (getchar() != '\n');
//			break;
//		case 's':
//			printf("Enter font size(0-127): ");
//			unsigned int font_size = 0;
//			scanf_s("%d", &font_size);
//			while (getchar() != '\n');
//			ch &= ~(0xff << 8);
//			ch |= (font_size << 8);
//			break;
//		case 'a':
//			printf("Select alignment:");
//			printf("%-12s%-12s%-12s\n", "l)left", "c)center", "r)right");
//			char choice = 0;
//			scanf_s("%c", &choice, 1);
//			while (getchar() != '\n');
//			// 先将对齐字段清零
//			ch &= ~(0x03 << 3);
//			switch (choice)
//			{
//			case 'l':
//				ch |= (0x00 << 3);
//				break;
//
//			case 'c':
//				ch |= (0x01 << 3);
//				break;
//
//			case 'r':
//				ch |= (0x02 << 3);
//				break;
//
//			default:
//				printf("Input error! Nothing have been changed!\n");
//				break;
//			}
//			break;
//
//		case 'b':
//			if (ch & (0x01 << 2))
//			{
//				ch &= ~(0x01 << 2);
//			}
//			else
//			{
//				ch |= (0x01 << 2);
//			}
//			break;
//
//		case 'i':
//			if (ch & (0x01 << 1))
//			{
//				ch &= ~(0x01 << 1);
//			}
//			else
//			{
//				ch |= (0x01 << 1);
//			}
//			break;
//
//		case 'u':
//			if (ch & 0x01)
//			{
//				ch &= ~(0x01);
//			}
//			else
//			{
//				ch |= 0x01;
//			}
//			break;
//
//		default:
//			printf("Error choice. Nothing have been changed!\n");
//			break;
//		}
//	}
//
//	printf("Done.\n");
//	return;
//}
//
//int main(void)
//{
//	p15_7();
//
//	return 0;
//}
//
//#endif

#if 1
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

#define ID_MASK     0xFF 
#define SIZE_MASK   0x7F00 
#define LEFT        0x00000 
#define CENTER      0x08000 
#define RIGHT       0x10000 
#define ALIGN_MASK  0x18000 
#define REGULAR     0x00000 
#define BOLD        0x20000 
#define ITALIC      0x40000 
#define UNDERLINE   0x80000 
#define STYLE_MASK  0xE0000 
#define SIZE_SHIFT  8 

typedef unsigned long font;

char do_menu(font * f);
char get_choice(const char *);
void show_menu(void);
void show_font(font f);
void eatline(void);
void get_id(font * f);
void get_size(font * f);
void get_align(font * f);

int main(void)
{
	font sample = 1 | (12 << SIZE_SHIFT) | LEFT | ITALIC;

	while (do_menu(&sample) != 'q')
		continue;
	puts("Bye!");
	return 0;
}

char do_menu(font * f)
{
	char response;

	show_font(*f);
	show_menu();
	response = get_choice("fsabiuq");
	switch (response)
	{
	case 'f':
		get_id(f);
		break;
	case 's':
		get_size(f);
		break;
	case 'a':
		get_align(f);
		break;
	case 'b':
		*f ^= BOLD;
		break;
	case 'i':
		*f ^= ITALIC;
		break;
	case 'u':
		*f ^= UNDERLINE;
		break;
	case 'q':
		break;
	default:
		fprintf(stderr, "menu problem\n");
	}

	return response;
}

char get_choice(const char * str)
{
	char ch;

	ch = getchar();
	ch = tolower(ch);
	eatline();
	while (strchr(str, ch) == NULL)
	{
		printf("Please enter one of the following: %s\n",
			str);
		ch = tolower(getchar());
		eatline();
	}
	return ch;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void show_menu(void)
{
	puts("f)change font    s)change size    a)change alignment");
	puts("b)toggle bold    i)toggle italic  u)toggle underline");
	puts("q)quit");
}

void show_font(font f)
{
	printf("\n%4s %4s %9s %3s %3s %3s\n",
		"ID", "SIZE", "ALIGNMENT", "B", "I", "U");
	printf("%4lu %4lu", f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT);
	switch (f & ALIGN_MASK)
	{
	case LEFT: printf("%7s", "left"); break;
	case RIGHT: printf("%7s", "right"); break;
	case CENTER: printf("%7s", "center"); break;
	default: printf("%7s", "unknown"); break;
	}
	printf("%8s %3s %3s\n\n", (f & BOLD) == BOLD ? "on" : "off",
		(f & ITALIC) == ITALIC ? "on" : "off",
		(f & UNDERLINE) == UNDERLINE ? "on" : "off");
}

void get_id(font * f)
{
	int id;

	printf("Enter font ID (0-255): ");
	scanf_s("%d", &id);
	id = id & ID_MASK;
	*f |= id;
	eatline();
}

void get_size(font * f)
{
	int size;

	printf("Enter font size (0-127): ");
	scanf_s("%d", &size);
	*f |= (size << SIZE_SHIFT) & SIZE_MASK;
	eatline();
}

void get_align(font * f)
{
	puts("Select alignment:");
	puts("l)left   c)center   r)right");
	switch (get_choice("lcr"))
	{
	case 'l':
		*f &= ~ALIGN_MASK;
		*f |= LEFT;
		break;
	case 'c':
		*f &= ~ALIGN_MASK;
		*f |= CENTER;
		break;
	case 'r':
		*f &= ~ALIGN_MASK;
		*f |= RIGHT;
		break;
	default:
		fprintf(stderr, "alignment problem\n");
	}
}

#endif
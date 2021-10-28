#if 0
#include <stdio.h>
#include <stdlib.h>
#define UINT unsigned int
struct font
{
	UINT        id : 8;
	UINT      size : 7;
	UINT     align : 2;
	UINT      bold : 1;
	UINT    italic : 1;
	UINT underline : 1;
}font_mode = { 1,12,0,0,0,0 };

const char align[][8] = { "left","center","right" };
const char on_off[][4] = { "off","on" };

void get_menu(void);
void change_font(void);
void change_size(void);
void change_align(void);
void change_others(char ch);

int main(void)
{
	char selected;
	get_menu();
	scanf_s("%c", &selected, 1);
	while (selected != 'q')
	{
		while (getchar() != '\n')
			continue;
		switch (selected)
		{
		case 'f':
			change_font();
			break;
		case 's':
			change_size();
			break;
		case 'a':
			change_align();
			break;
		default:
			change_others(selected);
			break;
		}
		get_menu();
		scanf_s("%c", &selected, 1);
	}
	return 0;
}

void get_menu(void)
{
	puts("ID\tSIZE\tALIGN\tB\tI\tU");
	printf("%-8d%-8d%-8s%-8s%-8s%-8s\n",
		font_mode.id, font_mode.size,
		align[font_mode.align], on_off[font_mode.bold],
		on_off[font_mode.italic], on_off[font_mode.underline]);
	puts("f) change font    s) change size      a) change alignment");
	puts("b) toggle bold    i) toggle italic    u) toggle underline");
	puts("q) quit");
}

void change_font(void)
{
	UINT n;
	printf("Enter font id (0-255): ");
	scanf_s("%d", &n);
	while (getchar() != '\n')
		continue;
	font_mode.id = n;
}

void change_size(void)
{
	UINT n;
	printf("Enter font size (0-127): ");
	scanf_s("%d", &n);
	while (getchar() != '\n')
		continue;
	font_mode.size = n;
}

void change_align(void)
{
	char ch;
	puts("Select alignment:\nl) left   c) center   r) right");
	scanf_s("%c", &ch, 1);
	while (getchar() != '\n')
		continue;
	if (ch == 'l')
		font_mode.align = 0;
	if (ch == 'c')
		font_mode.align = 1;
	if (ch == 'r')
		font_mode.align = 2;
}

void change_others(char ch)
{
	if (ch == 'b')
		font_mode.bold = !font_mode.bold;
	if (ch == 'i')
		font_mode.italic = !font_mode.italic;
	if (ch == 'u')
		font_mode.underline = !font_mode.underline;
}

#endif // 1
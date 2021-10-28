/*
	λ�ֶ�����һ��unsigned int��С�Ľṹ����ʲ���λֵ��
	λ�������һ��unsigned intֵ����λ��������λֵ��
	
	��ʾ����ʹ�������ַ�������λֵ����Ϊ�˽������еĲ�ͬ��
	�������ǰ�ʱͬʱʹ�������ַ�����һ��������
	
	�ƺ�д��FH���͵��������ˡ�ֻ��֪����λ����������λ���㣬����һ��λ��ϵ���Ϣ������λ�ֶ�(���ֶ�д��int��Ԫ���˳��������ʵ�֣�
	*/

//#include <stdio.h>
#include <stdlib.h>

//λ�ֶγ���
//�Ƿ�͸�����Ƿ�ɼ�
#define YES		1
#define NO		0

//�߿��ߵ���ʽ
#define SOLID	0
#define DOTTED	1
#define DASHED	2

//��ԭɫ
#define BLUE	4
#define GREEN	2
#define RED		1

//�����ɫ
#define BLACK	0
#define YELLOW	(GREEN | RED)
#define MAGENTA (BLUE | RED)
#define CYAN	(BLUE | GREEN)
#define WHITE	(BLUE | GREEN | RED)

//λ������ʹ�õĳ���
#define OPAQUE			0x00000001
#define FILL_BLUE		0x00000008
#define FILL_GREEN		0x00000004
#define FILL_RED		0x00000002
#define FILL_MASK		0x0000000E
#define BORDER			0x00000100
#define BORDER_BLUE		0x00000800
#define BORDER_GREEN	0x00000400
#define BORDER_RED		0x00000200
#define BORDER_MASK		0x00000E00
#define B_SOLID			0
#define B_DOTTED		0x00001000
#define B_DASHED		0x00002000
#define STYLE_MASK		0x00003000

const char * colors[8] = { "black", "red", "green", "yellow",
							"bule", "magenta", "cya", "white" };

struct box_props						/*����ʵ�����ҵĵ����Ǵ�����������ֶεġ�Ҳ���ǵ�һ���ֶ�����λ0�����λ�������һ���ֶ�����λ31�����λ���ҵ�ϵͳ��int��4�ֽ�32λ�ģ�
										  �������λ�ֶνṹֻ����һ��int�ĺ�2���ֽڣ���16λ������Ȼ��λ�ֶ�������Ϣ�����(^_^)*/
{
	unsigned int opaque			: 1;
	unsigned int fill_color		: 3;
	unsigned int				: 4;
	unsigned int show_border	: 1;
	unsigned int border_color	: 3;
	unsigned int border_style	: 2;
	unsigned int				: 2;
};

union Views										//����������λ�ֶνṹ��unsigned int����
{
	struct box_props st_view;
	unsigned int ui_view;
};

void show_settings(const struct box_props * ps);
void show_settings1(unsigned int);
char * itobs(int n, char * ps);							//��intֵ�Ķ����Ʋ����ӡ����
void show_bstr(char * str);

int main(void)
{
	/*�������϶��󣬳�ʼ����һ����Ա*/
	union Views box = { YES, YELLOW, YES, GREEN, DASHED };
	char bin_str[8 * sizeof(int)+1];

	system("color 0A");
	printf("Original box settings:\n");
	show_settings(&box.st_view);						//�����������ṹ��(int��С��

	printf("Box settings using unsigned int view:\n");
	show_settings1(box.ui_view);						//����������intֵ

	printf("Bits are ");
	itobs(box.ui_view, bin_str);
	show_bstr(bin_str);

	box.ui_view &= ~FILL_MASK;							//�Ѵ������ɫλȫ������
	box.ui_view |= (FILL_GREEN | FILL_BLUE);			//�������ɫ
	box.ui_view ^= OPAQUE;								//ת��ָʾ�Ƿ�͸����λ
	box.ui_view |= BORDER_RED;							//����ķ���
	box.ui_view &= ~STYLE_MASK;							//�����ʽλ
	box.ui_view |= B_DOTTED;							//����ʽ����Ϊ��

	printf("\nModified box settings:\n");
	show_settings(&box.st_view);

	printf("Box settings using unsigned int view:\n");
	show_settings1(box.ui_view);

	printf("Bits are ");
	itobs(box.ui_view, bin_str);
	show_bstr(bin_str);

	getchar();
	return 0;
}

void show_settings(const struct box_props * ps)
{
	printf("Box is %s.\n",
		ps->opaque == YES ? "opaque" : "transparent");
	printf("The fill color is %s.\n",
		colors[ps->fill_color]);
	printf("Border is %s\n",
		ps->show_border == YES ? "shown" : "not shown");
	printf("Border color is %s.\n", 
		colors[ps->border_color]);
	printf("Border style is ");
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

void show_settings1(unsigned int n)
{
	printf("Box is %s.\n",
		(n & OPAQUE) == OPAQUE ? "opaque" : "transparent");		//λ��������ȼ�����==�ţ�ע�������
	printf("The fill color is %s.\n",
		colors[(n & FILL_MASK) >> 1]);					/*1.fill_color������λ1��λ3֮�䣬����Ϊ��ȡ������λ��ʾ������ֵ��������һλ����������ȡ����3λ����ɫֵ���Ӷ���Ӧ������0-7����ɫ��������ɫ�ַ���
														  2.ע��λ��������ȼ�����&�������ڸ������������λ����ʱ����ü�����������*/
	printf("Border is %s.\n",
		(n & BORDER) == BORDER ? "shown" : "not shown");
	printf("��1��Border color is %s.\n",
		colors[(n & BORDER_MASK) >> 9]);				//��0xE00������ȡ����Ӧ��λ9��λ11֮�����ɫֵ�����ұߵ�λ������λ����Ȼ��������9λ����3λ��ɫֵ�䵽��3λ���Ӷ���Ӧ������0-7����ɫ��������ɫ�ַ���
	printf("��2��Border color is %s.\n",
		colors[(n >> 9) & 07]);							//��n����9λ������07����ȡ����3λ
	printf("��3��Border color is %s.\n",
		colors[(n >> 9) & (0xE >> 1)]);					//��n����9λ����0xE����1λ������n���룬ȡ����3λ
	//�ܽ᣺��λ����ȡ���ض�λ��ת���ɵ�������ֵʱ��ֻ��2����
	//1.��λ�����Ҫȡ���м��ĳnλ����ô�Ȱ���nλ�ұߵ�����λ�Ƴ�ȥ������nΪ�䵽���λ��
	//2.ȡֵ����һ�����nλȫΪ1��������Ǹ�������ȡ���Ǹ��������nλ��

	//ע����λ��ȡֵ��û�д�����ȡֵ�ٰѺ�ߵ��޹�λ�Ƴ�Ҳ����(�������ڵĵڶ���printf()�������������ģ������ԣ���λ�ķ���Ҳ�Ͷ��ֶ����ˣ���ԭ��Ͳ���Ӧ�þ��������ˡ�

	printf("Border style is  ");
	switch (n & STYLE_MASK)								//��Ϊ�������Ҫȡ��ֵ������ֻ��Ҫ��λ15��λ14�жϣ�����λȫ�����Σ����Ի��������룩
	{
	case B_SOLID:
		printf("solid.\n");
		break;
	case B_DOTTED:
		printf("dotted.\n");
		break;
	case B_DASHED:
		printf("dashed.\n");
		break;
	default:
		printf("unknown type.\n");
		break;
	}
}

char * itobs(int n, char * ps)
{
	int size = 8 * sizeof(int)+1;

	for (int i = size - 2; i >= 0; i--, n >>= 1)
	{
		ps[i] = (n & 01) + '0';							//n�������ƣ���01������ȡ��λ0��λֵ������0�ַ���ASCII��ת��Ϊ�ַ������δӺ���ǰд�뵽�ַ�����
	}
	ps[size - 1] = '\0';								//���һ��λ��ֲ����ַ�

	return ps;
}

void show_bstr(char * str)
{
	int i = 0;

	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i] != '\0')
		{
			putchar(' ');
		}
	}
	putchar('\n');
}
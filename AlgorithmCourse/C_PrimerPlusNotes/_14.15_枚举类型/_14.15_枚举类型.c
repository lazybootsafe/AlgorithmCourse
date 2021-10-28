#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>				//C99���ԣ���C++����
#include <string.h>

#define	LEN 30

enum spectrum						//ö������ģ�壬ö�ٵĳ����б���Ĭ��ֵ
{
	red,
	orange,
	yellow,
	green,
	blue,
	violet
};

const char * colors[] = { "red", "orange", "yellow", "greem", "blue", "violer" };

int main(void)
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;
	
	system("COLOR 0A");
	puts("Enter a color (empty line to quit):");
	while (gets_s(choice, LEN) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; color++)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
		{
			switch (color)
			{
			case red:	puts("Rose are red.");
				break;
			case orange:puts("Poppies are orange.");
				break;
			case yellow:puts("Sunflowers are yellow.");
				break;
			case green:	puts("Grass is green.");
				break;
			case blue:	puts("Bluebells are blue.");
				break;
			case violet:puts("Violets are violet.");
				break;
			default:
				break;
			}			
		}
		else
		{
			printf("I don't know about the color %s.\n", choice);
		}
		color_is_found = false;
		puts("Next color, please (empty line to stop):");
	}
	puts("Good bye.");

	system("pause");
	return 0;
}
/*��������ֿռ䣺
	��һ���ض��������ڵĽṹ��ǡ����ϱ�ǡ�ö�ٱ�ǣ�����ͬһ�����ֿռ䣬����������ֿռ�����ͨ����ʹ�õ����ֿռ��ǲ���ͬ�ġ�
	
	Ҳ����˵��
	������ͬһ���������ڶ�һ��������һ�����ʹ��ͬһ�����ֶ�����ͻ�����ǲ�����ͬһ����������ʹ��������ͬ��������ǻ�������ͬ������������
	����
	struct rect{double x; double y};
	int rect;	//��C�в�����ͻ
	���ǣ������ֲ�ͬ�ķ�ʽʹ��ͬһ�ֱ�ʶ������ɻ��ң�
	���ң�C++��������ͬһ���������ڶ�һ��������һ�����ʹ��ͬһ�����֣���Ϊ���ѱ�Ǻͱ���������ͬһ�����ֿռ䡣

	��ʵ����һ�仰��������Ҫʹ��ͬ���ı�ʶ����
*/
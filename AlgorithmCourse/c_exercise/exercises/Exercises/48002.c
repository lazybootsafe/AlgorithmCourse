#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char name[20] = { 0 };
	int width = 0;
	printf("Enter your name: ");
	scanf_s("%s", &name, 19);
	width = printf("\"%s\".\n", name);
	width -= 4;		//减掉双引号、句号和结束符得到字符串长度
	printf("\"%20s\".\n", name);	//设置打印字符串长度为20(目标字串不足用空格向前填充)
	printf("\"%-20s\".\n", name);	//设置打印字符串长度为20(目标字串不足用空格身后填充)
	printf("\"%*s\".", (width + 3), name);	//使用*修饰符指定打印宽度

	return 0;
}

#endif
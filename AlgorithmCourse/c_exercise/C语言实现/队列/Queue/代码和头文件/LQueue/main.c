#include "../head/LQueue.h"
#include "LQueue.c"
void main()
{
	LQueue *queue = NULL;
    char t;
  
	menu();
	printf("\n输入你选择的操作(以输入的第一个字符为准): ");
    while((t = getchar()) != 'j')
	{
		if(t == '\n')
			continue;
		if('a' <= t && t <= 'j')
		{	
			switch(t)
			{
			    case'a':
					InitLQueue(&queue);
					reactive();
					break;
				case'b':
					DestoryLQueue(queue);
                    queue = NULL;
					reactive();
					break;
				case'c':
					is_empty(queue);
					reactive();
					break;
				case'd':
					get_head(queue);
					reactive();
					break;
				case'e':
					length(queue);
					reactive();
					break;
				case'f':
					enter(queue);
					reactive();
					break;
				case'g':
					deletel(queue);
					reactive();
					break;
				case'h':
					ClearLQueue(queue);
					reactive();
					break;
				case'i':
					traversel(queue);
					reactive();
					break;
			}
		}
		else 
			printf("\n输入错误,请重新输入:  ");

		while(getchar() != '\n')
			continue;
	}
	printf("程序已经结束，感谢你的使用\n");
	DestoryLQueue(queue);
    getchar();
}
#include "../head/AQueue.h"
#include "AQueue.c"
void main()
{
	AQueue *queue = NULL;
    char t;
  
	menu();
	printf("\n输入你选择的操作(以输入的第一个字符为准): ");
    while((t = getchar()) != 'k')
	{
		if(t == '\n')
			continue;
		if('a' <= t && t <= 'k')
		{	
			switch(t)
			{
			    case'a':
					InitAQueue(&queue);
					reactive();
					break;
				case'b':
					DestoryAQueue(queue);
                    queue = NULL;
					reactive();
					break;
				case'c':
					is_full(queue);
					reactive();
					break;
				case'd':
					is_empty(queue);
					reactive();
					break;
				case'e':
					get_head(queue);
					reactive();
					break;
				case'f':
					length(queue);
					reactive();
					break;
				case'g':
					enter(queue);
					reactive();
					break;
				case'h':
					Delete(queue);
					reactive();
					break;
				case'i':
					ClearAQueue(queue);
					reactive();
					break;
				case'j':
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
	DestoryAQueue(queue);
    getchar();
}
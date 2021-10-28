#include "../inc/qgsort.h"
#include "qgsort.c"


int main()
{	
	char t;

	menu();
	printf("\n输入你选择的操作(以输入的第一个字符为准): ");
    while((t = getchar()) != 'i')
	{
		if(t == '\n')
			continue;
		if('a' <= t && t <= 'h')
		{	
			switch(t)
			{
			    case'a':
					printf("\n【插入排序】\n");
					print(insertSort);
					reactive();
					break;
				case'b':
					printf("\n【归并排序】\n");
					print(merge);
					reactive();
					break;
				case'c':
					printf("\n【快速排序(递归)】\n");
					print(quicksort_re);
					reactive();
					break;
				case'd':
					printf("\n【快速排序(非递归)】\n");
					print(QuickSort);
					reactive();
					break;
				case'e':
					printf("\n【计数排序】\n");
					print(count);
					reactive();
					break;
				case'f':
					printf("\n【基数计数排序】\n");
					print(RadixCountSort);
					reactive();
					break;
				case'g':
					printf("\n【颜色排序】\n");
					print(ColorSort);
					reactive();
					break;
				case'h':
					printf("\n【无序寻点】\n");
					print(find);
					reactive();
					break;
			}
		}
		else 
			printf("\n输入错误,请重新输入:  ");

		while(getchar() != '\n')
			continue;
	}		
    return 0;
}




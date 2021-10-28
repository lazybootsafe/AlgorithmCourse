#include "BinaryTree.c"
#include "../head/BinaryTree.h"
void main()
{
	BiTree root = NULL;
    char t;
  
	menu();
	printf("\n【操作】输入: ");
    while((t = getchar()) != 'e')
	{
		if(t == '\n')
			continue;
		if('a' <= t && t <= 'd')
		{	
			switch(t)
			{
				case'a':
					create(&root);
					reactive();
					break;
				case'b':
					destroy(root);
                    root = NULL;
					reactive();
					break;
				case'c':
					pre(root);
					in(root);
					post(root);
					LevelOrderTraverse(root,print);
					reactive();
					break;
				case'd':
					countPrBiTree(&root);
					reactive();
					break;
			}
		}
		else 
			printf("\n【操作】输入错误,请重新输入:  ");

		while(getchar() != '\n')
			continue;
	}
	printf("\n\n【结束】程序已经结束，感谢您的使用！\n\n");
    getchar();
}
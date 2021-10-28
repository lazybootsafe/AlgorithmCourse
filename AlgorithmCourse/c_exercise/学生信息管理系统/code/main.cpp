#include "stuManager.h"
#include "stuManager.cpp"

// 主函数
void main()
{	
	int i;
	LinkedList stu;
	
	init(stu);
	readFile(stu);

	menu();
	printf("\n【选择操作】输入: ");
    while((i = inputInt()) != 6)
	{	
		if(1 <= i && i <= 5)
		{	
			switch(i)
			{
				case 1:
					// [增加]一个学生
					add(stu);
					writeFile(stu);
					reactive();
					break;
				case 2:
					// [删除]一个学生
					del(stu);
					writeFile(stu);
					reactive();
					break;
				case 3:
					// [查找]学生信息
					searchStu(stu);
					reactive();
					break;
				case 4:
					// [修改]学生信息
					change(stu);
					reactive();
					break;
				case 5:
					// [打印]全部学生
					printfALL(stu);
					reactive();
					break;
			}
		}
		else 
			printf("\n【选择操作】选择输入有误,请重新选择:  ");
	}
	printf("\n\n【结束】程序已经结束，感谢您的使用！\n\n");
}


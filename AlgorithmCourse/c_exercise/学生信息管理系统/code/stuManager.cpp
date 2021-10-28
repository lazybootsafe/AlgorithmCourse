#include "stuManager.h"

/*
  【公用函数】——————————————————————————————————————
*/

// 输入数字
int inputInt() {
	int a, result;
	fflush(stdin);
	a = scanf("%d",&result);
	if(a == 0)
	{
		printf("\n【输入数字】输入错误，请重新输入: ");
        result = inputInt();
	}
	return result;
}

// 功能表
void menu()
{
	
	printf("\n\n                    **请选择以下功能**\n\n");
	printf("     |——————————输入  &&   功能—————————————|\n");
	printf("     |-——————————————————————————————|\n");
	printf("     |---------------------1    TO   [增加]一个学生----------------|\n");
	printf("     |-——————————————————————————————|\n");
	printf("     |---------------------2    TO   [删除]一个学生----------------|\n");
	printf("     |-——————————————————————————————|\n");
	printf("     |---------------------3    TO   [查找]学生信息----------------|\n");
	printf("     |-——————————————————————————————|\n");
	printf("     |---------------------4    TO   [修改]学生信息----------------|\n");
	printf("     |-——————————————————————————————|\n");
	printf("     |---------------------5    TO   [打印]全部学生----------------|\n");
	printf("     |-——————————————————————————————|\n");
	printf("     |---------------------6    TO   [退出]------------------------|\n");
	printf("     |-——————————————————————————————|\n");
	printf("     |-——————————————————————————————|\n");
}


// 简化交互
void reactive()
{
	printf("\n\n");
	system("PAUSE");
	system("cls");
	menu();
	printf("\n【选择操作】输入: ");
}


/*
  【一、初始化】——————————————————————————————————————
*/

// 初始化学生链表
void init(LinkedList &link) {
	link = (LinkedList)malloc(sizeof(LNode));
	link->next = NULL;
}



/*
  【二、查找一个学生】——————————————————————————————————————
*/

// 3. 判断学号为stu_id的学生是否存在
LinkedList ifStuExist(LinkedList &link, int stu_id) {
	LinkedList p;
	LinkedList result = NULL;
	for(p = link->next; p != NULL; p=p->next) {
		if(p->stu_id == stu_id) {
			result = p;
			break;
		}
	}
	return result;
}
// 打印一个学生
void printfStu(LinkedList p) {
	printf("\n  %s( %d )  [%s]   %d 年级 %d 班\n", p->name, p->stu_id, p->sex==0?"男":"女", p->grade, p->_class);
}
// 查找学生【主功能函数】
void searchStu(LinkedList link) {
	printf("\n【查找】输入你要查找的学号: ");
	int stu_id = inputInt();
	LinkedList p = ifStuExist(link, stu_id);
	if(p == NULL) {
		printf("\n【查找】不存在学号为 %d 的学生: ", stu_id);
	} else {
		printf("\n【查找成功】: \n");
		printfStu(p);
		
	}
}




/*
  【三、添加一个学生】——————————————————————————————————————
*/

// 添加链表节点
LinkedList addLNode(LinkedList &link, int stu_id, int grade, int _class, int sex, char *name) {

	LinkedList p = (LinkedList)malloc(sizeof(LNode));
	// 放入数据
	p->stu_id = stu_id;
	p->grade = grade;
	p->_class = _class;
	p->sex = sex;
	strcpy(p->name, name);
	p->next = NULL;

	// 将节点放进链表的第一个节点
	p->next = link->next;
	link->next = p;	
	return p;
}

// 输入学号
int inputStuId(LinkedList &link) {
	int stu_id = inputInt();
	if(ifStuExist(link, stu_id) != NULL) { 
		// 调用函数ifStuExist对学生id查重
		printf("\n【输入错误】学号为 %d 该学生已经存在，请重新输入: ", stu_id);
        stu_id = inputStuId(link);
	}
	return stu_id;
}

// 输入新的学生【主功能函数】
void add(LinkedList &link) {
	int stu_id;
	int grade;
	int _class;
	int sex;
	char name[30];
	printf("\n  【添加】输入[学号](int)：");
	stu_id = inputStuId(link);
	LinkedList p;

	printf("\n  【添加】输入[年级](int)：");
	grade = inputInt();

	printf("\n  【添加】输入[班别](int)：");
	_class = inputInt();

	printf("\n  【添加】输入[性别](int, 输入 0 为男性，输入其他为女性)：");
	sex = inputInt();

	printf("\n  【添加】输入[姓名](char *)：");
	fflush(stdin);
	gets(name);
	
	p = addLNode(link, stu_id, grade, _class, sex, name);
	printf("\n 【添加】 成功添加学生：\n");
	printfStu(p);
}




/*
  【四、删除一个学生】——————————————————————————————————————
*/

// 查找学号为stu_id的学生节点的父节点
LinkedList searchFather(LinkedList &link, int stu_id) {
	LinkedList p;
	LinkedList result = NULL;
	for(p = link; p->next != NULL; p=p->next) {
		if(p->next->stu_id == stu_id) {
			result = p;
			break;
		}
	}
	return result;
}

// 删除链表节点
void delNode(LinkedList &link, LinkedList fp) {
	LinkedList temp = fp->next;
	fp->next = temp->next;
	free(temp);
}

// 删除一个学生【主功能函数】
void del(LinkedList &link) {
	printf("\n【删除】请输入要删除的学生id:  ");
	int stu_id = inputInt();
	LinkedList fp = searchFather(link, stu_id);
	
	if(fp == NULL) {
		printf("\n【删除失败】不存在学号为 %d 的学生 ", stu_id);
	} else {
		delNode(link, fp);
		printf("\n【删除】成功删除学生( %d): ", stu_id);
	}
}




/*
  【五、修改一个学生的信息】——————————————————————————————————————
*/

// 选择操作
int chooseWay() {
	int way = inputInt();
	if(way < 0 || way > 3) { 
		printf("\n【输入错误】请输入0-3之间的数字，请重新输入: ");
        way = chooseWay();
	}
	return way;
}
// 修改数据
void changeData(LinkedList p, int way) {
	if(way == 0) {
		printf("\n【修改】姓名(char *):  ");
		fflush(stdin);
		gets(p->name);
	} else if(way == 1) {
		printf("\n【修改】性别(int, 输入 0 为男性，输入其他为女性)（）:  ");
		p->sex = inputInt();
	} else if(way == 2) {
		printf("\n【修改】年级(int):  ");
		p->grade = inputInt();
	} else if(way == 3) {
		printf("\n【修改】班别(int):  ");
		p->_class = inputInt();
	}
}
// 修改
void change(LinkedList &link) {
	printf("\n【修改】请输入要修改信息的学生的学号id:  ");
	int stu_id = inputInt();
	LinkedList p = ifStuExist(link, stu_id);
	if(p == NULL) {
		printf("\n【修改】不存在学号为 %d 的学生: ", stu_id);
	} else {
		printf("\n【修改】选择修改哪个信息（0->姓名，1->性别，2->年级，3->班级）：");
		int way = chooseWay();
		changeData(p, way);
		
	}
}




/*
  【六、打印全部学生】——————————————————————————————————————
*/

// 打印全部学生
void printfALL(LinkedList &link) {
	LinkedList p;
	if(link->next == NULL) {
		printf("\n 【打印】 暂无学生信息");
		return;
	}
	for(p = link->next; p != NULL; p = p->next) {
		printfStu(p);
	}
}



/*
  【七、文件读写操作】——————————————————————————————————————
*/

// 读取文件里面数据
void readFile(LinkedList link) {
	FILE * fp;
	LNode p;
	int num = 0;
	if( (fp=fopen("myfile.txt","rb")) == NULL) {
		printf("\n\n 【数据读取出错】 请在程序同级目录下新建一个myfile.txt文件 ");
		getchar();
		exit(0);
	}
	while(fread(&p, sizeof(LNode), 1, fp) == 1)   //如果读到数据，就显示；否则退出
	{	
		 // printfStu(&p);
		num++;
		 addLNode(link, p.stu_id, p.grade, p._class, p.sex, p.name); 
	}
	printf("\n 【读取数据】 从 myfile.txt 成功读取到[ %d ]个学生信息 \n", num);
}

// 将数据写入文件
void writeFile(LinkedList link) {
	FILE * fp;
	LinkedList p;
	fp = fopen ("myfile.txt", "wb");
	if(fp == NULL) {
		return;
	}
	for(p = link->next; p != NULL; p = p->next) {
		fwrite(p, sizeof(LNode), 1, fp);
	}
	
	fclose (fp);
}





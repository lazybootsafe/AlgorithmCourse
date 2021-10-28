#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef SJF_H_INCLUDED
#define SJF_H_INCLUDED 

// 定义学生结构体
typedef struct LNode { 

	int stu_id; // 学生学号

	int grade;  // 年级

	int _class; // 班级

	int sex;  // 性别

	char name[30]; // 姓名

  	struct LNode *next; 

} LNode, *LinkedList;


#endif

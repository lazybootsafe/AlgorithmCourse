#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef SJF_H_INCLUDED
#define SJF_H_INCLUDED 

// ����ѧ���ṹ��
typedef struct LNode { 

	int stu_id; // ѧ��ѧ��

	int grade;  // �꼶

	int _class; // �༶

	int sex;  // �Ա�

	char name[30]; // ����

  	struct LNode *next; 

} LNode, *LinkedList;


#endif

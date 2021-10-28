#pragma once

#define LEN 10000
#define MAX 10000

typedef struct item {
	char word[LEN];
	int num;
} Item;

typedef struct trnode {
	Item item;
	struct trnode * left;
	struct trnode * right;
} Trnode;

typedef struct tree {
	Trnode * root;
	int size;
} Tree;

//��ʼ����
static void InitializeTree(Tree * ptree);

//ȷ����Ϊ��
static int TreeIsFull(const Tree * ptree);

//ȷ����Ϊ��
static int TreeIsEmpty(const Tree * ptree);

//ͳ������
static int TreeItemCount(const Tree * ptree);

//������
static int InTree(const Tree * ptree, const Item * pi);

//�����
static int AddItem(Tree * ptree, const Item * pi);

//ɾ����
static int DelItem(Tree * ptree, const Item * pi);

//������
static void Traverse(const Tree * ptree, void(*pfun)(Item item));

//�����
static void DeleteAll(Tree * ptree);

//��ĳһ�����
static int ItemCount(const Tree * ptree, const Item * item);

#ifndef _17_8_H_INCLUDED
#define _17_8_H_INCLUDED

#define MAX 10
#define LEN 40
#define SIZE 100

typedef struct item {
	char name[LEN];
	char kind[MAX][LEN];
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
static void FindItem(const Tree * ptree, const Item * item);

//�����
static int AddItem(Tree * ptree, const Item * pi);

//ɾ����
static int DelItem(Tree * ptree, const Item * pi);

//������
static void Traverse(const Tree * ptree, void(*pfun)(Item item));

//�����
static void DeleteAll(Tree * ptree);

#endif // 17_8_H_INCLUDED

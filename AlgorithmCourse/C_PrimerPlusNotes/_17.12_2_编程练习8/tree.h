/*tree.h -- �����������Ľӿ�ͷ�ļ�*/

/*���в���������ͬ����Ŀ*/
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>


/*�������������Item����Ϊ�ʺϵ�����*/
#define MAXKINDS 20			//ͬ������������������
typedef	struct item
{
	char petname[20];			//������
	char petkind[MAXKINDS][20];	//ͬ���������������
} Item;

#define MAXITEMS 10			//�ø�ֵ���Ե�������ʱ�����Ƿ�˳�����С������Ҫ���������ø���

typedef struct node
{
	Item item;
	struct node * left;		/*ָ�����֧��ָ��*/
	struct node * right;	/*ָ���ҷ�֧��ָ��*/
} Node;


typedef struct tree
{
	Node * root;			/*ָ��������ָ��*/
	int size;				/*������Ŀ�ĸ���*/
} Tree;


/*����ԭ��*/

/*������  ��һ������ʼ��Ϊһ������*/
/*����ǰ��ptreeָ��һ����*/
/*�����󣺸����ѱ���ʼ��Ϊ����*/
void InitializeTree(Tree * ptree);


/*������  ȷ�����Ƿ�Ϊ��*/
/*����ǰ��ptreeָ��һ����*/
/*�����������Ϊ����������tree��
		  ���򷵻�false*/
bool TreeIsEmpty(const Tree * ptree);


/*������  ȷ�����Ƿ�����*/
/*����ǰ��ptreeָ��һ����*/
/*�����������������������tree��
		  ���򷵻�false*/
bool TreeIsFull(const Tree * ptree);


/*������  ȷ��������Ŀ�ĸ���*/
/*����ǰ��ptreeָ��һ����*/
/*�����󣺺�������������Ŀ�ĸ���*/
int TreeItemCount(const Tree * ptree);


/*������  ���������һ����Ŀ*/
/*����ǰ��pi�Ǵ������Ŀ�ĵ�ַ
		  ptreeָ��һ���ѳ�ʼ������*/
/*������������ܣ���������Ŀ��ӵ�����
		  ������tree�����򷵻�false*/
bool AddItem(const Item * pi, Tree * ptree);


/*������  �����в���һ����Ŀ*/
/*����ǰ��piָ��һ����Ŀ��
		  ptreeָ��һ���ѳ�ʼ������*/
/*�����������Ŀ�����У�����Ŀ����
		  ���Ƶ�*pi, ��������tree��
		  ���򷵻�false*/
bool InTree(Item * pi, const Tree * ptree);


/*������  ������ɾ��һ����Ŀ*/
/*����ǰ��pi�Ǵ�ɾ����Ŀ�ĵ�ַ
		  ptreeָ��һ���ѳ�ʼ������*/
/*������������ܣ�����������ɾ������Ŀ
		  ������tree�����򷵻�false*/
bool DeleteItem(const Item * pi, Tree * ptree);


/*������  ��һ����������������ÿһ����Ŀ*/
/*����ǰ��ptreeָ��һ������
		  pfunָ��һ��û�з���ֵ�ĺ�����
		  �ú�������һ��Item��Ϊ����*/
/*������pfunָ��ĺ���������������
		  ÿһ����Ŀһ��*/
void Traverse(const Tree * ptree, void(*pfun)(Item item));


/*������  ������ɾ�����нڵ�*/
/*����ǰ��ptreeָ��һ���ѳ�ʼ������*/
/*�����󣺸���Ϊ����*/
void EmptyAll(Tree * ptree);


#endif // !_TREE_H_
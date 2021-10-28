//tree.c -- �����͵�ʵ�ֽӿ�

#include <stdio.h>
#include <stdlib.h>							//malloc(), free()
#include <stdbool.h>						//bool������C++����
#include <string.h>							//strcmp()
#include <Windows.h>						//Sleep()
#include "tree.h"

//�ֲ���������
typedef struct pair
{
	Node * parent;
	Node * child;
} Pair;

//�ֲ�����ԭ��
static Node * MakeNode(const Item * pi);
static bool ToLeft(const Item * pi1, const Item * pi2);
static bool ToRight(const Item * pi1, const Item * pi2);
static void AddNode(Node * pnew_node, Node * root);
static void InOrder(const Node * root, void(*pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Node ** ptr);
static void DeleteAllNodes(Node * root);


//��������
void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	if (ptree->root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TreeIsFull(const Tree * ptree)
{
	if (ptree->size == MAXITEMS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
	Node  * pnew_node;
	Pair find;

	//������Ƿ�����
	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full.\n");
		return false;
	}
	//�����������Ƿ��Ѵ���
	find = SeekItem(pi, ptree);
	if (find.child != NULL)
	{
		find.child->item.count++;
		//fprintf(stderr, "Attempted to add duplicate item.\n");
		return true;
	}

	//���Դ����½ڵ�
	pnew_node = MakeNode(pi);
	if (pnew_node == NULL)
	{
		fprintf(stderr, "Couldn't create node.\n");
		return false;
	}
	//�����ɹ����������ṹ
	pnew_node->item.count = 1;
	ptree->size++;
	if (ptree->root == NULL)
	{
		ptree->root = pnew_node;
	}
	else
	{
		AddNode(pnew_node, ptree->root);
	}	
	return true;
}

bool InTree(const Item * pi, const Tree * ptree)
{
	return SeekItem(pi, ptree).child == NULL ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;

	look = SeekItem(pi, ptree);
	if (look.child == NULL)
	{
		return false;		//ʧ�ܷ���
	}

	//�����ж��ʱ����������С1
	if (look.child->item.count > 1)
	{
		look.child->item.count--;
		return true;
	}
	//���ʽ���һ��ʱ��ɾ���ڵ�
	if (look.parent == NULL)
	{
		DeleteNode(&ptree->root);
	}
	else if (look.parent->left == look.child)
	{
		DeleteNode(&look.parent->left);
	}
	else
	{
		DeleteNode(&look.parent->right);
	}
	ptree->size--;
	return true;
	
}

void Traverse(const Tree * ptree, void(*pfun)(Item item))
{
	if (ptree->root != NULL)
	{
		InOrder(ptree->root, pfun);
	}
}

void EmptyAll(Tree * ptree)
{
	if (ptree->root != NULL)
	{
		DeleteAllNodes(ptree->root);
	}
	ptree->root = NULL;
	ptree->size = 0;
}



//Ϊ����Ŀ���͸��ӵĽӿ�


int GetItems(const Item * pi, Tree * ptree)
{
	Pair look;

	look = SeekItem(pi, ptree);
	if (look.child == NULL)
	{
		return 0;
	}
	else
	{
		return look.child->item.count;
	}
}


//�ֲ���������

Node * MakeNode(const Item * pi)
{
	Node * pnew_node;

	pnew_node = (Node *)malloc(sizeof(Node));		//����ڵ��ڴ�
	if (pnew_node != NULL)							//���䵽ʱ���нڵ�ĳ�ʼ��
	{
		pnew_node->item = *pi;
		pnew_node->left = NULL;
		pnew_node->right = NULL;
	}
	return pnew_node;
}

bool ToLeft(const Item * pi1, const Item * pi2)
{
	int comp1;

	if ((comp1 = strcmp(pi1->word, pi2->word)) < 0)
	{
		return true;
	}
	else if (comp1 == 0 && strcmp(pi1->word, pi2->word) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ToRight(const Item * pi1, const Item * pi2)
{
	int comp1;

	if ((comp1 = strcmp(pi1->word, pi2->word)) > 0)
	{
		return true;
	}
	else if (comp1 = 0 && strcmp(pi1->word, pi2->word) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AddNode(Node * pnew_node, Node * root)					//�ݹ�
{
	if (ToLeft(&pnew_node->item, &root->item))
	{
		if (root->left == NULL)
		{
			root->left = pnew_node;
		}
		else
		{
			AddNode(pnew_node, root->left);
		}
	}
	else if (ToRight(&pnew_node->item,&root->item))
	{
		if (root->right == NULL)
		{
			root->right = pnew_node;
		}
		else
		{
			AddNode(pnew_node, root->right);
		}
	}
	else
	{
		fprintf(stderr, "location error in AddNode().\n");
		Sleep((unsigned long)3000);
		exit(EXIT_FAILURE);
	}
}

void InOrder(const Node * root, void(*pfun)(Item item))		//�ݹ�
{
	//�ݹ���÷��ʷǿյ�����������˳���������
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

Pair SeekItem(const Item * pi, const Tree * ptree)			//�ݹ�
{
	Pair look;

	look.parent = NULL;
	look.child = ptree->root;

	if (look.child == NULL)
	{
		return look;										//��������
	}
	while (look.child != NULL)
	{
		if (ToLeft(pi, &look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
		{
			break;				//���ǰ��������������㣬�ض�Ϊ��ȵ�������ж�ѭ����look.child����Ŀ��ڵ�ĵ�ַ
		}
	}
	return look;
}

void DeleteNode(Node ** ptr)
{
	Node * temp;

	puts((*ptr)->item.word);
	if ((*ptr)->left == NULL)
	{
		*ptr = (*ptr)->right;	//ֻ����֧ʱ���ô�ɾ�ڵ�ĸ��ڵ���ָ��ýڵ��ָ�룬�޸�Ϊָ���ɾ�ڵ��������
	}
	else if ((*ptr)->right == NULL)
	{
		*ptr = (*ptr)->left;	//ͬ��
	}
	else						//��ɾ�ڵ���2���ӽڵ�
	{
								//������������֧���ҿյ�������
		for (temp = (*ptr)->left; temp->right == NULL; temp = temp->right)
		{
			continue;
		}
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = temp->left;
		free(temp);
	}
}

void DeleteAllNodes(Node * root)							//�ݹ�
{
	Node *pright;

	if (root != NULL)
	{
		//�������ɾ���ǿյ�����
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}
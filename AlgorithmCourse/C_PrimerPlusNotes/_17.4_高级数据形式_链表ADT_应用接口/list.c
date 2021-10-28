//list.c -- ֧���б�����ĺ���

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*�ֲ�����ԭ��*/
static void CopyToNode(Item item, Node * pnode);

//�ӿں���

/*���б�����Ϊ���б�*/
void InitializeList(List * plist)
{
	*plist = NULL;
}

/*����б�Ϊ���򷵻��棬���򷵻ؼ�*/
bool ListIsEmpty(const List * plist)
{
	if (*plist == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*����б������򷵻��棬���򷵻ؼ�*/
bool ListIsFull(const List * plist)
{
	Node * pnode = (Node *)malloc(sizeof(Node));
	if (pnode == NULL)
	{
		return true;
	}
	else
	{
		free(pnode);
		return false;
	}
}

/*���ؽڵ���*/
unsigned int ListItemCount(const List * plist)
{
	Node * pnode = *plist;
	unsigned int count = 0;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

/*���������Ŀ�Ľڵ㣬��������ӵ�
plistָ����б��β���������ķ�����*/
bool AddItem(Item item, List * plist)
{
	Node * pnode = (Node *)malloc(sizeof(Node));
	Node * scan = *plist;

	if (pnode == NULL)
	{
		return false;
	}

	CopyToNode(item, pnode);
	pnode->next = NULL;
	if (scan == NULL)
	{
		*plist = pnode;
	}
	else
	{
		while (scan->next != NULL)
		{
			scan = scan->next;
		}
		scan->next = pnode;
	}


	return true;
}

/*����ÿ���ڵ㲢�����Ƿֱ�ִ��pfunָ��ĺ���*/
void Traverse(const List * plist, void(*pfun)(Item item))
{
	Node * pnode = *plist;

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}


/*�ͷ���malloc()������ڴ�
���б�ָ������ΪNULL*/
void EmptyTheList(List * plist)
{
	Node * tmp;

	while (*plist != NULL)
	{
		tmp = (*plist)->next;
		free(*plist);
		*plist = tmp;
	}
}


//�ֲ���������

//��һ����Ŀ���Ƶ�һ���ڵ���
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}
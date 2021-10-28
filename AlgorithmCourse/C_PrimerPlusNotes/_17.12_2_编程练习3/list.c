//list.c -- ֧���б�����ĺ���

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*�ֲ�����ԭ��*/
static void CopyToList(Item item, List * plist);


//�ӿں���

/*���б�����Ϊ���б�*/
void InitializeList(List * plist)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		plist->entries[i] = (Item){ "", 0 };
	}
	plist->items = 0;
}

/*����б�Ϊ���򷵻��棬���򷵻ؼ�*/
bool ListIsEmpty(const List * plist)
{
	return plist->items == 0 ? true : false;
}

/*����б������򷵻��棬���򷵻ؼ�*/
bool ListIsFull(const List * plist)
{
	return plist->items == MAXSIZE ? true : false;
}

/*���ؽڵ���*/
unsigned int ListItemCount(const List * plist)
{
	return plist->items;
}

/*���������Ŀ�Ľڵ㣬��������ӵ�
plistָ����б��β��*/
bool AddItem(Item item, List * plist)
{
	if (plist->items == MAXSIZE)
	{
		return false;
	}

	CopyToList(item, plist);
	plist->items++;
	return true;
}

/*����ÿ���ڵ㲢�����Ƿֱ�ִ��pfunָ��ĺ���*/
void Traverse(const List * plist, void(*pfun)(Item item))
{
	for (int i = 0; i < plist->items; i++)
	{
		(*pfun)(plist->entries[i]);
	}
}


/*�ͷ���malloc()������ڴ�
���б�ָ������ΪNULL*/
void EmptyTheList(List * plist)
{
	InitializeList(plist);
}


//�ֲ���������

//��һ����Ŀ���Ƶ��б���
static void CopyToList(Item item, List * plist)
{
	plist->entries[plist->items] = item;
}
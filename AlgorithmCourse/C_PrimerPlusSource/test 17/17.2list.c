#include <stdio.h>
#include <stdlib.h>
#include "17.2.h"

/* �ֲ�����ԭ�� */
static void CopyToNode(Item item, Node * pnode);

/* �ӿں��� */
/* ����������Ϊ�� */
void InitializeList(List * plist)
{
    plist->head = NULL;
    plist->end = NULL;
}
/* �������Ϊ�գ�����true */
bool ListIsEmpty(const List * plist)
{
    if (plist->head == NULL)
        return true;
    else
        return false;
}
/* �����������������true */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}
/* ���ؽڵ������ */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = plist->head; /* ��������Ŀ�ʼ */
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next; /* ������һ���ڵ� */
    }
    return count;
}
/* ����������Ľڵ㣬�������������plistָ�������ĩβ��������ʵ�֣� */
bool AddItem(Item item, List * plist)
{
    Node * pnew;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;  /* ʧ��ʱ�˳����� */

    CopyToNode(item, pnew);
    pnew->next = NULL;

    if (plist->head == NULL)
        plist->head = pnew;
    else
        plist->end->next= pnew;
    plist->end = pnew;

    return true;
}
/* ����ÿ���ڵ㲢ִ��pfunָ��ĺ��� */
void Traverse(const List * plist, void(*pfun)(Item item))
{
    Node * pnode = plist->head; /* ��������Ŀ�ʼ */
    while (pnode != NULL)
    {
        (*pfun)(pnode->item); /* �Ѻ���Ӧ���������е��� */
        pnode = pnode->next; /* ǰ������һ�� */
    }
}
/* �ͷ���malloc()������ڴ� *//* ��������ָ��ΪNULL   */
void EmptyTheList(List * plist)
{
    Node * psave;
    while (plist->head != NULL)
    {
        psave = plist->head;
        plist->head = plist->head->next;
        free(psave);
    }
}
/* �ֲ��������� */
/* ��һ��������ڵ��� */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item; /* �����ṹ */
}

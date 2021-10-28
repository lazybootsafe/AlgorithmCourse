#include <stdio.h>
#include <stdlib.h>
#include "17.3.h"


/* �ӿں��� */
/* ����������Ϊ�� */
void InitializeList(List * plist)
{
    for(int i=0;i<MAXSIZE;i++)
    {
        strcpy(plist->entries[i].title,"");
        plist->entries[i].rating=0;
        plist->items=0;
    }
}
/* �������Ϊ�գ�����true */
bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}
/* �����������������true */
bool ListIsFull(const List * plist)
{
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}
/* ���ؽڵ������ */
unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}
/* ����������Ľڵ㣬�������������plistָ�������ĩβ��������ʵ�֣� */
bool AddItem(Item item, List * plist)
{
    if (plist->items == MAXSIZE)
    {
        fprintf(stderr,"����.\n");
        return false;  /* ʧ��ʱ�˳����� */
    }
    plist->entries[plist->items] =item;
    (plist->items)++;

    return true;
}
/* ����ÿ���ڵ㲢ִ��pfunָ��ĺ��� */
void Traverse(const List * plist, void(*pfun)(Item item))
{
    for(int i=0;i<plist->items;i++)
    {
        (*pfun)(plist->entries[i]); /* �Ѻ���Ӧ���������е��� */
    }
}
/* �ͷ���malloc()������ڴ� *//* ��������ָ��ΪNULL   */
void DeleteAll(List * plist)
{
    for(int i=0;i<plist->items;i++)
    {
        strcpy(plist->entries[i].title,"");
        plist->entries[i].rating=0;
        plist->items=0;
    }
}

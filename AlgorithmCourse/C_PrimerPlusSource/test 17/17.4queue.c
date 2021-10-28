/* queue.c -- Queue���͵�ʵ�� */
#include <stdio.h>
#include <stdlib.h>
#include "17.4.h"

/* �ֲ����� */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

//��ʼ������
void InitializeQueue(Queue * pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue * pq)
{
    if(pq->items == MAXQUEUE)
        return true;
    else
        return false;
}

bool QueueIsEmpty(const Queue * pq)
{
    if(pq->items == 0)
        return true;
    else
        return false;
}

int QueueItemCount(const Queue * pq)
{
    return pq->items;
}

bool EnQueue(Item item, Queue * pq)
{
    Node * pnew;//1)����һ���½ڵ㣻

    if (QueueIsFull(pq))
        return false;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr, "����ʧ��!\n");
        exit(1);
    }
    CopyToNode(item, pnew);//2)��������ڵ���
    pnew->next = NULL;//3)���ýڵ��nextָ��ΪNULL�������ýڵ������һ���ڵ㣻
    if (QueueIsEmpty(pq))
        pq->front = pnew;     /* ��λ�ڶ��е��׶�   */
    else//4)���õ�ǰβ�ڵ��nextָ��ָ���½ڵ㣬���½ڵ����ӵ������У�
        pq->rear->next = pnew;  /* ���ӵ����е�β��   */
    pq->rear = pnew;//5)��rearָ��ָ���½ڵ㣬�Ա��ҵ����Ľڵ㣻
    pq->items++; //6)������1��

    return true;
}

bool DeQueue(Item * pitem, Queue * pq)
{
    Node * pt;

    if (QueueIsEmpty(pq))
    {
        fprintf(stderr,"û�п�ɾ����.\n");
        return false;
    }

    CopyToItem(pq->front, pitem);//1)������������ı����У�
    pt = pq->front;
    pq->front = pq->front->next;//3)������ָ��ָ������е���һ���
    free(pt);//2)�ͷſճ��Ľڵ�ʹ�õ��ڴ�ռ䣻
    pq->items--;//5)������1��

    if (pq->items == 0)
        pq->rear = NULL;//4)���ɾ�����һ���βָ�붼����ΪNULL��

    return true;
}

/* ��ն��� */
void EmptyTheQueue(Queue * pq)
{
    Item dummy;

    while (!QueueIsEmpty(pq))
        DeQueue(&dummy, pq);
}

/* �ֲ����� */
static void CopyToNode(Item item, Node * pn)
{
    pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi)
{
    *pi = pn->item;
}

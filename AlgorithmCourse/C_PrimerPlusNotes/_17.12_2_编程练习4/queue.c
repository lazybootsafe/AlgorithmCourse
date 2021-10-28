//queue.c -- �������͵�ʵ���ļ�

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/*�ֲ�����*/
static void CopyToNode(Item item, Node * pnode);
static void CopyToItem(Node * pnode, Item * pitem);

void InitializeQueue(Queue * pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsEmpty(const Queue * pq)
{
	return pq->items == 0;
}

bool QueueIsFull(const Queue * pq)
{
	return pq->items == MAXQUEUE;
}

int QueueItemCount(const Queue * pq)
{
	return pq->items;
}

bool EnQueue(Item item, Queue * pq)
{
	Node * pnew;

	if (QueueIsFull(pq))
	{
		return false;
	}

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (QueueIsEmpty(pq))
	{
		pq->front = pnew;			//��Ŀλ�ڶ����׶�
	}
	else
	{
		pq->rear->next = pnew;		//��Ŀ���ӵ�����β��
	}
	pq->rear = pnew;				//βָ��ָ��β�ڵ�
	pq->items++;					//��Ŀ�� + 1

	return true;
}

bool DeQueue(Item * pitem, Queue * pq)
{
	Node * pt;

	if (QueueIsEmpty(pq))
	{
		return false;
	}

	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (pq->items == 0)
	{
		pq->rear = NULL;
	}
	
	return true;
}

void EmptyTheQueue(Queue * pq)
{
	Item item;

	while (!QueueIsEmpty(pq))
	{
		DeQueue(&item, pq);
	}
}

//�ֲ���������
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}

static void CopyToItem(Node * pnode, Item * pitem)
{
	*pitem = pnode->item;
}
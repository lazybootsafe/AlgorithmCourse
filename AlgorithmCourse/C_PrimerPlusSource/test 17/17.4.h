#ifndef _17_4_H_
#define _17_4_H_
#include <stdbool.h>
#define MAXQUEUE 10

// ���������Item���͵Ķ��壬����
typedef struct item
{
    long arrive;   /* һλ�˿ͼ�����е�ʱ�� */
    int processtime; /* �ù˿���ѯʱ���ѵ�ʱ�� */
}Item;

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct queue
{
    Node * front;
    Node * rear;
    int items;  /* �����е�����    */
} Queue;

//��ʼ������
void InitializeQueue(Queue * pq);

//�������Ƿ�����
bool QueueIsFull(const Queue * pq);

//�������Ƿ�Ϊ��
bool QueueIsEmpty(const Queue *pq);

// ȷ�������е�����
int QueueItemCount(const Queue * pq);

//�ڶ���ĩβ�����
bool EnQueue(Item item, Queue * pq);

//�Ӷ��еĿ�ͷɾ����
bool DeQueue(Item *pitem, Queue * pq);

//��ն���
void EmptyTheQueue(Queue * pq);
#endif // _17_4_H_

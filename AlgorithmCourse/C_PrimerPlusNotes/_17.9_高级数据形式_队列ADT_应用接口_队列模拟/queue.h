//queue.h -- ���нӿ�ͷ�ļ�

#ifndef _QUEUE_H_

#define _QUEUE_H_

#include <stdbool.h>

/*���������Item�����Ͷ���*/
//����
typedef struct item
{
	long arrive;		//һλ�˿ͼ�����е�ʱ��
	int processtime;	//�ù˿���Ҫ����ѯʱ��
} Item;

#define MAXQUEUE 10		//���е���󳤶�

typedef	struct node
{
	Item item;
	struct node * next;
} Node;

typedef struct queue
{
	Node * front;		//ָ������׵�ָ��
	Node * rear;		//ָ�����β��ָ��
	int items;			//��������Ŀ�ĸ���
} Queue;

/*��������ʼ������
����ǰ��pqָ��һ������
�����󣺸ö��б���ʼ��Ϊ�ն���*/
void InitializeQueue(Queue * pq);


/*�������������Ƿ�Ϊ��
����ǰ��pqָ��һ���ѳ�ʼ���Ķ���
�������������Ϊ�գ��򷵻�true��
���򷵻�false*/
bool QueueIsEmpty(const Queue * pq);


/*�������������Ƿ�����
����ǰ��pqָ��һ���ѳ�ʼ���Ķ���
��������������������򷵻�true��
���򷵻�false*/
bool QueueIsFull(const Queue * pq);


/*������ȷ����������Ŀ�ĸ���
����ǰ��pqָ��һ���ѳ�ʼ���Ķ���
�����󣺷���һ����������Ŀ�ĸ���*/
int QueueItemCount(const Queue * pq);


/*�����������β�������Ŀ
����ǰ��pqָ��һ���ѳ�ʼ���Ķ���
item��Ҫ��ӵ�����β����Ŀ
�������������δ�����򽫸���Ŀ
��ӵ�����β����������true������
����false*/
bool EnQueue(Item item, Queue * pq);


/*�������Ӷ����׶�ɾ����Ŀ
����ǰ��pqָ��һ���ѳ�ʼ���Ķ���
������������зǿգ������׶˵�
��Ŀ�����Ƶ�*pitem,���Ӷ�����ɾ
������������true������������ʹ
����Ϊ�գ��Ѷ�������Ϊ�ն���
������п�ʼʱΪ�գ����ı���У�
��������false*/
bool DeQueue(Item * pitem, Queue * pq);


/*��������ն���
����ǰ��pqָ��һ���Ѿ���ʼ���Ķ���
�����󣺶��б����*/
void EmptyTheQueue(Queue * pq);


#endif // !_QUEUE_H_
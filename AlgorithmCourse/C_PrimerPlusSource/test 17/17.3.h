#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h> /* C99����      */
/* �ض���������� */
#include <string.h>
#define TSIZE  45 /* �����Ӱ���������С */
#define MAXSIZE 100

typedef struct film{
    char title[TSIZE];
    int rating;
}Item;

typedef struct list{
    Item entries[MAXSIZE];//�ں��������
    int  items; //list�е�����
}List;

//��ʼ������Ϊ��
void InitializeList(List * plist);

//����Ϊ��,����ture
bool ListIsEmpty(const List *plist);

//����Ϊ��������true
bool ListIsFull(const List *plist);

//ȷ�������е�����, plistָ��һ���ѳ�ʼ��������
unsigned int ListItemCount(const List *plist);

//Ϊ���������ɹ�����ture
bool AddItem(Item item, List * plist);

//�Ѻ��������������е�ÿһ��,�����б�
void Traverse(const List *plist, void(*pfun)(Item item));

//�������
void DeleteAll(List * plist);
#endif

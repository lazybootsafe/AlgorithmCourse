#ifndef MOVIE_H_
#define MOVIE_H_

#define TSIZE 45
#define MAXSIZE 5

typedef struct film {
	char titile[TSIZE];
	int rating;
} Item;

typedef struct list {
	Item entries[MAXSIZE];
	int items;
} List;

//��ʼ������Ϊ��
void InitializeList(List * plist);

//����Ϊ��,����1
int ListIsEmpty(const List * plist);

//����Ϊ��������1
int ListIsFull(const List * plist);

//Ϊ���������ɹ�����1
int AddItem(List * plist, Item item);

//ȷ�����������
unsigned int ListItemCount(List * plist);

//��������
void Traverse(const List * plist, void (*pfun)(Item item));

//�������
void DeleteAll(List * plist);

#endif
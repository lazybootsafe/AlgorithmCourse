#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode, *BiTree;   // ��������

typedef enum Status{
	SUCCESS,
	ERROR
}Status;

//�ö���ʵ�ֲ������
typedef struct QueueNode{  
	BiTree data;
	struct QueueNode *next;
}QueueNode,*pQueueNode;
 
typedef struct Queue{
	pQueueNode front;
	pQueueNode rear;
}Queue,*pQueue;



/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
//Status InitBiTree(BiTree T);


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree T);


/**
 *  @name        : Status CreateBiTree(BiTree T, char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
char* CreateBiTree(BiTree T, char* definition);


/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderTraverse(BiTree T, void (*visit)(TElemType e));


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree T, void (*visit)(TElemType e));	


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree T, void (*visit)(TElemType e));


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
void LevelOrderTraverse(BiTree T, void (*visit)(TElemType e));


/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree T);


#endif // BINARYTREE_H_INCLUDED
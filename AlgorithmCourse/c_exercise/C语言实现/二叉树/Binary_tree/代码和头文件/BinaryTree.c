#include "../head/BinaryTree.h"


//后序遍历摧毁二叉树T

Status DestroyBiTree(BiTree T)
{
	BiTree p,pr;
	p = pr = NULL;
	if (T == NULL)
		return ERROR;
	p = T->lchild;
	pr = T->rchild;
	T->lchild = NULL;
	T->rchild = NULL;
	free(T);
	T = NULL;
	DestroyBiTree(p);
	DestroyBiTree(pr);
	return SUCCESS;
}
void destroy(BiTree T)
{
	if(T == NULL)
		printf("\n请先构造二叉树\n");
	else
	{
		DestroyBiTree(T);
		printf("\n已销毁原有二叉树\n");
	}
}



//先序遍历构造二叉树T
char* createBiTree(BiTree *T,char* definition)
{	
	char ch = *definition;

	if ('#' == ch)            //扩展二叉树，虚结点 == #
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));	
		if (!*T)
		{
			exit(1);	//错误退出
		}
		(*T)->data = ch;	//生成根结点
		definition = createBiTree(&((*T)->lchild),definition+1);	//构造左子树,并记录字符位置
		definition = createBiTree(&((*T)->rchild),definition+1);	//构造右子树,并记录字符位置
	}
	return definition;
}
void create(BiTree *T)
{
	char ch[100];
	int i,char_sum,end_sum;//用char_sum和end_sum分别记录输入的字符和‘#’数量，来判断是否输错

	if(*T != NULL)
		destroy(*T);
	    *T = NULL;
	printf("\n【新建】先序输入建树字符串(插入'#'表示空子树): ");
	fflush(stdin);
	scanf("%s",ch);

	for(char_sum = end_sum = i = 0; ch[i] != 0; i++)
	{
		if('0' <= ch[i] && ch[i] <= '9') 
			char_sum ++;
		if('#' == ch[i] ) 
			end_sum ++;
	}
	if(char_sum + end_sum == i  &&  char_sum + 1 == end_sum  && ch[0] != '#')  //简陋的输入排错
		createBiTree(T,ch);
	else
		printf("\n输入有误\n");
}


//输出节点
void print(TElemType e)
{
	printf("【%c】",e);
}


//先序遍历二叉树T
Status PreOrderTraverse(BiTree T, void (*visit)(TElemType e))
{
	if ( NULL == T)
		return SUCCESS;
	(*visit)(T->data);
	if ( PreOrderTraverse(T->lchild,visit) == SUCCESS)
	{
		if ( PreOrderTraverse(T->rchild,visit) == SUCCESS )
			return SUCCESS;
	}
	return ERROR;
}
void pre(BiTree T)
{
	if(T == NULL)
		printf("\n请先构造二叉树\n");
	else
	{
		printf("\n【输出】先序遍历: ");
		PreOrderTraverse(T,print);
	}
}


//中序遍历二叉树T
Status InOrderTraverse(BiTree T, void (*visit)(TElemType e))
{
	if (NULL == T)
		return SUCCESS;
	if (InOrderTraverse( T->lchild, visit) == SUCCESS )
	{
		(*visit)(T->data); 
		if ( InOrderTraverse( T->rchild, visit) == SUCCESS )
			return SUCCESS;
	} 
	return ERROR;
}
void in(BiTree T)
{
	if(T != NULL)
	{
		printf("\n【输出】中序遍历: ");
		InOrderTraverse(T,print);
	}
}


//后序遍历二叉树T
Status PostOrderTraverse(BiTree T, void (*visit)(TElemType e))
{
	if ( NULL == T)
	{
		return SUCCESS;
	} 
	if ( PostOrderTraverse( T->lchild, visit) == SUCCESS )	
	{
		if ( PostOrderTraverse( T->rchild, visit) == SUCCESS)
		{
			(*visit)(T->data);
			return SUCCESS;
		}
	}
	return ERROR;
}
void post(BiTree T)
{
	if(T != NULL)
	{
		printf("\n【输出】后序遍历: ");
		PostOrderTraverse(T,print);
	}
}


//层序遍历二叉树T
pQueue init(pQueue pq){
	pq->front=(pQueueNode)malloc(sizeof(QueueNode));
	pq->front->next=NULL;
	pq->rear=pq->front;
	return pq;
}
void enqueue(pQueue pq,BiTree t){
	pQueueNode pNew=(pQueueNode)malloc(sizeof(QueueNode));
	pNew->data=t;
	pNew->next=NULL;
	pq->rear->next=pNew;
	pq->rear=pNew;
}
BiTree dequeue(pQueue pq){
	BiTree x;
	pQueueNode pTemp=(pQueueNode)malloc(sizeof(QueueNode));
	pTemp=pq->front->next;
	if(pTemp->next==NULL){
		pq->rear=pq->front;
	}else{
		pq->front->next=pTemp->next;
	}
	x=pTemp->data;
	free(pTemp);
	return x;
}
void LevelOrderTraverse(BiTree T, void (*visit)(TElemType e))
{
	pQueue pq=(pQueue)malloc(sizeof(Queue));
	pq=init(pq);

	if(T != NULL)
	{
		printf("\n【输出】层序遍历: ");
		enqueue(pq,T);
	    while(pq->rear!=pq->front){
		    BiTree x=dequeue(pq);		
			visit(x->data);		
			if(x->lchild){			
				enqueue(pq,x->lchild);		
			}
			if(x->rchild){
				enqueue(pq,x->rchild);
			}
		}
	}
}


//构造出前缀表达式二叉树
char* createPrBiTree(BiTree *T,char* definition)//前缀表达式先序遍历构造二叉树T
{	
	char ch = *definition;
	
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = ch;
    
	if ('0' <= ch && ch <= '9')            
	{   //不构造子树  
		(*T)->lchild = NULL;               
		(*T)->rchild = NULL;   
	}
	else
	{	//构造子树,并记录字符位置
		definition = createPrBiTree(&((*T)->lchild),definition+1);
		definition = createPrBiTree(&((*T)->rchild),definition+1);	
	}
	return definition;
}
//求值
int Value(BiTree T)
{
	if(T->data <= '9'  &&  T->data >= '0')
		return (T->data - '0');
	else
	{
		switch(T->data)            //因为这一步的T->data必为运算符，则必有左右孩子节点且不空
		{
     		case'+':  return Value(T->lchild) + Value(T->rchild); break;
			case'-':  return Value(T->lchild) - Value(T->rchild); break;
			case'*':  return Value(T->lchild) * Value(T->rchild); break;
			case'/':  return Value(T->lchild) / Value(T->rchild); break;
		}
	}
}
void countPrBiTree(BiTree *T)
{
	char ch[100];
	int i,char_sum,end_sum;

	if(*T != NULL)
		destroy(*T);
	    *T = NULL;
	printf("\n【新建】输入前缀表达式字符串: ");
	fflush(stdin);
	scanf("%s",ch);	

	for(char_sum = end_sum = i = 0; ch[i] != 0; i++)
	{
		if('0' <= ch[i] && ch[i] <= '9') 
			char_sum ++;
		if('+' == ch[i] || '-' == ch[i] || '*' == ch[i] || '/' == ch[i]) 
			end_sum ++;
	}
	if(char_sum + end_sum == i  &&  char_sum -1 == end_sum)  //简陋的输入排错
	{
		createPrBiTree(T,ch);    
		printf("\n计算结果为: %d \n",Value(*T));
	}
	else
		printf("\n输入有误\n");	
}



//功能表
void menu()
{
	
	printf("                        **请选择以下功能**\n\n");
	printf("     |——————————输入  &&   功能——————————————|\n");
	printf("     |-———————————————————————————————|\n");
	printf("     |---------------------a    TO   构造二叉树T---------------------|\n");
	printf("     |---------------------b    TO   摧毁二叉树T---------------------|\n");
	printf("     |---------------------c    TO   遍历二叉树T---------------------|\n");
	printf("     |---------------------d    TO   构造前缀表达式二叉树并求值------|\n");
	printf("     |---------------------e    TO   退出----------------------------|\n");
	printf("     |-———————————————————————————————|\n");
	printf("     |-———————————————————————————————|\n");
}


//简化交互
void reactive()
{
	printf("\n");
	system("PAUSE");
	system("cls");
	menu();
	printf("\n【操作】输入: ");
}

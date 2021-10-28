#include "../head/BinaryTree.h"


//��������ݻٶ�����T

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
		printf("\n���ȹ��������\n");
	else
	{
		DestroyBiTree(T);
		printf("\n������ԭ�ж�����\n");
	}
}



//����������������T
char* createBiTree(BiTree *T,char* definition)
{	
	char ch = *definition;

	if ('#' == ch)            //��չ������������ == #
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));	
		if (!*T)
		{
			exit(1);	//�����˳�
		}
		(*T)->data = ch;	//���ɸ����
		definition = createBiTree(&((*T)->lchild),definition+1);	//����������,����¼�ַ�λ��
		definition = createBiTree(&((*T)->rchild),definition+1);	//����������,����¼�ַ�λ��
	}
	return definition;
}
void create(BiTree *T)
{
	char ch[100];
	int i,char_sum,end_sum;//��char_sum��end_sum�ֱ��¼������ַ��͡�#�����������ж��Ƿ����

	if(*T != NULL)
		destroy(*T);
	    *T = NULL;
	printf("\n���½����������뽨���ַ���(����'#'��ʾ������): ");
	fflush(stdin);
	scanf("%s",ch);

	for(char_sum = end_sum = i = 0; ch[i] != 0; i++)
	{
		if('0' <= ch[i] && ch[i] <= '9') 
			char_sum ++;
		if('#' == ch[i] ) 
			end_sum ++;
	}
	if(char_sum + end_sum == i  &&  char_sum + 1 == end_sum  && ch[0] != '#')  //��ª�������Ŵ�
		createBiTree(T,ch);
	else
		printf("\n��������\n");
}


//����ڵ�
void print(TElemType e)
{
	printf("��%c��",e);
}


//�������������T
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
		printf("\n���ȹ��������\n");
	else
	{
		printf("\n��������������: ");
		PreOrderTraverse(T,print);
	}
}


//�������������T
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
		printf("\n��������������: ");
		InOrderTraverse(T,print);
	}
}


//�������������T
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
		printf("\n��������������: ");
		PostOrderTraverse(T,print);
	}
}


//�������������T
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
		printf("\n��������������: ");
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


//�����ǰ׺���ʽ������
char* createPrBiTree(BiTree *T,char* definition)//ǰ׺���ʽ����������������T
{	
	char ch = *definition;
	
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = ch;
    
	if ('0' <= ch && ch <= '9')            
	{   //����������  
		(*T)->lchild = NULL;               
		(*T)->rchild = NULL;   
	}
	else
	{	//��������,����¼�ַ�λ��
		definition = createPrBiTree(&((*T)->lchild),definition+1);
		definition = createPrBiTree(&((*T)->rchild),definition+1);	
	}
	return definition;
}
//��ֵ
int Value(BiTree T)
{
	if(T->data <= '9'  &&  T->data >= '0')
		return (T->data - '0');
	else
	{
		switch(T->data)            //��Ϊ��һ����T->data��Ϊ���������������Һ��ӽڵ��Ҳ���
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
	printf("\n���½�������ǰ׺���ʽ�ַ���: ");
	fflush(stdin);
	scanf("%s",ch);	

	for(char_sum = end_sum = i = 0; ch[i] != 0; i++)
	{
		if('0' <= ch[i] && ch[i] <= '9') 
			char_sum ++;
		if('+' == ch[i] || '-' == ch[i] || '*' == ch[i] || '/' == ch[i]) 
			end_sum ++;
	}
	if(char_sum + end_sum == i  &&  char_sum -1 == end_sum)  //��ª�������Ŵ�
	{
		createPrBiTree(T,ch);    
		printf("\n������Ϊ: %d \n",Value(*T));
	}
	else
		printf("\n��������\n");	
}



//���ܱ�
void menu()
{
	
	printf("                        **��ѡ�����¹���**\n\n");
	printf("     |������������������������  &&   ���ܡ���������������������������|\n");
	printf("     |-��������������������������������������������������������������|\n");
	printf("     |---------------------a    TO   ���������T---------------------|\n");
	printf("     |---------------------b    TO   �ݻٶ�����T---------------------|\n");
	printf("     |---------------------c    TO   ����������T---------------------|\n");
	printf("     |---------------------d    TO   ����ǰ׺���ʽ����������ֵ------|\n");
	printf("     |---------------------e    TO   �˳�----------------------------|\n");
	printf("     |-��������������������������������������������������������������|\n");
	printf("     |-��������������������������������������������������������������|\n");
}


//�򻯽���
void reactive()
{
	printf("\n");
	system("PAUSE");
	system("cls");
	menu();
	printf("\n������������: ");
}

#include "../head/LQueue.h"
//初始化
void InitLQueue(LQueue **Q)
{
	*Q = (LQueue *)malloc(sizeof(LQueue));
	(*Q)->front = NULL;
	(*Q)->rear = NULL;
	(*Q)->length = 0;
	printf("\n初始化成功\n");
}
//销毁队列
void DestoryLQueue(LQueue *Q)
{
	Node *p;

	if(NULL == Q)
		printf("\n未初始化\n");
	else
	{
		p = Q->front;
	    while(p != NULL)
		{	
			free(p);
		    p = p->next;
		}
	    free(Q);
	    printf("\n销毁成功\n");
	}
}
//检查队列是否为空
Status IsEmptyLQueue(const LQueue *Q)
{
	if(NULL == Q || Q->length == 0)
		return TRUE;  //空，或者不初始化
	else
		return FALSE;  //不空
}
void is_empty(const LQueue *Q)
{
	if(IsEmptyLQueue(Q) == FALSE)
		printf("\n队列不为空\n");
	else if(NULL == Q)
		printf("\n队列未初始化\n");
	else
		printf("\n队列为空\n");
}
//查看队头元素
Status GetHeadLQueue(LQueue *Q)
{
	if(IsEmptyLQueue(Q) == TRUE)
		return FALSE;  //空，或者不初始化
	else
		return TRUE; //不空
}
void get_head(LQueue *Q)
{
	if(TRUE == GetHeadLQueue(Q))
		printf("对头元素为【%d】",Q->front->data);
	else if(NULL == Q)
		printf("\n未初始化\n");
	else
		printf("\n队列为空\n");
}
//确定队列长度
int LengthLQueue(LQueue *Q)
{
	if(NULL == Q)
		return -1;
	return Q->length;
}
void length(LQueue *Q)
{
	if(LengthLQueue(Q) == -1)
		printf("\n未初始化\n");
	else
		printf("\n队列长度为%d\n",Q->length);
}
//入队操作
Status EnLQueue(LQueue *Q, int Data)
{
	Node *p;

	if(NULL == Q)
		return FALSE;

	p = (Node *)malloc(sizeof(Node));
	p->data = Data;
	p->next = NULL;
	if(Q->front == NULL)
	{	
		Q->front = p;
		Q->rear = p;
	}
	else
    {   
		Q->rear->next = p;
	    Q->rear = p;
	}
	Q->length++;
	return TRUE;
}
void enter(LQueue *Q)
{
	int Data,a;

	printf("\n入队数据: ");
	fflush(stdin);
	a = scanf("%d",&Data);
	if(a == 0)
	{
		printf("\n输入错误\n");		
		return ;
	}
	if(EnLQueue(Q,Data) == FALSE)
		printf("\n未初始化\n");
	else
		printf("\n【%d】入队成功\n",Data);
}
//出队操作
Status DeLQueue(LQueue *Q,int *e)
{
	Node *p;
	
	if(TRUE == IsEmptyLQueue(Q))
		return FALSE;

	p = Q->front;
	*e = p->data;
	Q->front = p->next;
	free(p);
	Q->length--;
	return TRUE;
}
void deletel(LQueue *Q)
{
	int e;

	if(TRUE == DeLQueue(Q,&e))
		printf("\n【%d】出队成功\n",e);
	else if(Q == NULL)
		printf("\n未初始化\n");
	else
		printf("\n队列为空\n");
}
//清空队列
void ClearLQueue(LQueue *Q)
{
	Node *p;

	if(NULL == Q)
		printf("\n未初始化\n");
	else
	{
		p = Q->front;
		while(p != NULL)
		{	free(p);
		    p = p->next;
		}
		Q->front = Q->rear = NULL;
		printf("\n清空完毕\n");
	}
}
//遍历函数操作
Status TraverseLQueue(const LQueue *Q, void (*foo)(int a))
{
	Node *p;
	int i = 1;

	if(NULL == Q)
		return FALSE;

    p = Q->front;
	while(p != NULL)
	{
		printf("\n第%d个数字是:",i++);
		foo(p->data);
		p = p->next;
	}
	return TRUE;
}
void traversel(const LQueue *Q)
{
	if(FALSE == TraverseLQueue(Q,LPrint))
		printf("\n未初始化\n");
	else
		printf("\n遍历完成\n");
}
//输出函数
void LPrint(int a)
{
	printf("【%d】",a);
}
//功能表
void menu()
{
	
	printf("                 *请选择以下功能*\n\n");
	printf("     |——————输入  &&   功能———————|\n");
	printf("     |-————————————————————|\n");
	printf("     |-------------a    TO   初始化队列--------|\n");
	printf("     |-------------b    TO   销毁队列----------|\n");
	printf("     |-------------c    TO   判断队列是否为空--|\n");
	printf("     |-------------d    TO   得到队头元素------|\n");
	printf("     |-------------e    TO   检测队列长度------|\n");
	printf("     |-------------f    TO   入队--------------|\n");
	printf("     |-------------g    TO   出队--------------|\n");
	printf("     |-------------h    TO   清空队列----------|\n");
	printf("     |-------------i    TO   遍历输出----------|\n");
	printf("     |-------------j    TO   退出--------------|\n");
	printf("     |-————————————————————|\n");
	printf("     |-————————————————————|\n");
}
//简化交互
void reactive()
{
	printf("\n");
	system("PAUSE");
	system("cls");
	menu();
	printf("\n输入你选择的操作(以输入的第一个字符为准): ");
}

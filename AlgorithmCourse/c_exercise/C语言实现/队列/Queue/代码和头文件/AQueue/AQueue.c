#include "../head/AQueue.h"

//初始化队列
void InitAQueue(AQueue **Q)
{
	int a;

	*Q = (AQueue *)malloc(sizeof(AQueue));
	
	printf("\n队列长度:  ");
	fflush(stdin);
	a = scanf("%d",&(*Q)->length);
	if(a == 0)
	{
		printf("\n输入错误\n");
        return ;
	}
	(*Q)->length ++ ;
	(*Q)->data = (int *)malloc((*Q)->length*sizeof(int));

	(*Q)->front = 0;
	(*Q)->rear = 0;
	printf("\n初始化成功\n");
}
//销毁队列
void DestoryAQueue(AQueue *Q)
{
	if(NULL == Q)
		printf("\n未初始化\n");
	else
	{
		free(Q->data);
	    free(Q);
		printf("\n销毁成功\n");
	}
}
//检查队列是否已满
Status IsFullAQueue(const AQueue *Q)
{
	if(NULL == Q || Q->front == (Q->rear+1) % Q->length)
		return TRUE;

	else return FALSE;
}
void is_full(const AQueue *Q)
{
	if(FALSE == IsFullAQueue(Q))
		printf("\n队列未满\n");
	else if(NULL == Q)  
		printf("\n未初始化\n");
	else  
		printf("\n队列已满\n");
}
//检查队列是否为空
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q == NULL || Q->front == Q->rear)
		return TRUE;

	else return FALSE;
}
void is_empty(const AQueue *Q)
{
	if(FALSE == IsEmptyAQueue(Q))
		printf("\n队列非空\n");
	else if(NULL == Q)
		printf("\n未初始化\n");
	else
		printf("\n队列为空\n");
}
//查看队头元素
Status GetHeadAQueue(AQueue *Q, int *e)
{
	if(TRUE == IsEmptyAQueue(Q))
		return FALSE; 
	*e = Q->data[Q->front];
	return TRUE; 
}
void get_head(AQueue *Q)
{
	int e;
	if(GetHeadAQueue(Q, &e) == TRUE) 
		printf("\n队头元素为%d\n",e);
	else if(Q == NULL)
		printf("\n未初始化\n");
    else
		printf("\n队列为空\n");
}
//确定队列长度
int LengthAQueue(AQueue *Q)
{
	int sum;

    if(NULL ==	Q)
	    return -1;

	else if(Q->front > Q->rear)
		sum = Q->length - Q->front +Q->rear;
	else sum = Q->rear - Q->front;
	return sum;
}
void length(AQueue *Q)
{
	if(LengthAQueue(Q) == -1)
		printf("\n未初始化\n");
	else printf("\n队列长度为%d\n",LengthAQueue(Q));
}
//入队操作
Status EnAQueue(AQueue *Q, int Data)
{
	if(IsFullAQueue(Q) == TRUE)
		return FALSE;

    Q->data[Q->rear] = Data;
	Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}
void enter(AQueue *Q)
{
	int Data;
	int a;

	printf("\n入队数据:  ");
	fflush(stdin);
	a = scanf("%d",&Data);
	if(a == 0)
	{
		printf("\n输入错误\n");
        return ;
	}
	if(EnAQueue(Q,Data) == TRUE)
		printf("\n【%d】入队成功\n",Data);
	else if(Q == NULL)
		printf("\n未初始化\n");
	else
		printf("\n队列已满\n");
}
//出队操作
Status DeAQueue(AQueue *Q,int *Data)
{
	if(TRUE == IsEmptyAQueue(Q))
		return FALSE; 

    *Data = Q->data[Q->front];
	Q->front = (Q->front+1)%Q->length;
	return TRUE;
}
void Delete(AQueue *Q)
{
	int Data;

	if(TRUE == DeAQueue(Q,&Data))
		printf("\n【%d】出队成功\n",Data);
	else if(NULL == Q)
		printf("\n未初始化\n");
	else
		printf("\n队列为空\n");
}
//清空队列
void ClearAQueue(AQueue *Q)
{
	if(NULL == Q)
		printf("\n未初始化\n");
	else
	{
		free(Q->data);
		Q->data = (int *)malloc(Q->length*sizeof(int));
		Q->front = Q->rear = 0;
		printf("\n清空成功\n");
	}
}
//遍历输出
Status TraverseAQueue(AQueue *Q)
{
	int i;

	if(NULL == Q )
		return FALSE;

	i = Q->front;
    while(i != Q->rear)
	{	printf("【%d】  ",Q->data[i]);
	    i = (i+1) % Q->length;
	}
	while(i != (Q->front+Q->length-1) % Q->length)
	{	printf("【空】 ");
	    i = (i+1) % Q->length;
	}
	return TRUE;
}
void traversel(AQueue *Q)
{
	if( FALSE == TraverseAQueue(Q))
		printf("\n未初始化\n");
	else printf("\n遍历输出完毕\n");
}
//功能表
void menu()
{
	
	printf("                 *请选择以下功能*\n\n");
	printf("     |——————输入  &&   功能———————|\n");
	printf("     |-————————————————————|\n");
	printf("     |-------------a    TO   初始化队列--------|\n");
	printf("     |-------------b    TO   销毁队列----------|\n");
	printf("     |-------------c    TO   判断队列是否已满--|\n");
	printf("     |-------------d    TO   判断队列是否为空--|\n");
	printf("     |-------------e    TO   得到队头元素------|\n");
	printf("     |-------------f    TO   检测队列长度------|\n");
	printf("     |-------------g    TO   入队--------------|\n");
	printf("     |-------------h    TO   出队--------------|\n");
	printf("     |-------------i    TO   清空队列----------|\n");
	printf("     |-------------j    TO   遍历输出----------|\n");
	printf("     |-------------k    TO   退出--------------|\n");
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



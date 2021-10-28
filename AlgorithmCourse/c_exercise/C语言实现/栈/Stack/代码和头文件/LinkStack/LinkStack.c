#include "../head/LinkStack.h"

//链栈(基于链表的)
Status initLStack(LinkStack **s)   //初始化
{
	*s = (LinkStack *)malloc(sizeof(LinkStack));
	if(NULL == *s)
		return ERROR;
	(*s)->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(NULL == (*s)->top)
		return ERROR;

	(*s)->top->next = NULL;
	(*s)->count = 0;
	return SUCCESS;
}
void init(LinkStack **s)
{
	if(initLStack(s) == SUCCESS)
		printf("\n初始化成功\n");
	else
		printf("\n初始化失败\n");
}

Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if(NULL == s || s->top == NULL || s->top->next != NULL) //栈指针为空或者栈顶指针为空
		return ERROR;
	else 
		return SUCCESS;
}
void isempty(LinkStack *s)
{
	if(isEmptyLStack(s) == SUCCESS)
		printf("\n链栈为空\n");
	else if(NULL == s || s->top == NULL)
		printf("\n未初始化\n");
	else
		printf("\n链栈不为空\n");
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
	if(NULL == s || s->top == NULL || s->top->next == NULL)
		return ERROR;
	*e = s->top->next->data;
	return SUCCESS;
}
void gettop(LinkStack *s)
{
	ElemType e;

	if(getTopLStack(s,&e) == SUCCESS)
		printf("\n栈顶元素为%d\n",e);
	else if(NULL == s || s->top == NULL)
		printf("\n未初始化\n");
	else
		printf("\n链栈为空\n");
}

Status clearLStack(LinkStack *s)   //清空栈
{
	LinkStackPtr p1,p2;

	if(NULL == s || s->top == NULL)
		return ERROR;

	p1=s->top->next;
	while(p1 != NULL)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	s->top->next = NULL;
	return SUCCESS;
}
void clear(LinkStack *s)
{
	if(clearLStack(s) == SUCCESS)
		printf("\n清空完毕\n");
	else 
		printf("\n未初始化\n");
}

Status destroyLStack(LinkStack *s)   //销毁栈
{
	if(NULL == s || s->top == NULL)
		return ERROR;
	free(s);
	return SUCCESS;
}
void destroy(LinkStack *s)
{
	if(destroyLStack(s) == SUCCESS)
		printf("\n销毁成功\n");
	else 
		printf("\n未初始化\n");
}
Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	if(NULL == s || s->top == NULL)
		return ERROR;
	*length = s->count;
	return SUCCESS;
}
void length(LinkStack *s)
{
	int len;

	if(LStackLength(s,&len) == SUCCESS)
		printf("\n链栈长度为%d\n",len);
	else
		printf("\n未初始化\n");
}

Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
	LinkStackPtr p = NULL;

	if(NULL == s || s->top == NULL)
		return ERROR;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top->next;
	s->top->next = p;
	s->count++;
	return SUCCESS;
}
void push(LinkStack *s)
{
    ElemType d;
	int a;

	printf("\n入栈数据: ");
	fflush(stdin);
	a = scanf("%d",&d);
	if(a == 0)
	{
		printf("\n输入错误\n");
		push(s);
	}
	if(pushLStack(s,d) == SUCCESS)
		printf("\n%d入栈成功\n",d);
	else
		printf("\n未初始化\n");
}

Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
	LinkStackPtr p = NULL;

	if(NULL == s || s->top == NULL || s->count == 0)
		return ERROR;
    p = s->top->next;
	s->top->next = p->next;
	*data = p->data;
	free(p);
	s->count--;
	return SUCCESS;
}
void pop(LinkStack *s)
{
	ElemType d;

	if(popLStack(s,&d) == SUCCESS)
		printf("\n%d出栈成功\n",d);
	else if(NULL == s || s->top == NULL)
		printf("\n未初始化\n");
	else
		printf("\n栈为空\n");
}
//
void abc()
{
	printf("                 *请选择以下功能*\n\n");
	printf("     |——————输入  &&   功能———————|\n");
	printf("     |-————————————————————|\n");
	printf("     |-------------a    TO   初始化栈----------|\n");
	printf("     |-------------b    TO   判断栈是否为空----|\n");
	printf("     |-------------c    TO   得到栈顶元素------|\n");
	printf("     |-------------d    TO   清空栈------------|\n");
	printf("     |-------------e    TO   销毁栈------------|\n");
	printf("     |-------------f    TO   检测栈长度--------|\n");
	printf("     |-------------g    TO   入栈--------------|\n");
	printf("     |-------------h    TO   出栈--------------|\n");
	printf("     |-------------i    TO   输出--------------|\n");
	printf("     |-------------j    TO   退出--------------|\n");
	printf("     |-————————————————————|\n");
	printf("     |-————————————————————|\n");
}
void wsg()
{	
	printf("\n");
	system("PAUSE");
	system("cls");
	abc();
	printf("\n输入你选择的操作(以输入的第一个字符为准): ");
}
void print(LinkStack *s)
{
	LinkStackPtr p;

	if(NULL == s || s->top == NULL)
		printf("\n未初始化\n");
	else
    {
		printf("\n此时顺序栈数据为:\n");
        for(p = s->top->next; p != 0; p = p->next)
		printf("       【%d】\n",p->data);
	}
}

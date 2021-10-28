#include "../head/SqStack.h"

//顺序栈(基于数组的)
Status initStack(SqStack **s,int sizes)  //初始化栈
{

	*s=(SqStack *)malloc(sizeof(SqStack));
	(*s)->elem = (ElemType *)malloc(sizeof(ElemType)*sizes);
	if(NULL == (*s)->elem)
		return ERROR;
	(*s)->top = -1;       
	(*s)->size = sizes;     //最大空间
	return SUCCESS;
}
void init(SqStack **s)
{
	int num,k;
	Status yn;

	printf("\n所构建顺序栈的最大空间: ");
	fflush(stdin);
	k = scanf("%d",&num);

	if(k == 0)
	{	
		printf("\n输入错误\n");
		init(s);
	}
	else if(num <= 0)
	{
		printf("\n最大空间不能低于1\n");
		init(s);
	}

	if((yn = initStack(s,num)) == SUCCESS)
		printf("\n初始化成功\n");
	else 
		printf("\n初始化失败\n");
}

Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if(NULL == s || s->top == -1)
		return ERROR;
	return SUCCESS;
}
void isempty(SqStack *s)
{
	Status yn;

	if((yn = isEmptyStack(s)) == SUCCESS)
		printf("\n栈不为空\n");
	else if(NULL == s)
		printf("\n未初始化\n");	
	else
		printf("\n栈为空\n");
}

Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if(NULL == s || s->top == -1)
		return ERROR;
	*e = s->elem[s->top];
	return SUCCESS;
}
void gettop(SqStack *s)
{
	ElemType e;
	Status yn;

	if((yn = getTopStack(s,&e)) == SUCCESS)
		printf("\n得到栈顶元素%d\n",e);
	else if(NULL == s)
		printf("\n未初始化\n");	
	else
		printf("\n栈为空\n");
}

Status clearStack(SqStack *s)   //清空栈
{
	if(NULL == s)
		return ERROR;
	s->top = -1;
	return SUCCESS;
}
void clear(SqStack *s)
{
	Status yn;

	if((yn = clearStack(s)) == SUCCESS)
		printf("\n清空成功\n");
	else
		printf("\n未初始化\n");
}

Status destroyStack(SqStack *s)  //销毁栈
{
	if(NULL == s)
		return ERROR;
	else
	{
		free(s);

		return SUCCESS;
	}
}
void destroy(SqStack *s)
{
	Status yn;

	if((yn = destroyStack(s)) == SUCCESS)
		printf("\n销毁成功\n");
	else
		printf("未初始化");
}

Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	if(NULL == s)
		return ERROR;
	*length = s->top + 1;
	return SUCCESS;
}
void length(SqStack *s)
{
	Status yn;
	int len;

	if((yn = stackLength(s,&len)) == SUCCESS)
		printf("\n栈长度为%d\n",len);
	else
		printf("\n未初始化\n");
}

Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if(NULL == s || s->top == s->size-1)
		return ERROR;
	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;
}
void push(SqStack *s)
{
	ElemType data;
	Status yn;
	int a;

	printf("\n输入入栈数据: ");
	fflush(stdin);
	a = scanf("%d",&data);
	if(a == 0)
	{
		printf("\n输入错误\n");
		push(s);
	}
	
	if((yn = pushStack(s,data)) == SUCCESS)
		printf("\n%d入栈成功\n",data);
	else if(NULL == s)
		printf("\n未初始化\n");
	else
		printf("\n栈满\n");
}

Status popStack(SqStack *s,ElemType *data)   //出栈
{
	if(NULL == s || s->top == -1)
		return ERROR;
	*data = s->elem[s->top];
	s->top--;
	return SUCCESS;
}
void pop(SqStack *s)
{
	ElemType data;
	Status yn;

	if((yn = popStack(s,&data)) == SUCCESS)
		printf("\n%d出栈成功\n",data);
	else if(NULL == s)
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
void print(SqStack *s)
{
	int i;

	if(NULL == s)
		printf("\n未初始化\n");
	else if(s->top == -1)
		printf("\n栈为空\n");
	else
	{
		printf("\n此时顺序栈数据为:\n");
        for(i = s->top; i >=0; i--)
		     printf("       【%d】\n",s->elem[i]);
	}
}
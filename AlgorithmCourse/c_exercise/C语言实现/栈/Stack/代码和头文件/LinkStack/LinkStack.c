#include "../head/LinkStack.h"

//��ջ(���������)
Status initLStack(LinkStack **s)   //��ʼ��
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
		printf("\n��ʼ���ɹ�\n");
	else
		printf("\n��ʼ��ʧ��\n");
}

Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if(NULL == s || s->top == NULL || s->top->next != NULL) //ջָ��Ϊ�ջ���ջ��ָ��Ϊ��
		return ERROR;
	else 
		return SUCCESS;
}
void isempty(LinkStack *s)
{
	if(isEmptyLStack(s) == SUCCESS)
		printf("\n��ջΪ��\n");
	else if(NULL == s || s->top == NULL)
		printf("\nδ��ʼ��\n");
	else
		printf("\n��ջ��Ϊ��\n");
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
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
		printf("\nջ��Ԫ��Ϊ%d\n",e);
	else if(NULL == s || s->top == NULL)
		printf("\nδ��ʼ��\n");
	else
		printf("\n��ջΪ��\n");
}

Status clearLStack(LinkStack *s)   //���ջ
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
		printf("\n������\n");
	else 
		printf("\nδ��ʼ��\n");
}

Status destroyLStack(LinkStack *s)   //����ջ
{
	if(NULL == s || s->top == NULL)
		return ERROR;
	free(s);
	return SUCCESS;
}
void destroy(LinkStack *s)
{
	if(destroyLStack(s) == SUCCESS)
		printf("\n���ٳɹ�\n");
	else 
		printf("\nδ��ʼ��\n");
}
Status LStackLength(LinkStack *s,int *length)    //���ջ����
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
		printf("\n��ջ����Ϊ%d\n",len);
	else
		printf("\nδ��ʼ��\n");
}

Status pushLStack(LinkStack *s,ElemType data)   //��ջ
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

	printf("\n��ջ����: ");
	fflush(stdin);
	a = scanf("%d",&d);
	if(a == 0)
	{
		printf("\n�������\n");
		push(s);
	}
	if(pushLStack(s,d) == SUCCESS)
		printf("\n%d��ջ�ɹ�\n",d);
	else
		printf("\nδ��ʼ��\n");
}

Status popLStack(LinkStack *s,ElemType *data)   //��ջ
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
		printf("\n%d��ջ�ɹ�\n",d);
	else if(NULL == s || s->top == NULL)
		printf("\nδ��ʼ��\n");
	else
		printf("\nջΪ��\n");
}
//
void abc()
{
	printf("                 *��ѡ�����¹���*\n\n");
	printf("     |����������������  &&   ���ܡ�������������|\n");
	printf("     |-����������������������������������������|\n");
	printf("     |-------------a    TO   ��ʼ��ջ----------|\n");
	printf("     |-------------b    TO   �ж�ջ�Ƿ�Ϊ��----|\n");
	printf("     |-------------c    TO   �õ�ջ��Ԫ��------|\n");
	printf("     |-------------d    TO   ���ջ------------|\n");
	printf("     |-------------e    TO   ����ջ------------|\n");
	printf("     |-------------f    TO   ���ջ����--------|\n");
	printf("     |-------------g    TO   ��ջ--------------|\n");
	printf("     |-------------h    TO   ��ջ--------------|\n");
	printf("     |-------------i    TO   ���--------------|\n");
	printf("     |-------------j    TO   �˳�--------------|\n");
	printf("     |-����������������������������������������|\n");
	printf("     |-����������������������������������������|\n");
}
void wsg()
{	
	printf("\n");
	system("PAUSE");
	system("cls");
	abc();
	printf("\n������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼): ");
}
void print(LinkStack *s)
{
	LinkStackPtr p;

	if(NULL == s || s->top == NULL)
		printf("\nδ��ʼ��\n");
	else
    {
		printf("\n��ʱ˳��ջ����Ϊ:\n");
        for(p = s->top->next; p != 0; p = p->next)
		printf("       ��%d��\n",p->data);
	}
}

#include "../head/SqStack.h"

//˳��ջ(���������)
Status initStack(SqStack **s,int sizes)  //��ʼ��ջ
{

	*s=(SqStack *)malloc(sizeof(SqStack));
	(*s)->elem = (ElemType *)malloc(sizeof(ElemType)*sizes);
	if(NULL == (*s)->elem)
		return ERROR;
	(*s)->top = -1;       
	(*s)->size = sizes;     //���ռ�
	return SUCCESS;
}
void init(SqStack **s)
{
	int num,k;
	Status yn;

	printf("\n������˳��ջ�����ռ�: ");
	fflush(stdin);
	k = scanf("%d",&num);

	if(k == 0)
	{	
		printf("\n�������\n");
		init(s);
	}
	else if(num <= 0)
	{
		printf("\n���ռ䲻�ܵ���1\n");
		init(s);
	}

	if((yn = initStack(s,num)) == SUCCESS)
		printf("\n��ʼ���ɹ�\n");
	else 
		printf("\n��ʼ��ʧ��\n");
}

Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if(NULL == s || s->top == -1)
		return ERROR;
	return SUCCESS;
}
void isempty(SqStack *s)
{
	Status yn;

	if((yn = isEmptyStack(s)) == SUCCESS)
		printf("\nջ��Ϊ��\n");
	else if(NULL == s)
		printf("\nδ��ʼ��\n");	
	else
		printf("\nջΪ��\n");
}

Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
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
		printf("\n�õ�ջ��Ԫ��%d\n",e);
	else if(NULL == s)
		printf("\nδ��ʼ��\n");	
	else
		printf("\nջΪ��\n");
}

Status clearStack(SqStack *s)   //���ջ
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
		printf("\n��ճɹ�\n");
	else
		printf("\nδ��ʼ��\n");
}

Status destroyStack(SqStack *s)  //����ջ
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
		printf("\n���ٳɹ�\n");
	else
		printf("δ��ʼ��");
}

Status stackLength(SqStack *s,int *length)   //���ջ����
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
		printf("\nջ����Ϊ%d\n",len);
	else
		printf("\nδ��ʼ��\n");
}

Status pushStack(SqStack *s,ElemType data)  //��ջ
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

	printf("\n������ջ����: ");
	fflush(stdin);
	a = scanf("%d",&data);
	if(a == 0)
	{
		printf("\n�������\n");
		push(s);
	}
	
	if((yn = pushStack(s,data)) == SUCCESS)
		printf("\n%d��ջ�ɹ�\n",data);
	else if(NULL == s)
		printf("\nδ��ʼ��\n");
	else
		printf("\nջ��\n");
}

Status popStack(SqStack *s,ElemType *data)   //��ջ
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
		printf("\n%d��ջ�ɹ�\n",data);
	else if(NULL == s)
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
void print(SqStack *s)
{
	int i;

	if(NULL == s)
		printf("\nδ��ʼ��\n");
	else if(s->top == -1)
		printf("\nջΪ��\n");
	else
	{
		printf("\n��ʱ˳��ջ����Ϊ:\n");
        for(i = s->top; i >=0; i--)
		     printf("       ��%d��\n",s->elem[i]);
	}
}
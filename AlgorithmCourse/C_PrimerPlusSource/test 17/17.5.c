/*5.��дһ��������ʾ�û�����һ���ַ�����Ȼ��ó���Ѹ��ַ�����
�ַ����ѹ��һ��ջ���μ���ϰ��5����Ȼ���ջ�е�����Щ�ַ�������ʾ
���ǡ������ʾΪ���ַ���������*/

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40

/*ͷ�ļ���ʼ*/
#define SMAX 100
typedef char Item;

typedef struct stack{
    Item item[SMAX];
    int items;
}Stack;

//��ʼ��ջ
void InitializeStack(Stack * ps);

//ȷ��ջΪ��
int StackIsEmpty(const Stack * ps);

//ȷ��ջΪ��
int StackIsFull(const Stack * ps);

//ͳ��ջ������
int StackItemCount(const Stack * ps);

//��ջ��ѹ����
int AddItem(Stack * ps, Item item);

//��ջ��������
int DelItem(Stack * ps, Item * pitem);

//�����
void EmptyItem(Stack * ps);

/*ͷ�ļ�����*/


/*��������ʼ*/
char * s_gets(char * st, int n);

int main()
{
    Stack stack;
    Item temp[SIZE];
    Item ch;
    int i;

    InitializeStack(&stack);
    //�û�����ѹ��ջ��
    printf("�����ַ���:\n");
    while(s_gets(temp,SIZE)!=NULL && temp[0]!='\0')
    {
        for(i=0;temp[i] != '\0';i++)
        {
            if (AddItem(&stack,temp[i]) == 0)
                break;
        }
        if(StackIsFull(&stack))
        {
            fprintf(stderr,"ջ����.\n");
            break;
        }
        printf("������һ���ַ���(���н���):\n");
    }
    //��ջ�е������ݲ����
    if(StackIsEmpty(&stack))
    {
        fprintf(stderr, "û������.\n");
        exit(1);
    }

    printf("�������� %d ���ַ�.\n",StackItemCount(&stack));
    printf("�����ַ�����������:\n");
    while(!StackIsEmpty(&stack))
    {
        DelItem(&stack,&ch);
        putchar(ch);
    }
    printf("\nBye.\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');  // ���һ��з�
        if (find)           // �����ַ����NULL��
            *find = '\0';     // �ڴ˴�����һ�����ַ�
        else
            while (getchar() != '\n')
                continue;      // ���������е�ʣ������
    }
    return ret_val;
}
/*����������*/


/*�������忪ʼ*/
//��ʼ��ջ
void InitializeStack(Stack * ps)
{
    ps->items=0;
}

//ȷ��ջΪ��
int StackIsEmpty(const Stack * ps)
{
    if(ps->items==0)
        return 1;
    else
        return 0;
}

//ȷ��ջΪ��
int StackIsFull(const Stack * ps)
{
    return (ps->items==SMAX) ? 1:0;
}

//ͳ��ջ������
int StackItemCount(const Stack * ps)
{
    return ps->items;
}

//��ջ��ѹ����
int AddItem(Stack * ps, Item item)
{
    if(StackIsFull(ps))
        return 0;
    else
    {
        ps->item[ps->items]=item;
        ps->items++;
        return 1;
    }
}

//��ջ��������
int DelItem(Stack * ps, Item * pitem)
{
    if (StackIsEmpty(ps))
        return 0;
    else
    {
        *pitem=ps->item[ps->items-1];
        EmptyItem(ps);
        ps->items--;
        return 1;
    }
}

//�����
void EmptyItem(Stack * ps)
{
    ps->item[ps->items-1]='\0';
}

/*�����������*/

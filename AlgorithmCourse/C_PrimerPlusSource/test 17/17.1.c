/* 1.�޸ĳ����嵥17.2���øó����������Ҳ��������ʾ��Ӱ�б�һ��
�������޸�����Ķ��壬����˫�����������һ�ַ������õݹ顣*/
#include <stdio.h>
#include <stdlib.h>    /* �ṩmalloc()ԭ�� */
#include <string.h>    /* �ṩstrcpy()ԭ�� */
#define TSIZE 45    /* ����Ƭ���������С */

typedef struct film {
    char title[TSIZE];
    int rating;
    struct film * next;  /* ָ�������е���һ���ṹ */
    struct film *prev; //ָ����һ���ṹ
}Node;

char * s_gets(char * st, int n);

int main(void)
{
    Node * head = NULL;//ͷָ��
    Node *pre =NULL;//��һ���ڵ�
    Node *end;//β�ڵ�
    Node *current;//��ǰ�ڵ�
    char input[TSIZE];

    /* �ռ���������Ϣ */
    puts("�����һ����Ӱ��:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)   /* ��1���ṹ */
            head = current;
        else         /* �����Ľṹ */
            pre->next = current;//�ϸ��ڵ��nextָ��ָ��ǰ�ڵ�
        current->prev=pre;//��ǰ�ڵ��prevָ��ָ����һ���ڵ�
        current->next = NULL;//��ǰ�ڵ�ָ���ָ�룬��ʾ��β
        strcpy(current->title, input);
        puts("��������(0-10):");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("��һ����Ӱ�� (������н���):");
        pre = current;//��ǰ�ڵ��Ϊ��һ���ڵ㣬ѭ����ȥ
    }
    end=pre;//endָ�����һ���ڵ�

    if (head == NULL)
        printf("û������. ");
    else
        printf("��Ӱ�б�����:\n");
    // ������ʾ��Ӱ�б�
    current = head;
    while (current != NULL)
    {
        printf("��Ӱ: %s ����: %d\n",
                current->title, current->rating);
        current = current->next;
    }
    //������ʾ��Ӱ�б�
    puts("\n������������ʾ��Ӱ�б�");
    current=end;//��ĩβ��ʼ
    while(current !=NULL)
    {
        printf("��Ӱ: %s  ����: %d\n",
                current->title,current->rating);
        current=current->prev;
    }

    /* ��������ͷ��ѷ�����ڴ� */
    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
    }
    printf("�ټ�!\n");

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
        if (find)        // �����ַ���� NULL��
            *find = '\0';     // �ڴ˴�����һ�����ַ�
        else
            while (getchar() != '\n')
                continue;   // ����ʣ��������
    }
    return ret_val;
}

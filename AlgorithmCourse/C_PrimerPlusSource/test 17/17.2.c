/*2.����list.h�������嵥17.3��ʹ�������list���壺
typedef struct list
{
    Node * head;    // ָ��list�Ŀ�ͷ
    Node * end;     //ָ��list��ĩβ
} List;
��д list.c�������嵥 17.5���еĺ�������Ӧ�µĶ��壬��ͨ��
films.c�������嵥 17.4���������յĴ��롣*/
#include <stdio.h>
#include <stdlib.h> /* �ṩexit()��ԭ�� */
#include "17.2.h"  /* ����List��Item */
#include "17.2list.c"

void showmovies(Item item);
char * s_gets(char * st, int n);

int main(void)
{
    List movies;
    Item temp;
    /* ��ʼ��   */
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "û�д洢�ռ䡣\n");
        exit(1);
    }
    /* ��ȡ�û����벢���� */
    puts("�����һ����Ӱ��:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("�������� <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n') continue;
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "����ռ�ʧ�ܡ�\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("װ����.");
            break;
        }
        puts("������һ����Ӱ�� (���н���):");
    }
    /* ��ʾ����*/
    if (ListIsEmpty(&movies))
        printf("û����������. ");
    else
    {
        printf("��Ӱ�嵥����:\n");
        Traverse(&movies, showmovies);
    }
    printf("�������� %d ����Ӱ.\n", ListItemCount(&movies));
    /* ����   */
    EmptyTheList(&movies);
    printf("Bye!\n");

    return 0;
}
void showmovies(Item item)
{
    printf("��Ӱ: %s ����: %d\n", item.title,item.rating);
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

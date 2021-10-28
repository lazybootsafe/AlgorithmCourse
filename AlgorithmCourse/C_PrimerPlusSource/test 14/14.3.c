/*3.�޸ĳ����嵥 14.2 �е�ͼ��Ŀ¼����ʹ�䰴������ͼ���˳�����
ͼ�����Ϣ��Ȼ���ձ�����ĸ���������ͼ�����Ϣ������ռ۸����
�����ͼ�����Ϣ*/
#include <stdio.h>
#include <string.h>//�ṩstrcmp()
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100     // ����鼮����
struct book {       // ���� book ģ��
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
char * s_gets(char * st, int n);
void sort_by_input(const struct book library[] ,int n);
void sort_by_title(struct book library[] ,int n);
void sort_by_price(struct book library[] ,int n);

int main(void)
{
    static struct book library[MAXBKS]; // �ṹ����
    int count = 0;
    int index;

    puts("�������µ��鱾����(����[enter] ��������).");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        puts("������������.");
        s_gets(library[count].author, MAXAUTL);
        puts("��������۸�.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;    // ����������
        if (count < MAXBKS)
            puts("������һ������.");
    }
    if (count > 0)
    {
        puts("������˳������,�鱾�嵥����:");
        sort_by_input(library,count);

        puts("������˳������,�鱾�嵥����:");
        sort_by_title(library,count);

        puts("���۸��С����,�鱾�嵥����:");
        sort_by_price(library,count);
    }
    else
        puts("û���µ��鱾���ðɣ�.\n");
    puts("�ټ�.\n");

    return 0;
}

char * s_gets(char * st, int n)
{

    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // ���һ��з�
        if (find)       // �����ַ���� NULL��
            *find = '\0';    // �ڴ˴�����һ�����ַ�
        else
            while (getchar() != '\n') continue;   // ����������
    }

    return ret_val;
}

void sort_by_input(const struct book library[] ,int n)
{
    for (int index = 0; index < n; index++)
        printf("%s by %s: $%.2f\n", library[index].title,
               library[index].author, library[index].value);
   printf("\n");
}

void sort_by_title(struct book library[] ,int n)
{
    struct book temp;
    int i, j;

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(strcmp(library[i].title,library[j].title) > 0)
            {//ð������
                temp=library[j];
                library[j]=library[i];
                library[i]=temp;
            }
    for (int index = 0; index < n; index++)
        printf("%s by %s: $%.2f\n", library[index].title,
               library[index].author, library[index].value);
   printf("\n");
}

void sort_by_price(struct book library[] ,int n)
{
    struct book temp;
    int i, j;

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(library[i].value>library[j].value)
            {//ð������
                temp=library[j];
                library[j]=library[i];
                library[i]=temp;
            }
    for (int index = 0; index < n; index++)
        printf("%s by %s: $%.2f\n", library[index].title,
               library[index].author, library[index].value);
   printf("\n");
}


/*4.��дһ�����򣬴���һ����������Ա�Ľṹģ�壺
a.��1����Ա����ᱣ�պţ���2����Ա��һ����3����Ա�Ľṹ����1��
��Ա����������2����Ա�����м�������3����Ա��ʾ�ա���������ʼ��һ��
�ں�5�������ͽṹ�����顣�ó���������ĸ�ʽ��ӡ���ݣ�
Dribble, Flossie M.�C�C 302039823
������м�����ֻ��ӡ���ĵ�1����ĸ�������һ���㣨.�������û��
�м��������ô�ӡ�㡣��дһ��������д�ӡ���ѽṹ���鴫�ݸ������
����
b.�޸�a���֣����ݽṹ��ֵ�����ǽṹ�ĵ�ַ��*/
#include <stdio.h>
#define SSN 20
#define LEN 10

struct names {
    char first_name[LEN];
    char mid_name[LEN];
    char last_name[LEN];
};

struct person {
    char num[SSN];
    struct names name;
};
void printa(struct person p[],int n);
void printb(struct person p);
int main (void)
{
    struct person people[5]={
        {"302039823",{"Dribble","Mindder","Flossie"}},
        {"123519823",{"asdw","uibdder","fhh"}},
        {"745689823",{"ksdv","","qwi"}},
        {"321356823",{"rsdv","mer","dgre"}},
        {"786354823",{"hbgv","","kco"}}
    };
    printa(people,5);

    for(int i=0;i<5;i++)
        printb(people[i]);

    printf("\n");
    return 0;
}
void printa(struct person p[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%s,%s %c%c -- %s\n",p[i].name.first_name,
               p[i].name.last_name,
               p[i].name.mid_name[0],
               (p[i].name.mid_name[0]=='\0')? '\0':'.',
               p[i].num);
    }
    printf("\n");
}

void printb(struct person p)
{
    printf("%s,%s %c%c -- %s\n",p.name.first_name,
               p.name.last_name,
               p.name.mid_name[0],
               (p.name.mid_name[0]=='\0')? '\0':'.',
               p.num);
}

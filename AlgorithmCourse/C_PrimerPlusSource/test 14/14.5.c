/*5.��дһ���������������Ҫ��

a.�ⲿ����һ����������Ա�Ľṹģ��name��һ���ַ�����������һ��
�ַ��������ա�
b.�ⲿ����һ����3����Ա�Ľṹģ��student��һ��name���͵Ľṹ��
һ��grade���鴢��3�������ͷ�����һ����������3������ƽ������
c.��main()����������һ���ں�CSIZE��CSIZE = 4����student���ͽṹ��
���飬����ʼ����Щ�ṹ�����ֲ��֡��ú���ִ��d��e��f��g����������
��
d.�Խ����ķ�ʽ��ȡÿ��ѧ���ĳɼ�����ʾ�û�����ѧ���������ͷ�
�����ѷ������浽grade������Ӧ�Ľṹ�С�������main()����������������
��ѭ������ɡ�
e.����ÿ���ṹ��ƽ���֣����Ѽ�����ֵ�������ʵĳ�Ա��
f.��ӡÿ���ṹ����Ϣ��
g.��ӡ�༶��ƽ���֣������нṹ����ֵ��Ա��ƽ��ֵ��*/

#include <stdio.h>
#include <math.h>
#define LEN 10
#define CSIZE 4
#define NUM 3

struct name{
    char first_name[LEN];
    char second_name[LEN];
};
struct student{
    struct name names;
    float grade[NUM];
    float average;
};
void d_get_score(struct student stus[],int n);
void e_average(struct student stus[],int n);
void f_print(struct student stus[],int n);
void g_all_aver(struct student stus[],int n);

int main(void)
{
    struct student stus[CSIZE]={
                        {.names={"��","С��"}},
                        {.names={"��","����"}},
                        {{"��","����"},{0,0,0},0},
                        {{"��","��߷"},{0,0,0},0}
                            };
    d_get_score(stus,CSIZE);
    e_average(stus,CSIZE);
    f_print(stus,CSIZE);
    g_all_aver(stus,CSIZE);

    return 0;
}

void d_get_score(struct student stus[],int n)
{
    int i,j;

    for(i=0,j=0;i<n;i++)
    {
        for(j=0;j<NUM;j++)
        {
            printf("����%s%s�ĵ�%d���ɼ���\n",stus[i].names.first_name,
                   stus[i].names.second_name,j+1);
            while(scanf("%f",&stus[i].grade[j]) !=1)
                while(getchar() !='\n') continue;//����������
            while(getchar() !='\n') continue;//����������
        }
    }
    puts("");
}

void e_average(struct student stus[],int n)
{
    float tol;
    int i,j;

    for(i=0;i<n;i++)
    {
        tol=0;
        for(j=0;j<NUM;j++)
        {
            tol+=stus[i].grade[j];
        }
        stus[i].average=tol/j;
    }
}

void f_print(struct student stus[],int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        printf("%s%s��%d�ųɼ��ֱ���",stus[i].names.first_name,
               stus[i].names.second_name,NUM);
        for(j=0;j<NUM;j++)
        {
            printf(" %g",stus[i].grade[j]);
        }
        printf(",ƽ������%.2f.\n",stus[i].average);
    }
}

void g_all_aver(struct student stus[],int n)
{
    float tol=0;
    float aver;
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<NUM;j++)
        {
            tol+=stus[i].grade[j];
        }
    }
    aver=tol/(i*j);
    printf("�༶ƽ������%.2f.\n",aver);
}


/*6.һ���ı��ļ��б�����һ������ӵ���Ϣ��ÿ�����ݶ����������У�
4 Jessie Joybat 5 2 1 1
��1������Ա�ţ�Ϊ����������䷶Χ��0��18����2������Ա��������3
������Ա���ա������ն���һ�����ʡ���4���ǹٷ�ͳ�Ƶ���Ա�ϳ�������
����3��ֱ��ǻ��������������ʹ�㣨RBI�����ļ����ܰ����ೡ������
���ݣ�����ͬһλ��Ա�����ж������ݣ�����ͬһλ��Ա�Ķ�������֮���
����������Ա�����ݡ���дһ�����򣬰����ݴ��浽һ���ṹ�����С��ý�
���еĳ�ԱҪ�ֱ��ʾ��Ա�������ա��ϳ���������������������������
�����ʣ��Ժ���㣩������ʹ����Ա����Ϊ������������ó���Ҫ�����ļ�
��β����ͳ��ÿλ��Ա�ĸ����ۼ��ܺ͡�
�������ͳ����֮��ء����磬һ�����ݺʹ����е�ʧ�󲻼����ϳ���
�������ǿ��ܲ���һ��RBI�����Ǹó���Ҫ������������������һ����ȡ��
���������ļ�������������ݵ�ʵ�ʺ��塣
Ҫʵ����Щ���ܣ���򵥵ķ����ǰѽṹ�����ݶ���ʼ��Ϊ�㣬���ļ�
�е����ݶ�����ʱ�����У�Ȼ���������Ӧ�Ľṹ�С���������ļ���
Ӧ����ÿλ��Ա�İ����ʣ����Ѽ��������浽�ṹ����Ӧ��Ա�С����㰲
����������Ա���ۼƻ����������ϳ��ۼƴ���������һ�����������㡣��
�󣬳�����������ӵ�ͳ�����ݣ�һ����ʾһλ��Ա���ۼ����ݡ�*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20      //�ַ�����
#define SIZE 20     //��Ա����

struct player{
    int num; //��Ա��
    char first_name[LEN];
    char last_name[LEN];
    int action;//�ϳ�����
    int hit;//������
    int walk;//������
    int rbi;//���
    float average;//������
};
void a_get_zero(struct player *man,int n);//���ݱ�0
void b_get_data(struct player *man,int n);//��ȡ����
void c_print(struct player *man,int n);//��ӡ

int main(void)
{
    static struct player players[SIZE];
    a_get_zero(players,SIZE);
    b_get_data(players,SIZE);
    c_print(players,SIZE);
    printf("�ټ�.");

    return 0;
}

void a_get_zero(struct player *man,int n)
{
    for(int i=0;i<n;i++)//����
        man[i]=(struct player){0,"","",0,0,0,0,0};
}

void b_get_data(struct player *man,int n)
{
    FILE *p;
    char name[LEN];
    int nu,ac,hi,wa,rb;
    char f_name[LEN],l_name[LEN];


    puts("������Ҫ�򿪵��ļ�����");
    gets(name);
    if(( p = fopen(name,"rb")) == NULL)
    {
        fprintf(stderr,"���ܴ�%s�ļ�",name);
        exit(EXIT_FAILURE);
    }
    while( (fscanf(p,"%d%s%s%d%d%d%d",&nu,f_name,
                   l_name,&ac,&hi,&wa,&rb)) == 7)
    {//��ȡ�ļ����ݵ��Ӵ洢������
        man[nu].num = nu;
        if(man[nu].first_name[0] =='\0')
        {
            strcpy(man[nu].first_name,f_name);
            strcpy(man[nu].last_name,l_name);
        }
        man[nu].action += ac;
        man[nu].hit += hi;
        man[nu].walk += wa;
        man[nu].rbi += rb;
    }
	if (fclose(p) != 0)
		fprintf(stderr,"�ر��ļ�ʱ��������.\n");
}

void c_print(struct player *man,int n)
{
    int i=0;
    int ac=0,hi=0,wa=0,rb=0;

    for(i=0;i<n;i++)
    {//���㰲����
        man[i].average=man[i].hit /(float)man[i].action;
    }
    printf("\n");
    printf("��Ա��\t��\t��\t����\t������\t������"
            "\t���\t������\n");
    for(i=0;i<n;i++)
    {
        if(man[i].first_name[0] !='\0')
            {
            printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%.3g\n",
                   man[i].num,man[i].first_name,man[i].last_name,
                   man[i].action,man[i].hit,man[i].walk,man[i].rbi,
                   man[i].average);
            }
           ac +=man[i].action;
           hi +=man[i].hit;
           wa +=man[i].walk;
           rb +=man[i].rbi;
    }
    printf("\n");
    printf("�ܼ�: ���� %d\t������ %d\t������ %d\t��� %d\tƽ�������� %.3g\n",
            ac,hi,wa,rb,hi/(float)ac);
}


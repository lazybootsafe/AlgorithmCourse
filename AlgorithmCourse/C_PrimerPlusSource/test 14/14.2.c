/*2.��дһ����������ʾ�û������ա��º��ꡣ�·ݿ������·ݺš��·�
�����·�����д��Ȼ��ó���Ӧ����һ���е��û�ָ�����ӣ�������һ�죩
��������*/
#include <stdio.h>
#include <string.h>//�ṩstrcmp()����
#include <ctype.h>//�ṩtolower()����
#include <stdlib.h>//�ṩexit
int get_days(int n);//��
int get_months(void);//��
int get_years(void);//��
int answer(void);//��
char * s_gets(char * st, int n);

struct month{
    char name[20];
    char abbr[4];
    int days;
    char monumb[3];
};
struct month months[12]={
                        { "january", "jan", 31, "1" },
                        { "february", "feb", 28, "2" },
                        { "march", "mar", 31, "3" },
                        { "april", "apr", 30, "4" },
                        { "may", "may", 31, "5" },
                        { "june", "jun", 30, "6" },
                        { "july", "jul", 31, "7" },
                        { "august", "aug", 31, "8" },
                        { "september", "sep", 30, "9" },
                        { "october", "oct", 31, "10" },
                        { "november", "nov", 30, "11" },
                        { "december", "dec", 31, "12" }
                        };

int main(void)
{
    answer();
    puts("�ټ�.");

    return 0;
}

int get_days(int n)
{
    int d;

    puts("��������:");
    while( scanf("%d",&d) != 1 || (d<1 ||d>months[n-1].days))
    {
        while( getchar() !='\n')
            continue;//����������
        printf("��������ȷ����(1��%d).",months[n-1].days);
    }
    while( getchar() !='\n') continue;//����������

    return d;//������
}

int get_months(void)//��
{
    char m[20];//�·�
    int i=0,n=0;

    puts("�������·�(�������·ݺ�(1-12)���·������·�����д):");
    s_gets(m,20);

    while(m[i])
    {
        if(isalpha(m[i]))
            m[i] = tolower(m[i]);  // ת��ΪСд
        i++;
    }
    for(i=0;i<12;i++)
    {//ƥ���·�
        if( strcmp( m, months[i].name) == 0 ||
            strcmp( m, months[i].abbr) == 0 ||
            strcmp( m, months[i].monumb) == 0)
            {
                n=i+1;
                break;
            }
    }
	if (n>12||n<1)
	{
		printf("������·�.\n");
		exit(1);
	}

    return n;//�����·�
}

int get_years(void)//��
{
    int y;//��

    puts("���������:");
    while( scanf("%d",&y) != 1 )
    {
        while( getchar() !='\n')
            continue;//����������
        puts("��������ȷ�����:");
    }
    while( getchar() !='\n') continue;//����������
    if( (y%4 == 0 && y%100 != 0 )||(y%400 == 0 && y%3200 != 0)) //�ж���ƽ�껹������
        months[1].days=29;//���꣬2���޸�Ϊ29��
    else
        months[1].days=28;//ƽ�꣬2���޸�Ϊ28��

    return y;//������
}

int answer(void)//��
{
    int day=0;
    int month;
    int year;
    int i,tol=0;

    year=get_years();
    month=get_months();
    day=get_days(month);

    for(i=0,tol=0;i<month-1;i++)//ͳ���·��պϼ�
        tol+=months[i].days;
    tol+=day;//���ϵ��µ�����
    printf("ֱ��%d-%d-%d ����%d��.\n",year,month,day,tol);

    return tol;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // ���һ��з�
        if (find)         // �����ַ����NULL��
            *find = '\0';    // �ڴ˴�����һ�����ַ�
    else
        while (getchar() != '\n')
            continue;     // ������������ʣ����ַ�
    }
    return ret_val;
}


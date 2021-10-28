/*1.���±�д��ϰ�� 5�����·�����ƴд�����·ݺţ�������ʹ��
strcmp()������һ���򵥵ĳ����в��Ըú���*/
#include <stdio.h>
#include <string.h>//�ṩstrcmp()����
#include <ctype.h>
int days(char *st);
char * s_gets(char * st, int n);

struct month{
    char name[20];
    char abbr[4];
    int days;
    int monumb;
};
struct month months[12]={
                        { "january", "jan", 31, 1 },
                        { "february", "feb", 28, 2 },
                        { "march", "mar", 31, 3 },
                        { "april", "apr", 30, 4 },
                        { "may", "may", 31, 5 },
                        { "june", "jun", 30, 6 },
                        { "july", "jul", 31, 7 },
                        { "august", "aug", 31, 8 },
                        { "september", "sep", 30, 9 },
                        { "october", "oct", 31, 10 },
                        { "november", "nov", 30, 11 },
                        { "december", "dec", 31, 12 }
                        };

int main(void)
{
    char temp[21];
    int i,n;

    puts("�������·���:");
    while( s_gets(temp,20) !=NULL && temp[0] != '\0')
    {
        if(  days(temp) ==0 )
            puts("������·�.");
        else
            printf("һ�굽%s�¹���%d��.\n",temp,days(temp));
        puts("������һ���·���(�س��뿪):");
    }
    puts("�ټ�.");

    return 0;
}

int days(char *st)
{
    int i=0,tol=0,n=0;

    while(st[i])
    {
        if(isalpha(st[i]))
            st[i] = tolower(st[i]);  // ת��ΪСд
        i++;
    }

    for(i=0;i<12;i++)
    {
        if( strcmp( st, months[i].name) == 0 )
        {
            n=i+1;
            break;
        }
    }

    for(i=0,tol=0;i<n;i++)
        tol+=months[i].days;
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


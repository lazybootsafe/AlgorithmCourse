#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81//�ַ�������
#define SIZE 4//�˵�����

char * s_gets(char * st, int n);
char get_choice(void);
void ToUpper(char * st);//��д
void ToLower(char * st);//Сд
void Transpos(char * st);//��ת
void Dummy(char * st);//ԭ��

int main(void)
{
    char st[LEN];//�洢ԭ�ַ���
    char copy[LEN];
    char ch;//ѡ����ĸ
    //����ָ������
    void(*fp[SIZE])(char *) = {ToUpper, ToLower, Transpos, Dummy};
    int index;

    puts("����һ������(ʲô����������뿪����):");
    while (s_gets(st, LEN) != NULL && st[0] != '\0')
    {
        while ((ch = get_choice()) != 'q')
        {
            switch (ch)
            {
            case 'a': index = 0;
                    break;
            case 'b': index = 1;
                    break;
            case 'c': index = 2;
                    break;
            case 'd': index = 3;
                    break;
            default : printf("�������.\n");
                    break;
            }
            strcpy(copy, st);
            (*(fp[index]))(copy);
            puts(copy);
        }
        printf("\n����һ������(ʲô����������뿪����):\n");
    }
    puts("�ټ�.");

    return 0;
}

char get_choice(void)
{
    char ch;

    printf("\n������ĸ����ѡ��ִ�еĺ���:\n");
    printf("a). ��д\tb). Сд\n");
    printf("c). ��ת\td). ԭ��\n");
    printf("q). �뿪.\n");
    while ((ch = (tolower(getchar()))) < 'a' || ch > 'd' && ch != 'q')
    {
        while (getchar() != '\n') continue;
        printf("��������ȷ����ĸ(a, b, c, d h���� q).\n");
    }
    while (getchar() != '\n') continue;

    return ch;
}

void ToUpper(char * st)
{
    while (*st)
    {
        *st = toupper(*st);
        st++;
    }
}

void ToLower(char * st)
{
    while (*st)
    {
        *st = tolower(*st);
        st++;
    }
}

void Transpos(char * st)
{
    while (*st)
    {
        if (islower(*st))
            *st = toupper(*st);
        else if (isupper(*st))
            *st = tolower(*st);
        st++;
    }
}

void Dummy(char * st)
{

}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

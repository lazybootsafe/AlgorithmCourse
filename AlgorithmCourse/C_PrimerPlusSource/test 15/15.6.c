/*6.���һ��λ�ֶνṹ�Դ����������Ϣ��
����ID��0��255֮���һ������
�����С��0��127֮���һ������
���룺0��2֮���һ��������ʾ����롢���С��Ҷ��룻
�Ӵ֣�����1����գ�0����
б�壺����1����գ�0����
��һ��������ʹ�øýṹ����ӡ�����������ʹ��ѭ���˵������û���
����������磬�ó����һ������ʾ�����£�
ID SIZE ALIGNMENT  B   I   U
1  12   left      off off off

f)change fonts	s)change size 	 a)change alignment
b)toggle bold 	i)toggle italic  u)toggle underline
q)quit
s
Enter font size (0-127): 36
ID SIZE ALIGNMENT  B   I   U
1  36   left      off off off
�ó���Ҫʹ�ð�λ���������&���ͺ��ʵ�������������ID�������С
��Ϣת����ָ���ķ�Χ�ڡ�*/

#include <stdio.h>
#include <string.h>

struct word {
    unsigned int font: 8;
    unsigned int size: 7;
    unsigned int alignment: 2;
    unsigned int bold: 1;
    unsigned int italic: 1;
};

const char *align[3]={"��","��","��"};
const char *open[2]={"��","��"};

char get_choice(void);
char get_select(void);
void print(struct word *);

int main(void)
{
    struct word type={1,12,0,0,0};
    char choice;
    char ch;
    int num;

    print(&type);
    while ((choice=get_choice())!='q')
    {
        switch (choice)
        {
        case 'f': printf("�ı����� (0 - 255): ");
                  scanf("%u",&num);
                  getchar();
                  type.font=num;
                  break;
        case 's': printf("�ı��С (0 - 127): ");
                  scanf("%u",&num);
                  getchar();
                  type.size=num;
                  break;
        case 'a': printf("ѡ����뷽ʽ:\n");
                  printf("l)��   c)��   r)��\n");
                  if ((ch=get_select())=='l')
                      type.alignment=0;
                  else if (ch=='c')
                      type.alignment=1;
                  else
                      type.alignment=2;
                  break;
        case 'b': type.bold=!type.bold;
                  break;
        case 'i': type.italic=!type.italic;
                  break;
        default : break;
        }
        print(&type);
    }
    printf("�ټ�.\n");

    return 0;
}

char get_choice(void)
{
    char ch;

    printf("f)�ı�����\ts)�ı��С\ta)�ı���뷽ʽ\n");
    printf("b)�л�����\ti)�л�б��\nq)�뿪\n");

    while(strchr("fsabiq",ch=getchar())==NULL)
    {
        while (getchar()!='\n') continue;
        printf("��������ȷ����ĸ.\n");
    }
    while(getchar()!='\n') continue;

    return ch;
}

char get_select(void)
{
    char ch;

    while(strchr("lcr", ch=getchar())==NULL)
    {
        while (getchar()!='\n') continue;
        printf("��������ȷ����ĸ.\n");
    }
    while(getchar()!='\n')
        continue;

    return ch;
}

void print(struct word * pst)
{
    printf("\n ���� ��С   ���뷽ʽ    ��    б\n");
    printf("%3u", pst->font);
    printf("%6u", pst->size);
    printf("%10s", align[pst->alignment]);
    printf("%8s", open[pst->bold]);
    printf("%6s\n\n", open[pst->italic]);
}

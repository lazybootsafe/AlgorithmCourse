/*7.��дһ��������ϰ 6 ������ͬ�ĳ���ʹ�� unsigned long ���͵ı�
������������Ϣ������ʹ�ð�λ�����������λ��Ա��������Щ��Ϣ��*/

#include <stdio.h>
#include <string.h>

#define ID_MASK 0xff
//����ȱʧ�����
#define SIZE_MASK (0x7f << 8)
#define ALIGN_MASK (0x3 << 15)

#define CENTER (0x1 << 15)
#define RIGHT (0x2 << 15)
#define BOLD (0x1 << 17)
#define ITALIC (0x1 << 18)

const char *align[3]={"��","��","��"};
const char *open[2]={"��","��"};

char get_choice(void);
char get_select(void);
void print(unsigned long);

int main(void)
{
    unsigned long type=0;
    char choice;
    char ch;
    int num;

    print(type);
    while ((choice=get_choice())!='q')
    {
        switch (choice)
        {
        case 'f': printf("�ı����� (0 - 255): ");
                  scanf("%lu", &num);
                  getchar();
                  type&=~ID_MASK;		//�ѱ�ʾ����ID��λ���
                  type|=num;			//��������ID
                  break;
        case 's': printf("�ı��С (0 - 127): ");
                  scanf("%lu", &num);
                  getchar();
                  type&=~SIZE_MASK;
                  type|=(num << 8);
                  break;
        case 'a': type&=~ALIGN_MASK;
                  printf("ѡ����뷽ʽ:\n");
                  printf("l)��   c)��   r)��\n");
                  if ((ch=get_select())=='c')
                      type|=CENTER;
                  else if (ch=='r')
                      type|=RIGHT;
                      break;
        case 'b': type^=BOLD;
                  break;
        case 'i': type^=ITALIC;
                  break;
        default : break;
        }
        print(type);
    }
    printf("�ټ�.\n");

    return 0;
}

char get_choice(void)
{
    char ch;

    printf("f)�ı�����\ts)�ı��С\ta)�ı���뷽ʽ\n");
    printf("b)�л�����\ti)�л�б��\nq)�뿪\n");

    while (strchr("fsabiq", ch=getchar())==NULL)
    {
        while (getchar()!='\n')
            continue;
        printf("��������ȷ����ĸ.\n");
    }
    while (getchar()!='\n') continue;

    return ch;
}

char get_select(void)
{
    char ch;

    while (strchr("lcr", ch=getchar())==NULL)
    {
        while (getchar()!='\n')
            continue;
        printf("��������ȷ����ĸ.\n");
    }
    while (getchar()!='\n') continue;

    return ch;
}

void print(unsigned long num)
{
    printf("\n ���� ��С   ���뷽ʽ    ��    б\n");
    printf("%3u", num & ID_MASK);
    printf("%6u", (num & SIZE_MASK) >> 8);
    printf("%10s", align[(num & ALIGN_MASK) >> 15]);
    printf("%8s", open[(num & BOLD) >> 17]);
    printf("%6s\n\n", open[(num & ITALIC) >> 18]);
}

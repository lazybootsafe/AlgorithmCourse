/*5.��дһ����������һ�� unsigned int ����ֵ�е�����λ������תָ����
����λ�����磬rotate_l(x, 4)��x������λ�����ƶ�4��λ�ã����Ҵ������
�Ƴ���λ�����³������Ҷˡ�Ҳ����˵���Ѹ߽�λ�Ƴ���λ����ͽ�λ����
һ�������в��Ըú�����*/

#include <stdio.h>
#include <limits.h>
#define SIZE CHAR_BIT * sizeof(unsigned int)

char *trans_10to2(unsigned int n,char *ch);//ʮ����ת�������ַ���
void show(const char *st);
unsigned int move_left(unsigned int, int);
int main(void)
{
    unsigned int num;
    int bit;
    char st[SIZE + 1];

    printf("����һ����������Ҫ���ƶ���λ����:\n");
    while( (scanf("%u%d",&num,&bit)) != 2)
    {
        printf("����������.");
        while(getchar() != '\n') continue;
    }
    while(getchar() != '\n') continue;
    printf("ԭ���Ķ������ַ�����:\n");
    show(trans_10to2(num,st));
    num = move_left(num, bit);//������λ�����ƶ�
    printf("���ڵĶ������ַ�����:\n");
    show(trans_10to2(num,st));
}

unsigned int move_left(unsigned int n, int bit)
{
    int i;

    for(i=0;i<bit;i++)
        n=(n<<1)+((n>>(SIZE-1))&01);//n������һ�����ұ�Ϊ0
                                    //(n>>(SIZE-1))&01�������ұ�0��������ߵ�ֵ
                                    //ѭ���ƶ���λ����
    return n;
}

char *trans_10to2(unsigned int n,char *ch)//ʮ����ת�������ַ���
{
    int i;

    for (i=SIZE-1;i>=0;i--,n>>= 1)
        ch[i]=(01&n)+'0';//n&01����n���һλ��ֵ
    ch[SIZE]='\0';

    return ch;
}

void show(const char *st)
{
    int i=0;

    while(st[i])
    {
        putchar(st[i]);
        if(++i%4==0 && st[i])
            putchar(' ');
    }
    printf("\n");
}


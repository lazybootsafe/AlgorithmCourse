#include <stdio.h>//���һ������chline(ch, i, j)����ӡָ�����ַ�j��i�С�
void chline(char ,int ,int );
int main()
{
    int hang=0,lie=0;
    char ch;

    printf("��Ҫ��ӡʲô�ַ�:");
    ch=getchar();
    printf("������������:");
    scanf("%d %d",&hang,&lie);
    chline(ch,hang,lie);
    printf("\n");

    return 0;
}

void chline(char ch,int hang,int lie)
{
    int a,b;

    for(a=1;a<=hang;a++)
    {
        for(b=1;b<=lie;b++)
            printf("%c",ch);
        printf("\n");
    }
}

#include <stdio.h>  //��дһ���������û�ָ������˰��������Ӧ��˰���룬Ȼ�����˰��
#define TAX1 0.15
#define TAX2 0.28
//2��˰��
#define SINGLE 17850
#define HOUSE 23900
#define SHARE 29750
#define DIVORCED 14875
//4�����
int main(void)
{
    double gross=0.0,tax=0.0,base=0.0;
    int a,n;
    const int LENGTH=65;

    for(a=0;a<LENGTH;a++)
        printf("*");
    printf("\n��ѡ��������:\n");
    printf("1) ���� \t\t\t 2) ����\n");
    printf("3) �ѻ�,���� \t\t\t 4) �ѻ�,����\n");
    printf("5) �뿪\n");
    for(a=0;a<LENGTH;a++)
        printf("*");
    printf("\n");//��ӡ���

    while(scanf("%d",&n)==1)
    {
    switch(n)
        {
        case 1:base=SINGLE;
                break;
        case 2:base=HOUSE;
                break;
        case 3:base=SHARE;
                break;
        case 4:base=DIVORCED;
                break;
        case 5:printf("�뿪.\n");
                return 0;
        default:printf("��������ȷѡ��.\n");
        }//ѡ�����

    printf("������˰���:\n");
    scanf("%lf",&gross);
    if(gross<=base)
       tax=gross*TAX1;
    else
       tax=base*TAX1+(gross-base)*TAX2;
    printf("����Ҫ���ɵ�˰����:%.2lf.\n",tax);
    printf("�ٴ�ѡ�����(1-4;����q�뿪):\n");
    }
    return 0;
}

#include <stdio.h>//��дһ��������ʾһ���ṩ�ӷ����������˷��������Ĳ˵������
//�û�ѡ���ѡ��󣬳�����ʾ�û������������֣�Ȼ��ִ���û��ղ�ѡ��Ĳ�����
#include <ctype.h>
float get_float(void);
char get_choice(void);
char get_first(void);
int main(void)
{
    char choice;
    float num1, num2;

    while((choice=get_choice()) != 'q')
    {
        printf("�����һ������:");
        num1=get_float();
        printf("����ڶ�������:");
        num2=get_float();
        switch(choice)
        {
        case 'a':printf("%.2f + %.2f = %.2f\n",num1,num2,num1+num2);
                    break;
        case 'b':printf("%.2f - %.2f = %.2f\n",num1,num2,num1-num2);
                    break;
        case 'c':printf("%.2f * %.2f = %.2f\n",num1,num2,num1*num2);
                    break;
        case 'd':if(!num2)
        {
            printf("����������һ������0��ֵ:");
            num2=get_float();
        }
            printf("%.2f / %.2f = %.2f\n",num1,num2,num1/num2);
                    break;
        default:printf("��ֻ��ʶ a, s, m, d ���� q.\n");
                     break;
        }
    }
    printf("�ټ�.\n");
    return 0;
}
float get_float(void) //�������ֵ�������������ĺ���
{
    char ch;
    float num;

    while(scanf("%f",&num)!=1)
    {
        while((ch=getchar()) !='\n')
            putchar(ch);//�����������
        printf("����һ������.\n������һ����ȷ������,"
               "����2.5,-1.78E8,����3:");

    }
    while (getchar()!='\n')
        continue;

    return num;
}

char get_choice(void)//��ӡ��������û�ѡ��ĺ���
{
    char ch;

    printf("������ѡ��Ĳ���:\n");
    printf("%-36s%s","a. ��", "s. ��\n");
    printf("%-36s%s","m. ��", "d. ��\n");
    printf("%s\n", "q. �뿪");

    ch=get_first(); //ֻȡ����ĵ�һ���ַ�
    while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd'
                && ch != 'q')
        {
            printf("������:a, s, m, d or q.\n");
            ch = get_first();
        }
    return ch;
}

char get_first(void) //ֻȡ����ĵ�һ���ַ�
{
    char ch;
    while( isspace(ch = getchar()))
        continue;
    while (getchar() != '\n' )
        continue;

    return ch;
}

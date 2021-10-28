#include <stdio.h>//�޸ĵ�7�µı����ϰ8�����ַ��������ֱ�ǲ˵���ѡ���q����5
//��Ϊ��������ı�ǡ�
#include <ctype.h>
#define BASE1 8.75
#define BASE2 9.33
#define BASE3 10.00
#define BASE4 11.20
//���ֵȼ��Ļ�������
#define TIME 40			//����40hΪ�Ӱ�
#define	MUL	1.5		//�Ӱ�ʱ������ƽʱ��1.5��
#define	RATE1 0.15		//ǰ300��Ԫ��˰��
#define RATE2 0.2			//300-450��Ԫ��˰��
#define RATE3 0.25		//����450��Ԫ��˰��
#define BREAK1 300		//˰�ʵĵ�һ���ֽ��
#define BREAK2 450		//˰�ʵĵڶ����ֽ��
#define LENGTH 65		//*�ĳ���

char get_choice(void);
void calculate(double base);
int main(void)
{
    double base;
    char choice;

    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a': base = BASE1;
                      break;
            case 'b': base = BASE2;
                      break;
            case 'c': base = BASE3;
                      break;
            case 'd': base = BASE4;
                      break;
            default: printf("��ֻ��ʶ a, b, c, d ���� q.\n");
                     break;
        }
        if (choice >= 'a' && choice <= 'd')
            calculate(base);
    }

    return 0;
}

//������������ĺ���
void calculate(double base)
{
    double hour, gross, tax;

    printf("��һ�ܹ�������Сʱ? ");
    scanf("%lf", &hour);
    while (getchar() != '\n')
        continue;					//�����س�
    if (hour <= TIME)
        gross = hour * base;
    else
        gross = TIME * base + (hour - TIME) * MUL * base;
    //����������
    if (gross <= BREAK1)
        tax = gross * RATE1;
    else if (gross <= BREAK2)
        tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
    else
        tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2
            + (gross - BREAK2) * RATE3;
    //����˰��
    printf("�ܹ���: $%.2lf\n˰: $%.2lf\n"
            "������: $%.2lf\n",
            gross, tax, (gross - tax));
    printf("\n");
}

//��ӡѡ����沢���û�����ĺ���
char get_choice(void)
{
    char ch;
    int count;

    for (count = 0; count < LENGTH; count++)
        printf("*");
    printf("\n��ѡ����Ĺ��ʵȼ�:\n");
    printf("%-36s%s","a) $8.75/hr", "b) $9.33/hr\n");
    printf("%-36s%s","c) $10.00/hr", "d) $11.20/hr\n");
    printf("%s\n", "q) quit");
    for (count = 0; count < LENGTH; count++)
        printf("*");
    printf("\n");

    ch = getchar();
    while (getchar() != '\n')
        continue;					//���������ʣ������

    return ch;
}

#include <stdio.h> //�����ֳ���,ʹ�ö��ֲ��ң�binary search������
#define LOW 1   //��ʼ����
#define HIGH 100    //��ʼ����
int get_guess(void);
int main(void)
{
    while(1)
        get_guess();
}

int get_guess(void)
{
    long guess = (HIGH+LOW)/2;
    long n=1;//nΪ�µĴ���
    long low=LOW;
    long high= HIGH;
    char ch;

    printf("ѡ��һ����������%dС��%d,��������.\n",LOW,HIGH);
    printf("�Ծ�����\"y\",���˴�\"b\",С�˴�\"s\".\n");
    printf("��...��%ld��?\n",guess);
    while ((ch=getchar()) != 'y')  /* ��ȡ��Ӧ���� y ���Ա� */
    {
        if(ch=='s')
        {
            low=guess; //��С��,��������Ϊ�µ���
            guess=(guess+high)/2;//����guess�����޺�����֮��
        }
        else if(ch=='b')
        {
            high=guess;//�´���,��������
            guess=(guess+low)/2;//����guess�����޺�����֮��
        }
        else
            printf("��ֻ��ʶ'y','b'�� 's'.\n");

        printf("��...��%ld��?\n",guess);
        while(getchar()!='\n')
            continue; //ֻȡ��������ĸ
        if(guess==HIGH-1)
            guess++; //��ȡֵ�ܴﵽ����
        n++;
    }
        printf("�����Ҳ¶���\n");
        printf("��ֻ����%ld�ξͲ³�����.\n",n);
        printf("�������!\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("�������°�!\n");
        while(getchar()!='\n')
            continue; //ֻȡ��������ĸ
    return 0;
}

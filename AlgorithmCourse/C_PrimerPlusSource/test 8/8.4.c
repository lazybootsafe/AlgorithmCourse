#include <stdio.h> //�ó���Ҫ����ƽ��ÿ�����ʵ���ĸ������Ҫ�ѿհ�ͳ��Ϊ���ʵ���ĸ��
#include <ctype.h>
int main(void)
{
    char ch=0;
    double average_letter=0;
    int inword=0;//�ڵ�����Ϊ1,����Ϊ0
    int chars=0;
    int words=0;

    printf("���뵥��,ͳ��ƽ����ĸ����.\n");
    while((ch=getchar())!= EOF)
    {
        if(!isspace(ch) && !ispunct(ch))//���ǿհ׺ͱ��
            chars++;    //ͳ���ַ�����
        if(!ispunct(ch)&&!isspace(ch)&&!inword)//���ǿո������ڵ�����
        {
            inword=1; //��˵����ʼ����,�ڵ���Ϊ1
            words++; //��������1
        }
        if(ispunct(ch)||isspace(ch)&&inword) //�뿪�������ǿհ׻���
            inword=0;//���ʽ�����,���ڵ�������
    }
    average_letter=(double)chars/(double)words;
    printf("��%d���ַ���%d������\n",chars,words);
    printf("ƽ����ĸ������:%.2f��.\n",average_letter);

    return 0;
}

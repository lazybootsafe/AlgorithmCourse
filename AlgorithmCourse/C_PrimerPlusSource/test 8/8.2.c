#include <stdio.h>  //��дһ������������ EOF ֮ǰ����������Ϊ�ַ�����ȡ������Ҫ
//��ӡÿ��������ַ�������Ӧ��ASCIIʮ����ֵ��
int main(void)
{
    char ch;
    int n=0; //nͳ���ַ���
    while((ch=getchar())!=EOF)
    {
        n++; //��ӡ�ַ����
        if(ch >= 32)
            printf("%c",ch); //���з����Ʊ�������
        else if (ch =='\n' || ch == '\t' )
            printf("%s",ch=='\n' ? "\\n":"\\t");
        //һ������ַ������
        else
            printf("^%c",ch + 64);
        printf("%-5d",ch);
        if(ch=='\n')
            n=0;
        if(n%10==0) //10�Ի���
            printf("\n");
    }
    return 0;
}

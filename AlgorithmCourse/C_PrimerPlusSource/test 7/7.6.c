#include <stdio.h> //��д�����ȡ���룬����#ֹͣ������ei���ֵĴ�����
int main(void)
{
    char ch;
    char ch_pre=0; //ǰһ���ַ�
    int n=0; //��¼ei���ִ���.
    printf("��������(ͳ��ei���ִ���,#�뿪):\n");
    while((ch=getchar())!='#')
    {
        if((ch_pre=='e')&&(ch=='i'))
            n++;
        ch_pre=ch; //ÿһ��ѭ����,��ch��ֵ��ch_pre,ch_pre�ͱ�Ϊǰһ���ַ�
    }
    printf("\"ei\"������%d��.\n",n);
    return 0;
}

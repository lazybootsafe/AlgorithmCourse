#include <stdio.h> //��ȡ����,#ֹͣ,��ӡ�ո��з����������ַ���
int main(void)
{
    char ch;
    int space=0,enter=0,other=0;

    while ((ch = getchar()) != '#')
    {
        if(ch==' ')
            space++;
        else if(ch=='\n')
            enter++;
        else
            other++;
    }
    printf("�ո���:%d���з���:%d�����ַ���:%d\n",space,enter,other);
    return 0;
}

#include <stdio.h>//��дһ������������ EOF ֮ǰ����������Ϊ�ַ�����ȡ���ó���//Ҫ���������еĴ�д��ĸ��Сд��ĸ�ĸ�����
#include <ctype.h>
int main(void)
{
    char ch;
    int up_letter=0,low_letter=0;

    printf("�����дСд��ĸ,ͳ�Ƹ���.\n");
    while( (ch=getchar()) != EOF )
    {
        if(islower(ch))
            low_letter++;
        if(isupper(ch))
            up_letter++;
    }
    printf("��д��ĸ��%d��,Сд��ĸ��%d��.",up_letter,low_letter);

    return 0;
}

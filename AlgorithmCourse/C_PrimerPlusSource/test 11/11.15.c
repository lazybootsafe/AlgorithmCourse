/*15.ʹ���ַ����ຯ��ʵ��atoi()���������������ַ������Ǵ����֣�
�ú�������0��*/
#include <stdio.h>
#include <ctype.h>
int myatoi(char * st);

int main(void)
{
    char str[40];
    gets(str);
    printf("%d\n", myatoi(str));

    getchar();
    return 0;
}

int myatoi(char * st)
{
    int sum=0;

    while(*st)
    {   //���ַ�������λת��Ϊ��ֵ
        if(isdigit(*st))
            sum=10*sum+(*st-'0');
        else//���Ǵ������򷵻�0
            return 0;
        st++;
    }
    return sum;
}

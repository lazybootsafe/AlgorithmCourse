#include <stdio.h> //����Ҫ��ӡÿ��������ַ��Լ���Ӧ��ASCII�루ʮ���ƣ���һ�д�ӡ8���ַ���
int main(void)
{
    char ch;
    int n=1; //�ַ���
    printf("������һЩ����(#����):\n");
    while ((ch = getchar()) != '#')
    {
        printf("%3c:%3d ",ch,ch);
        if(n++%8==0)
            printf("\n");
    }
    return 0;
}

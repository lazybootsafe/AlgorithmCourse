#include <stdio.h>  /*��дһ������������3��������һ���ַ��������������ַ������Ǵ�
                      ��ӡ���ַ�����1������ָ��һ���д�ӡ�ַ��Ĵ�������2������ָ����ӡָ
                      ���ַ�����������дһ�����øú����ĳ���*/
void TEST(char ch,int i,int j);
int main()
{
    int i,j;
    char ch;

    printf("�����ַ�:\n");
    ch=getchar();
    printf("��ӡ����,ÿ�м���:\n");
    scanf("%d%d",&j,&i);
    TEST(ch,i,j);
    return 0;
}
void TEST(char ch,int i,int j) //iһ�д�ӡ����,j��ӡ����
{
    int m,n;
    for(m=1;m<=j;m++)
    {
        for(n=1;n<=i;n++)
            printf("%c",ch);
        printf("\n");
    }
}

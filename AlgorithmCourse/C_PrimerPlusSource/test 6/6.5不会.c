#include<stdio.h>    //��ӡ������,������ĸ���µ����������ߵݼ���A
int main(void)
{
    char ch = 0,temp = 0;
    int i,j,length;
    printf("�������д��ĸ:");
    scanf("%c",&ch);

    length = ch - 'A' + 1;   //�ж�������ĸ
    for (i = 0; i < length; i++)
    {
        temp = 'A'-1 ;
        for (j = 0; j < (length - i -1); j++)
            printf(" ");
        for (j = 0; j <= i; j++)
            printf("%c", ++temp);
        for (j = 0; j < i; j++)
            printf("%c", --temp);
        printf("\n");
    }
    system("pause");
    return 0;
}

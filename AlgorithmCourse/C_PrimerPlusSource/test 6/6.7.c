#include<stdio.h> //��ȡһ������,�����ӡ��
#include <string.h>
int main(void)
{
    char word[40];
    int n,a;
    printf("������һ������:");
    scanf("%s",word);
    n=strlen(word);
    printf("������ʵ�����д��:");
    for(a=0;a<=n;a++)
        printf("%c",word[strlen(word)-a-1]);
    printf("\n");

    return 0;
}

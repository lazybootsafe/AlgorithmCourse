#include <stdio.h> //�����ӡ���������
int main(void)
{
    char word[256];
    int a=-1,b;
    printf("����һ�л�:");
    do
    {
        a++;
        scanf("%c", &word[a]);
    } while (word[a] != '\n');
    for(b=a;b>0;b--)
    {
        printf("%c",word[b-1]);
	}
	return 0;
 }

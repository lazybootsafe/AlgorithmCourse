#include <stdio.h>  //���һ������ͳ���ڶ����ļ���β֮ǰ��ȡ���ַ�����
int main(void)
{
    int ch;
    int a=0;
    while((ch=getchar())!=EOF)
        a++;
    printf("%d\n",a);


    return 0;
}

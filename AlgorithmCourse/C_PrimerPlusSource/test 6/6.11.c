#include <stdio.h> //����8������,�����ӡ8������
int main(void)
{
    long integer[8];
    int a;
    printf("������8������:");
    for(a=0;a<8;a++)  //�����0��ʼ�洢,����a=0
    {
        scanf("%d",&integer[a]);
    }
    for(a=7;a>=0;a--)  //8λ��,��������Ԫ��Ϊ7
    {
        printf("%d",integer[a]);
    }
    printf("\n");
	system("pause");
    return 0;
 }

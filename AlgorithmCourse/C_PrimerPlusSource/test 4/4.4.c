/*4.��дһ��������ʾ�û�������ߣ���λ��Ӣ�磩��������Ȼ������
��ĸ�ʽ��ʾ�û����������Ϣ��
Dabney, you are 6.208 feet tall
ʹ��float���ͣ�����/��Ϊ���š������Ը�⣬����Ҫ���û�������Ϊ
��λ������ߣ�������Ϊ��λ��ʾ������*/
#include <stdio.h>
#define CM 100
int main(void)
{
    float height;
    char name[40];
    printf("���������ֺ����(cm):");
    scanf("%s%f",name,&height);
    height=height/CM;
    printf("%s,you are %.3fm feet tall\n",name,height);

    return 0;
}

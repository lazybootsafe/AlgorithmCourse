/*1.��дһ���������Ѷ������ַ���ת��Ϊһ����ֵ�����磬���������
�䣺
char * pbin = "01001001";
��ô��pbin��Ϊ�������ݸ��ú�������Ӧ�÷���һ��int���͵�ֵ25��*/

#include <stdio.h>
#include<math.h>
int transf(char *st);

int main(void)
{
    char *pbin="01001001";

    printf("%s��ʮ������%d.\n",pbin,transf(pbin));

    return 0;
}

int transf(char *st)
{
    int tol=0;

    while(*st)//����*st!='\0'
        tol=(tol<<1)+(*st++-'0');

    return tol;
}

/*2.��дһ��������ʾ�û����������գ���ִ��һ�²�����
a.��ӡ�����գ�����˫���ţ�
b.�ڿ��Ϊ20���ֶ��Ҷ˴�ӡ�����գ�����˫���ţ�
c.�ڿ��Ϊ20���ֶ���˴�ӡ�����գ�����˫���ţ�
d.�ڱ�������ȿ�3���ֶ��д�ӡ�����ա�*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[40];
    char xing[40];
    int widthn,widthx;
    printf("���������:");
    scanf("%s",name);
    printf("���������:");
    scanf("%s",xing);
    widthn=strlen(name)+3;
    widthx=strlen(xing)+3;
    printf("a:���������\"%s\",����\"%s\".\n",name,xing);
    printf("b:���������\"%20s\",����\"%20s\".\n",name,xing);
    printf("c:���������\"%-20s\",����\"%-20s\".\n",name,xing);
    printf("d:���������\"%*s\",����\"%*s\".\n",
           widthn,name,widthx,xing);
    return 0;
}

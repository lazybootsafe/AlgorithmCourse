/*.��дһ����������ʾ�û���������Ȼ����ʾ�û������ա���һ�д�
ӡ�û�����������գ���һ�зֱ��ӡ�����յ���ĸ������ĸ��Ҫ����Ӧ��
���յĽ�β���룬������ʾ��
Melissa Honeybee
7��������8
���������ٴ�ӡ��ͬ����Ϣ��������ĸ��������Ӧ�����յĿ�ͷ���룬
������ʾ��
Melissa Honeybee
7������8*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    char firstname[40],secondname[40];
    int a,b;
    printf("��������:");
    scanf("%s",firstname);

    printf("��������:");
    scanf("%s",secondname);

    a=strlen(firstname);
    b=strlen(secondname);
    printf("%s %s\n",firstname,secondname);
    printf("%*d %*d\n",a,a,b,b);
    printf("%s %s\n",firstname,secondname);
    printf("%-*d %-*d\n",a,a,b,b);

    return 0;
}

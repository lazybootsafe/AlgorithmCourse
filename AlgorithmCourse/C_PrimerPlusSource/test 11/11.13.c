/*13.��дһ�����򣬷�����ʾ�����в����ĵ��ʡ����磬�����в�����
see you later���ó���Ӧ��ӡlater you see��*/
#include <stdio.h>
#include <string.h>
//void reverse(char * st);
int main(int argc, char * argv[])
{
    int count;

    for (count = argc - 1; count > 0; count--)
        printf("%s ", argv[count]);

    return 0;
}

////�������ֻ�ǵ����ӡ�����ַ�����������ʹ�ַ�������
//void reverse(char * st)
//{
//    int i=0;
//
//    for(i=strlen(st)-1;i>=0;i--)
//        putchar(st[i]);
//    st[0]='\0';
//}

/*3.��Ʋ�����һ����������һ�������а�һ�����ʶ���һ�������У���
�����������е������ַ����ú���Ӧ��������1���ǿհ��ַ�ǰ������п�
�ס���һ�����ʶ���Ϊû�пհס��Ʊ�����з����ַ����С�*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 40
void word_get(char *ar);
int main(void)
{
    char ar[SIZE];

    word_get(ar);
    puts(ar);

    system("pause");
    return 0;
}

void word_get(char *ar)
{
    char ch;

    while( isspace( ch=getchar() ) )
        continue;
    do
        *ar++=ch;
    while( !isspace( ch=getchar() ) );
    *ar='\0';
}

#include <stdio.h> //ʹ��switch��д��ϰ4��
int main(void)
{
    char words;
    int n=0; //�ַ���
    printf("����������(#�뿪):\n");
    while((words=getchar()) != '#')
    {
        switch(words)
        {
        case '.':words='!'; //�滻���
                n++;
                break;
        case '!':printf("!"); //�滻!
                n++;
                break;
        default:break;
        }
        putchar(words);
    }
    printf("һ��������%d���滻.\n",n);
    return 0;

}

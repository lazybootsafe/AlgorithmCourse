#include <stdio.h> //ʹ��if else����дһ�������ȡ���룬����#ֹͣ��
//�ø�̾���滻��ţ���������̾���滻ԭ���ĸ�̾�ţ���󱨸�����˶��ٴ��滻��
int main(void)
{
    char words;
    int n=0; //�ַ���
    printf("����������(#�뿪):\n");
    while((words=getchar()) != '#')
    {
        if(words == '.')
            {
                words='!'; //�滻���
                n++;
            }
        else if (words == '!')
            {
                printf("!"); //�滻!
                n++;
            }
        printf("%c",words);
    }
    printf("һ��������%d���滻.\n",n);
    return 0;

}

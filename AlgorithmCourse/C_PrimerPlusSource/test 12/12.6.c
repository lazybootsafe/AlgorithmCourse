/*6.��дһ����������1000��1��10��Χ�ڵ�����������ñ�����ӡ
��Щ���֣�����ӡÿ�������ֵĴ������� 10 ����ͬ������ֵ���У����ɵ�
���ֳ��ֵĴ����Ƿ���ͬ������ʹ�ñ����Զ���ĺ�����ANSI C��rand()��
srand()���������ǵĸ�ʽ��ͬ������һ�������ض����������������Եķ�
����*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define SIZE_N 10

int main(void)
{
    int i,j;
    int ar[SIZE_N];//����������ִ���������
    int seed[SIZE_N]={1,2,3, 4, 5, 6, 7, 8, 9, 10};

    for(i=0;i<SIZE_N;i++)
    {
        for(j=0;j<SIZE_N;j++)
            ar[j]=0;
        srand(seed[i]);
        printf("������%d\n",seed[i]);
        for(j=0;j<SIZE;j++)
            ar[rand()%10]++;

        for(j=0;j<SIZE_N;j++)
        {
            printf("%d:%-5d",j+1,ar[j]);
            if(j==4)
                puts("");
        }
        puts("");
    }
    return 0;
}

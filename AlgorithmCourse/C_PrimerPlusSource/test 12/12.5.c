/*5.��дһ����������100��1��10��Χ�ڵ�����������Խ������У���
�԰ѵ�11�µ������㷨�ԼӸĶ�������������������������������
�򣩡�*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void print_ar(int *ar,int n);//��ӡ����
int main(void)
{
    int ar[100]={0};
    int i;

    srand((unsigned int)time(0));
    for(i=0;i<SIZE;i++)
        ar[i]=(int)rand()%10 + 1;//�������������

    puts("old:");
    for(i=0;i<SIZE;i++)
    {//��ӡ��ʼ100�������
        printf("%-4d",ar[i]);
        if(i%10==9)
            puts("");
    }

    puts("new:");
    print_ar(ar,SIZE);//��ӡ����õ���

    return 0;
}

void print_ar(int *ar,int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(ar[i]<ar[j])
            {
                temp=ar[j];
                ar[j]=ar[i];
                ar[i]=temp;
            }
    for(i=0;i<n;i++)
    {
        printf("%-4d",ar[i]);
        if(i%10==9)
            puts("");
    }
}

#include<stdio.h>/*3.��дһ�����������ش�����int���������е����ֵ������һ���򵥵�
�����в��Ըú�����*/
int return_max(int ar[] , int n);

int main(void)
{
    int source[]={23,2,132,66,3,5,25,7,3,20};
    printf("%d",return_max(source,10));
    printf("\n");

    return 0;
}

int return_max(int ar[] , int n)
{
    int max=ar[0],i,a;

    for(i=0;i<n;i++)
    {
        if(max<ar[i])
            max=ar[i];
    }

    return max;
}

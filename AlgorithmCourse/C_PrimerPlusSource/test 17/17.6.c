/*6.��дһ���������� 3 ��������һ�����������ں������������������
�����Ԫ�ظ����ʹ����ҵ���������������ҵ������������У���ô�ú���
���� 1������������������У��ú����򷵻� 0���ö��ֲ��ҷ�ʵ�֡�*/

#include <stdio.h>
#define SIZE 10
int Binary_search(int ar[],int n,int search_num);
int main()
{
    int search_num;
    int ar[SIZE]={1,2,3,4,5,6,7,8,9,10};

    printf("����1����(q�뿪):");
    while(scanf("%d",&search_num)==1)
    {
        puts("0���������У�1����������.");
        printf("%d\n",Binary_search(ar,SIZE,search_num));
        printf("�ٴ�����1����(q�뿪):");
    }
    puts("�ټ�.");

    return 0;
}

int Binary_search(int ar[],int n,int search_num)
{
    int start=0;
    int end=n-1;
    int mid;

    while(start<=end)
    {
        mid=(start+end) / 2;
        if(search_num < ar[mid])
            end=mid-1;
        else if(search_num > ar[mid])
            start=mid+1;
        else
            return 1;
    }
    return 0;
}





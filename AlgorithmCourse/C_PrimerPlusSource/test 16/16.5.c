/*5.��дһ������������Щ�������ں�int����Ԫ�ص�������������Ĵ�С
��һ������ѡȡ������ֵ���ú��������������ѡ��ָ��������Ԫ�أ�����
ӡ���ǡ�ÿ��Ԫ��ֻ��ѡ��һ�Σ�ģ��齱���ֻ���ѡ�����ų�Ա������
�⣬������ʵ����time()����12�����۹��������Ƶĺ���������srand()��
ʹ������������������ʼ�������������rand()����дһ���򵥵ĳ����
�Ըú�����*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 10//���������������

void print_rand(const int ar[],int len,int n);
int main()
{
    int n;//��Ҫ���ƶ�������Ԫ��
    int ar[SIZE]={1,2,3,4,5,6,7,8,9,10};

    srand(time(0));//��ϵͳʱ��Ϊ����
    printf("ԭʼ������:\n");
    for(int i=0;i<SIZE;i++)
        printf("%-2d ",ar[i]);
    puts("\n����Ҫ�����������ȡ�������֣�");
    while( scanf("%d",&n) == 1 )
    {
        print_rand(ar,SIZE,n);
        puts("\n�ٴ���������Ҫ�����������ȡ����������(q�뿪)��");
    }
    puts("�ټ�.");

    return 0;
}

void print_rand(const int ar[],int len,int n)
{
    int i,j;
    int arcopy[len];
    int temp;//��ʱ���

    //����һ�����鸱���������޸�ԭʼ����
    memcpy(arcopy,ar,len*sizeof(int));
    if(n>len||n<1)
        printf("����������ַ�Χ����(������1-%d)",len);
    else
    {
        printf("ȡ����%d����������£�\n",n);
        for(i=0;i<n;i++)
        {
            j=(int)rand()%(len-i);//j��0��(10-i)֮����±�
            {   //ÿ����������±��Ӧ��Ԫ�غ��������һ��Ԫ�ؽ���
                //���һ��Ԫ��ÿ��ѭ���ݼ�1���Ա�֤���ظ�
                temp=arcopy[j];
                arcopy[j]=arcopy[len-i-1];
                arcopy[len-i-1]=temp;
            }
            printf("%-3d ",arcopy[len-i-1]);//��ӡ����
        }
    }

    printf("\n");
}

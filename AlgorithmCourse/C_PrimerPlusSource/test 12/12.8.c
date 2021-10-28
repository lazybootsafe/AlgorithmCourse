/*8.�����ǳ����һ���֣�
// pe12-8.c
#include <stdio.h>
int * make_array(int elem, int val);
void show_array(const int ar [], int n);
int main(void)
{
    int * pa;
    int size;
    int value;
    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}
�ṩmake_array()��show_array()�����Ķ��壬��ɸó���make_array()
��������������������1��������int���������Ԫ�ظ�������2��������Ҫ��
��ÿ��Ԫ�ص�ֵ���ú�������malloc()����һ����С���ʵ����飬����ÿ��
Ԫ������Ϊָ����ֵ��������һ��ָ��������ָ�롣show_array()������
ʾ��������ݣ�һ����ʾ8������*/
#include <stdio.h>
#include <stdlib.h>
int * make_array(int elem, int val);
void show_array(const int ar [], int n);
int main(void)
{
    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");

    return 0;
}

int * make_array(int elem, int val)
{
    int i;
    int *pt;
    pt=(int *)malloc(elem * sizeof(int));

    for(i=0;i<elem;i++)
        pt[i]=val;

    return pt;
}

void show_array(const int ar [], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
        if(i%8 ==7)
            puts("");
    }
    puts("");
}

/*11.��дһ����Ϊtransform()�ĺ���������4���������ں�double��������
��Դ���������ں�double�������ݵ�Ŀ����������һ����ʾ����Ԫ�ظ�����
int���Ͳ���������������ȼ۵ĺ���ָ�룩��transform()����Ӧ��ָ������
Ӧ����Դ�����е�ÿ��Ԫ�أ����ѷ���ֵ������Ŀ�������С����磺
transform(source, target, 100, sin);
���������target[0]����Ϊsin(source[0])���ȵȣ�����100��Ԫ�ء���һ
�������е���transform()4�Σ��Բ��Ըú������ֱ�ʹ��math.h�������е���
�������Լ��Զ��������������Ϊ������*/

#include <stdio.h>
#include <math.h>
#define PSIZE 4
#define SIZE 100

void transform(double source[],double target[],int size,double(*pf)(double num));
double oppsite_val(double);//Դ����ȡ��ֵ
double double_val(double);//Դ����˫��

int main(void)
{
    int i, j;
    double source[SIZE],target[SIZE];
    double(*p[PSIZE])(double)={sin,sqrt,oppsite_val,double_val};

    printf("Դ����:\n");
    for (i=0;i<SIZE;i++)
    {
        source[i]=i;
        printf("%7g ",source[i]);
        if (i%10==9)
            printf("\n");
    }
    printf("\n");
    for (i=0;i<PSIZE;i++)
    {
        printf("Դ����%d:\n",i+1);
        //target[0]����Ϊsin(source[0])
        transform(source,target,SIZE,p[i]);//p[0]��sin��p[1]�ǿ���
        for (j=0;j<SIZE;j++)
        {
            printf("%7.2f ",target[j]);
            if(j%10==9)
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

void transform(double source[],double target[],int size,double(*pf)(double num))
{
    for(int i=0;i<size;i++)
        target[i]=(*pf)(source[i]);
}

double oppsite_val(double num)
{
    return (-1*num);
}

double double_val(double num)
{
    return (2*num);
}

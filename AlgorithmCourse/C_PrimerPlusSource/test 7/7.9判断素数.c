#include <stdio.h>  //��дһ������,ֻ��������������,Ȼ����ʾ����С�ڻ���ڸ���������.
int main(void)
{
    long num=0;
    long a,b;//a�������,b�����ڲ�
    int flag; //�������


    printf("������һ��������(q�뿪):\n");
    while(scanf("%ld",&num)==1)
    {
    if(num>0)   //����0��������
        {
            printf("%ld��������:\n",num);
            for(a=2;a<=num;a++) //a��num�������б���
            {
                flag = 1;   //�������Ϊ1
                for(b=2;b*b<=a;b++)  //�жϱ����ĸ������Ƿ�������
                {
                    if(a%b==0)  //�ܱ������Ͳ�������
                        flag=0; //�����������Ϊ0
                }
                if(flag==1)   //�ж��Ƿ�������
                    printf("%ld ",a);
            }
            printf("\n");
        }
    else //С�ڵ����㲻��
        printf("������������.\n");
    printf("��������һ����(q�뿪):");
    }

    return 0;
}

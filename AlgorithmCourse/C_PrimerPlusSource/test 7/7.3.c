#include <stdio.h> //��дһ�����򣬶�ȡ����ֱ���û����� 0��
//��������󣬳���Ӧ�����û������ż���������� 0��������
//��Щż����ƽ��ֵ�������������������������ƽ��ֵ��
int main(void)
{
    long even_num=0,odd_num=0; //ż������������
    long num;
    long even_sum=0,odd_sum=0; //ż����������
    printf("������һ������(��0�˳�):");
    for(scanf("%ld",&num);num!=0;)
    {
        if(num%2==0)
        {
            even_num++;
            even_sum+=num; //����ż����
        }
        else
        {
            odd_num++;
            odd_sum+=num; //����������
        }
    printf("��������һ������(0�˳�):");
    scanf("%ld",&num);
    }
    printf("\n");
    printf("ż���ĸ���Ϊ%ld,���ǵ�ƽ������:%.3f\n",even_num,(even_num==0)?0:((float)even_sum/even_num));
    printf("�����ĸ���Ϊ%ld,���ǵ�ƽ������:%.3f\n",odd_num,(odd_num==0)?0:((float)odd_sum/odd_num));
    return 0;
}

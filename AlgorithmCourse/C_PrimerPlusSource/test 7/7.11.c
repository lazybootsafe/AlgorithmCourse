#include <stdio.h>//��дһ��������ѭ������switch���ʵ���û����벻ͬ����ĸʱ�в�ͬ����Ӧ
#include<ctype.h>
#define ARTICHOKE 2.05  //�󼻼۸�a
#define BEET 1.15  //��˼۸�b
#define CARROT 1.09 //���ܲ��۸�c
#define	DISCOUNT_LIMIT 100  //��װ�Ѻ��˷Ѵ���Ҫ�󶩵�100��Ԫ
#define DISCOUNT_RATE 0.05	//�ۿ�Ϊ%5
#define BREAK1 5
#define BREAK2 20   //�����ֽ��
#define	FEE1 6.5
#define	FEE2 14 //װ�˷ѵķֽ��
#define FEE3_RATE 0.5
//��ͬ���������װ�˷ѣ����г���20����ÿ����һ��
//����0.5Ԫ
int main(void)
{
    char ch;
    double weight=0;
    double weight_a=0,weight_b=0,weight_c=0; //���������߲˵�����
    double total_weight=0;	//������
    double veg_cost=0;		//�����߲��ܹ�����
    double order_cost=0;		//�����ܶ�
    double total_cost=0;		//�����ܶ�
    double pack_tran_fee=0;	//װ�˷�
    double discount=0;    //�ۿ�
    int count = 0;  //�ư���

    printf("��ѡ������Ҫ��Ļ�����ĸ\n");
    printf("a����,b�����,c�Ǻ��ܲ�,q�˳�����.\n");
    while((ch=tolower(getchar())) != 'q')
    {
        switch(ch)
        {
        case 'a':printf("������Ҫ���������:\n");
                scanf("%lf",&weight);
                weight_a+=weight;
                count++;
                printf("��������a,b,c��q:\n");
                break;
        case 'b':printf("������Ҫ���������:\n");
                scanf("%lf",&weight);
                weight_b+=weight;
                count++;
                printf("��������a,b,c��q:\n");
                break;
        case 'c':printf("������Ҫ���������:\n");
                scanf("%lf",&weight);
                weight_c+=weight;
                count++;
                printf("��������a,b,c��q:\n");
                break;
        default:printf("��������ȷ�Ļ�����ĸ");
        }
        while(getchar() != '\n')
            continue;					//�˵�������������������ַ�
    }

    if(!count)
    {
        printf("�ټ�.\n");
        return 0;
    } //��ʼ���q��ֱ���˳�

    total_weight=weight_a+weight_b+weight_c;
    //������
    veg_cost=ARTICHOKE*weight_a + BEET*weight_b +CARROT*weight_c;
    //�����߲��ܻ���
    if(veg_cost>=DISCOUNT_LIMIT)
        {
            discount=veg_cost*DISCOUNT_RATE;
            order_cost=veg_cost-discount;
        }
    else
        order_cost=veg_cost;
    //�ۿۼ���

    if (total_weight<=BREAK1)
        pack_tran_fee=FEE1;
    else if (total_weight<=BREAK2)
        pack_tran_fee=FEE2;
    else
        pack_tran_fee=FEE2+(total_weight-BREAK2)*FEE3_RATE;
    //װ�˷�
    total_cost=order_cost+pack_tran_fee;
    //�����ܶ�

    printf("��Ĺ�����Ϣ����:\n");
    if (weight_a)
        printf("�󼻵���$%-15.2f ������$%-15.2f �󼻷���$%-15.2f\n",ARTICHOKE,weight_a,ARTICHOKE*weight_a);
    if (weight_b)
        printf("��˵���$%-15.2f �������$%-15.2f ��˷���$%-15.2f\n",BEET,weight_b,BEET*weight_b);
    if (weight_c)
        printf("���ܲ�����$%-13.2f ���ܲ�����$%-13.2f ���ܲ�����$%-13.2f\n",CARROT,weight_b,CARROT*weight_c);
    printf("�����߲˵ķ���$%-15.2f\n",veg_cost);
    if (discount)
        printf("�ۿ�$%-15.2f\n",discount);
    printf("�˷ѺͰ�װ��$%-15.2f\n",pack_tran_fee);
    printf("���еķ����ܶ�$%-15.2f\n",total_cost);
    //������Ϣ

    return 0;
}

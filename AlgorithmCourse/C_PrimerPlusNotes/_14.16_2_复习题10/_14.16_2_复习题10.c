#include <stdio.h>
#include <stdlib.h>

//������ģ��
struct gas
{
	float distance;
	float gals;
	float mpg;
};

//a.���һ��������������һ��struct gas �������ٶ����ݽ����Ľṹ����distance��gals��Ϣ��
//����Ϊmpg��Ա��ȷ�����ֵ������������������Ľṹ��

struct gas makeinfoA(struct gas);

//b.���һ��������������struct gas�ĵ�ַ���ٶ����ݽ����Ľṹ����distance��gas��Ϣ��
//����Ϊmpg��Ա��ȷ�����ֵ����������ǡ���ĳ�Ա��

void makeinfoB(struct gas * pst);


int main(void)
{
	//��������
	struct gas gasA = { .distance = 300.0f, .gals = 20 };

	gasA = makeinfoA(gasA); 
	system("color 5A");
	printf("%.2f %.2f %.2f\n", gasA.distance, gasA.gals, gasA.mpg);

	struct gas gasB = gasA;
	struct gas * pst = &gasB;
	makeinfoB(pst);
	printf("%.2f %.2f %.2f\n", gasB.distance, gasB.gals, gasB.mpg);

	getchar();
	return 0;
}

struct gas makeinfoA(struct gas info)
{
	//�Ҳ�����ô��ġ���
	info.mpg = info.distance / info.gals;		//��λ��Ӣ��ÿ����

	return info;
}

void makeinfoB(struct gas * pst)
{
	pst->mpg = pst->distance / pst->gals;
}

#include <stdio.h>
#include <stdlib.h>

/*���в������ຯ�����ʹ��ע�⣺

	��һ���Ժ������ʹ�ñ�����㹻���Բ��������֤����ȷ��˳���������ͽ�ϡ�
	�ڶ�, �����ں�Ĳ�����ʹ������������������������ʱ����ֻ��һ�ε������������㣬����ʵ�ʵ�������Ҳ���ж�ε��������㣩*/

#define SQUARE(X) X * X
	//ϵͳ�Ѻ�����⵱�����Է������͵��ַ������������ַ��͵��ַ�����CԤ�������е����Է����Ǻ궨�������еĵ����ġ��ʡ����ÿհ��ַ�����Щ�ʷֿ���
	//����������#defineָ����3�����Է��ţ�X��*��X��
#define SIX 2*3
	//�ö�������1�����Է��ţ�������2*3��

/*�ض��峣��:

	ANSI��׼ֻ�����¶�����ɶ�����ȫ��ͬ
	��ͬ��ζ������ӵ����ͬ˳������Է��ţ���ˣ���������������ȫ��ͬ:*/
#define SIX 2 * 3
#define SIX 2	*	3
	//2�߶���3����ͬ�����Է��ţ����Ҷ���Ŀո��������һ���֡�����Ķ��屻��Ϊ�ǲ�ͬ�ģ�
#define SIX 2*3
	//��ʽֻ��1��������3�������Է��ţ������ǰ�������岻��ͬ

#define PR(X) printf("The result is %d.\n", X)

int main(void)
{
	int x = 4;
	int z;

	system("color 5A");

	printf("Evaluating SQUARE(x): ");
	z = SQUARE(x);					//��չ��Ϊz = x*x;
	PR(z);							//��չ��Ϊprintf("The result is %d.\n", z);

	printf("Evaluation SQUARE(2): ");
	z = SQUARE(2);					//��չ��Ϊz = 2*2;
	PR(z);							//��չ��Ϊprintf("The result is %d.\n", z);

	printf("Evaluating 100 / SQUARE(2): ");
	PR(100 / SQUARE(2));			/*��չ��Ϊprintf("The result is %d.\n",100 / SQUARE(2));
									-> printf("The result is %d.\n",100 / 2*2);*/
	
	printf("Evaluating SQUARE(++x): ");
	PR(SQUARE(++x));				/*��չ��Ϊprintf("The result is %d.\n", SQUARE(++x));
									-> printf("The result is %d.\n", ++x*++x);
									�Ӵ����Ͽ���x������һ��*/
	getchar();
	printf("Evaluating incrementing, x is %x.\n", x);
									/*x��ʼֵΪ4����ֵֹΪ6������������*/
	getchar();
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define LEN 20

struct names
{
	char first[LEN];
	char last[LEN];
};

struct guy
{
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	//����һ���ṹ����
	struct guy fellow[2] = {
		{
			{ "Ewen", "Villard" },
			"grilled salmon",
			"personality coach",
			58112.00f
		},
		{
			{"Rodney", "Swillbelly"},
			"tripe",
			"tabloid editor",
			232400.00f
		}
	};
	
	//����һ���ṹָ��
	struct guy * him;	/*����һ��ָ��guy�ṹ��ָ�룬����ָͨ�����������
						������������������һ���µĽṹ��������ζ��ָ��him����ָ���κ����е�guy���͵Ľṹ
						  ���磺barney��һ��guy���͵Ľṹ��������������him = &barney;��*/

	system("color 5A");
	printf("address #1: %p, #2: %p\n", &fellow[0], &fellow[1]);						/*��ַ�����ȡ����0��guy���͵Ľṹfellow[0]�͵�1��fellow[1]*/
	him = &fellow[0];	/*���߸�ָ����Ҫָ��ĵ�ַ*/								/*ע������
																					  �ṹ�������һ����֮ͬ����
																								һ����������־��Ǹ�����ĵ�ַ
																								���ǣ�
																								һ���ṹ�����ֲ��Ǹýṹ�ĵ�ַ��
																					  ���Ե�ʹ��
																					  �ṹָ��ָ��ĳ���ṹʱ��Ҫʹ�õ�ַ�����&*/
	printf("pointer #1: %p, #2: %p\n", him, him + 1);								/* him ָ��ṹfellow[0]��
																					   him + 1 ָ����һ���ṹfellow[1],
																					   ����(him+1)-him����84
																					  ����Ϊÿ��guy�ͽṹռ84�ֽ�<�����Լ���һ��Ŷo(����)o>��
																						
																						˳����һ�£���Щϵͳ�У�Ϊ�˱����ڴ�Ķ��룬ϵͳ�����ݵĴ洢�ᵼ�·�϶��
																						���ԣ��ṹ�Ĵ�С�п��ܴ������ڲ�����Ա��С֮�͡���*/
	printf("him->income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);/*		 him->income���Խṹָ��ʹ�ü�ӳ�Ա�����->ȡ���ṹָ��ָ��Ľṹ�ĳ�Ա
																									*him).income���Խṹ����ʹ�ýṹ��Ա�����. ȡ���ṹ�ĳ�Ա

																						���ԣ����->�Ľṹָ��ͺ��. �Ľṹ����һ���ġ�������ýṹָ��ָ��ýṹ��
																						*/
	him++;				/*ָ����һ���ṹ*/
	printf("him->favfood is %s: him->handle.last is %s\n", him->favfood, him->handle.last);
	
	system("pause");
	return 0;
}
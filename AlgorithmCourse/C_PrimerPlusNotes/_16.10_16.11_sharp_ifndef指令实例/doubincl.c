//doubinc.c -- ���ΰ���ͬһͷ�ļ�
#include <stdio.h>
#include "names_st.h"
#include "names_st.h"			/*��С�����ΰ���ͬһͷ�ļ�
								  ������Ϊ����ͷ�ļ����з�ֹ�ظ������Ĵ��롣���ԣ���Ȼ�������Σ�����ֹ���ظ����壨����ṹ���壬ֻ����һ�ζ��壩
								  ���ȥ����ͷ�ļ��е�ifndefָ���������Ͳ���ͨ������*/

int main(void)
{
	names winner = { "Less", "Ismoor" };

	printf("The winner is %s %s.\n", winner.first, winner.last);

	return 0;
}
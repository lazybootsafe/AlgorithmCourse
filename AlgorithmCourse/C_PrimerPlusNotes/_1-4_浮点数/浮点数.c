#include <stdio.h>
#include<math.h>

int main(void)
{
	float about = 43215.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;

	//��ӡ������
	printf("%f �� %e �� %E �� %a �� %A\n", about, about, about, about, about);		//%e(%E)�ǰ���e(ָ��/��ѧ)��������ӡ��%a(%A)��ӡ��ʮ������
	printf("%lf �� %e �� %E �� %a �� %A\n", abet, abet, abet, abet, abet);
	printf("%f �� %e �� %E �� %a �� %A\n\n", dip, dip, dip, dip, dip);

	//������������
	float toobig = 3.4e38*100.0f;		//3.4e38*100.0f�Ľ������float��Χ���������磬printf()��ӡ��һ����������������ֵxx#INFxx,infinity��inf֮���
	printf("%f\n\n", toobig);		//1.#INF00

	//������������ ̫���ӣ����Ҳ���O(��_��)O
	/*���⣬��һ������ĸ�����"NaN"(Not a Number).��asin()�����Һ����Ĳ���������(0,1)֮��(���Һ�����ֵ����(0,1)),
	  ����û�г���1������ֵ(����)���������(0,1)����Ĳ���������ֵΪNaN��������һ������printf()��������ֵ��ӡΪxx#INDxx,nan,NaN,��������ʽ��ʾ������*/
	double fl = asin(1.1e3);
	printf("%f\n", fl);  //-1.#IND00

	getchar();
	return 0;

}
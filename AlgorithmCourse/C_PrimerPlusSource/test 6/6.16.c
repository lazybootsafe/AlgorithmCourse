#include <stdio.h> //100�ĵ���Ϣ�͸����Ƚ�
#include <math.h>
#define DEI 0.05 //dei ����
#define DAP 0.1  //dap ����
int main(void)
{
    float dei=100.0, dap=100.0, x;  //dei��dap������100
	int n;

	for( n = 1, x = 0.0; x >= 0; n++)
	{
		dap = 100+DAP * 100 * n;
		dei = 100*pow(1+DEI,n) ;
		x = dap - dei;
	}
    printf("%d\n", n-1);//ע��forѭ��˳�򣺵�����ĳ��ѭ��ʵ�ַ������Ի����n�ټ����Ƚϣ��õ����������˳�ѭ���󣬴�ʱn�Ѿ�+1��
    printf("dap:%f\tdei:%f\n", dap, dei);

    system("pause");
    return 0;
}

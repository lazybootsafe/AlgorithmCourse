/*�������
#include <stdio.h>
int main(void)
(		//��һ��
int n, int n2, int n3;		// �ڶ���
/*�ó����м�������		// ������

n=5;
n2=n*n;
n3=n2*n2;		//���Ĵ�(����һ�����"n cubed = %d"֪��)
printf("n = %d, n squared = %d, n cubed = %d",n,n2,n3);
return 0;

)		//��һ��
*/

//���������ȷ����
#include <stdio.h>
int main(void)
{
	int n, n2, n3;
	n = 5;
	n2 = n*n;
	n3 = n2*n;
	printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);
	getchar();
	return 0;

}
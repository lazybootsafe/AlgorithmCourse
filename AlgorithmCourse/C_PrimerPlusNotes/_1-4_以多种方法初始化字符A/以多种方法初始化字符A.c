//�Զ��ַ�ʽ��ʼ��һ���ַ�A
#include <stdio.h>

int main(void)
{
	char ch_1 = 'A';		
	char ch_2 = 65;		 //A��ʮ����ASCII��
	char ch_3 = '\101';  //A�İ˽���ASCII��
	char ch_4 = '\x41';  //A��ʮ������ASCII��
	char ch_5 = '\X41';  //c(10): warning C4129: ��pX��: ����ʶ����ַ�ת������;c(10): warning C4305: ����ʼ����: �ӡ�int������char���ض�
	char ch_6 = 'Ů';	 //c(11): warning C4305: ����ʼ����: �ӡ�int������char���ض�

	printf("%c\n", ch_1);  //A
	printf("%c\n", ch_2);  //A
	printf("%c\n", ch_3);  //A
	printf("%c\n", ch_4);  //A
	printf("%c\n", ch_5);  //1
	printf("%c\n", ch_6);  //?
	
	getchar();
	return 0;

}
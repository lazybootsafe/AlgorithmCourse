#include <stdio.h>  //����stdioͷ�ļ�(standard input and output)��׼�������ͷ�ļ�
void butler(void);  //�����Զ��庯��
int main(void)
{
	printf("I will summon the butler function.\n");
	butler();
	printf("Yes.Bring me some tea and writeable CD-ROMs.\n");
	getchar();
	return 0;

}

void butler(void)	//butler��������Ŀ�ʼ(����ͷ)��"{}"��Ϊ������
{
	printf("You rang, sir?\n");
}
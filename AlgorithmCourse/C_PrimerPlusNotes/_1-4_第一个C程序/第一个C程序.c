#include <stdio.h>	//����stdioͷ�ļ�,��׼�������ͷ�ļ����ڲ���װ�������()�͹ؼ��֣���Ŀ�ĵ���printf������ʽ����ӡ

int main(void)		//��־main����
{
	int num;		//������䣬�������͵�num����
	int a;
	num = 1;		//��ֵ��䣬Ϊnum��ֵ
	
	//���岿���붯�����ַֿ�
	a = printf("I'm a simple ");	//����������䣬����printf��������ʽ����ӡ��һ��(�ú����ķ���ֵ�Ǵ�ӡ���ַ��ĳ���)
	printf("computer.\n");			//ͬ��
	printf("My favourite number is %d because it is first.\n", num);	//��ʽ����ӡ�ڶ���,%ָ��num�����λ�ã�dΪ��num����ʮ�����������
	printf("%d", a);
	getchar();	//�ȴ��û����룬��ֹ��Ļһ������
	return 0;	//������䣬����0ֵ
}
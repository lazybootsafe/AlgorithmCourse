#include <stdio.h>

int main(void)
{
	//�����û���������ֵĺ�
	long num, sum = 0L;		//��ʼ��longֵΪ0�������
	int status;				//��ʼ��scanf()�ķ���ֵ�����ɹ�ɨ���������Ŀ��

	printf("Please enter an integer to be sumed");
	printf("����q��to quit��:");
	status = scanf_s("%ld", &num,10);
	while (status = 1)		//status��������Ϊ1.��������ѭ��
	{
		sum = sum + num;
		printf("Please enter next number to sum: ");
		status = scanf_s("%ld", &num);/*��scanfδ�ܶ�ȡlongֵ����������������û������
									    ���´ζ�ȡʱ���Ӷ�ȡʧ�ܵĵط�������ȡ֮ǰ������
										�ڸ�ʧ�ܵ�ѭ�����ڣ�����scanfһ����ȡʧ�ܣ������޶�ȡʧ��
										Ҳ����˵���ĳ�����벻��������ʧ�ܵ�����ѭ����Ҳ�����ʧ�ܵ����޶�ȡ*/
	}
	printf("Those integers sum to %ld.\n", sum);

	getchar();
	getchar();
	getchar();
	return 0;
}
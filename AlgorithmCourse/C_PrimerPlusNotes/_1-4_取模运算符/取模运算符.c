#include <stdio.h>
#define SEC_PER_MIN 60	//ÿ����60��
int main(void)
{
	//ȡ�������Ҳ������
	printf("Convetion For seconds����Ӣ�ﲻ̫�ã���ž������ʶ����\n");
	int sec, min, left;	//ʣ�����˼

	printf("Please enter a second-number:��<=0 to quit��\n");
	scanf_s("%d", &sec, 10);
	while (sec > 0)
	{
		min = sec / SEC_PER_MIN; //���������,��������ֻ�����������֣��ƺ�ȡ��������ڱ�׼��ѧ��ͷ�ļ����Ҫ��Ҳ�У�
		left = sec % SEC_PER_MIN; //ȡģ���㲻��1���ӵ�����
		printf("%d seconds is %d minutes and %d seconds\n", sec, min, left);
		printf("Please enter another second-number:(<=0 to quit)\n");
		scanf_s("%d", &sec, 10);
	}
	printf("Done!\n");
	getchar();
	getchar();
	return 0;
}
#include <stdio.h>
#include <string.h>
#define BLURB "Authentic imitation!"

int main(void)
{
	printf("/%2s/\n\n", BLURB);//��ӡ�ַ�������̳���Ϊ2
	printf("/%24s/(��%d)\n\n", BLURB, strlen(BLURB));//��ӡ�ַ�������̳���Ϊ24�����λ�ÿո����
	printf("/%24.5s/\n\n", BLURB);//��ӡ�ַ�������̳���Ϊ24����ӡ�ַ����ĺ�5���ַ������λ�ÿո����
	printf("/%-24.5s/\n\n", BLURB);//��ӡ�ַ�������̳���Ϊ24����ӡ�ַ����ĺ�5���ַ������λ�ÿո���䣬������ӡ���ַ����ո���ң�
	//printf("/%+24.5s/\n\n", BLURB);//��ʾ���ţ�Ŷ���ַ����޷���

	getchar();
	return 0;

}
#include <stdio.h>

int main(void)
{
	//CĬ�Ϸ�0ֵΪ�棬0ֵΪ��
	int n = 3;

	while (n)
		printf("ѭ����1��n = %d\n", n--);
	printf("\n����ѭ��1��n = %d\n\n", n);

	n = -3;
	while (n)
		printf("ѭ����2��n = %d\n", n++);
	printf("\n����ѭ��2��n = %d\n\n", n);

	int goast = 7;
	while (goast)		//�ȼ���while(goast!= 0),����Ա����д��
	{
		;//д�����
	}
	return 0;
}
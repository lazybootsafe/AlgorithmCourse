#include <stdio.h>

int main(void)
{
	/*sizeof���������size_t����ֵ���޷��ţ�������������
	�������ݶ�������͵Ĵ�С���������������͵�ʱ�򣬱���������������
	��printf()����еĸ�ʽ˵������%zd��z����˵����sizeof�ķ���ֵ���ͣ�
	���%zd�����ã�������%u��%lu,��Ҳ˵��sizeof�ķ���ֵ����size_t���޷����������ͣ�����Ϊ�޷��ų���������
	*/
	int n = 10;
	size_t intsize = sizeof (int);
	
	printf("%d has %u bytes,and all ints has %u bytes.\n", n, sizeof n, intsize);

	getchar();
	return 0;
}
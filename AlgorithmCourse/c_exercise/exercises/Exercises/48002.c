#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char name[20] = { 0 };
	int width = 0;
	printf("Enter your name: ");
	scanf_s("%s", &name, 19);
	width = printf("\"%s\".\n", name);
	width -= 4;		//����˫���š���źͽ������õ��ַ�������
	printf("\"%20s\".\n", name);	//���ô�ӡ�ַ�������Ϊ20(Ŀ���ִ������ÿո���ǰ���)
	printf("\"%-20s\".\n", name);	//���ô�ӡ�ַ�������Ϊ20(Ŀ���ִ������ÿո�������)
	printf("\"%*s\".", (width + 3), name);	//ʹ��*���η�ָ����ӡ���

	return 0;
}

#endif
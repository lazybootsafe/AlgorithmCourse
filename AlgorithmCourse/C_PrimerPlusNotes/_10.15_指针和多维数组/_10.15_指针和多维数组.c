#include <stdio.h>
#include <stdlib.h>

#define COLOR system("Color 4F")

int main(void)
{
	COLOR;

	int zippo[4][2] = { { 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 } };

	printf("   zippo = %p,    zippo + 1 = %p\n", zippo, zippo + 1);		// zippo��������Ԫ��{2��4}�ĵ�ַ
																		// zippo+1����1��Ԫ��{6��8}�ĵ�ַ	��zippoֵ����1��ʾ����һ�������С������8��
	
	printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);// zippo[0]������{2��4}��Ԫ�صĵ�ַ����2�ĵ�ַ �������������������������������1
																		// zippo[0]+1������{2��4}��4�ĵ�ַ  ��zippo[0]ֵ����1��ʾ����һ�������С������4��
	
	printf("  *zippo = %p,   *zippo + 1 = %p\n", *zippo, *zippo + 1);	// *zippo��ȡֵΪ����{2��4}��Ԫ��2�ĵ�ַ  �������������������������������������2
																		// *zippo+1: ȡֵΪ����{2��4}��4�ĵ�ַ
	//���1�����2��ӡ��ֵ����ͬ��

	printf("  zippo[0][0] = %d\n", zippo[0][0]);	//��ӡ2
	printf("    *zippo[0] = %d\n", *zippo[0]);		//��ӡ2
	printf("      **zippo = %d\n", **zippo);		//��ӡ2

	printf("  zippo[2][1] = %d\n", zippo[2][1]);	//��ӡ3

	printf("*(*(zippo+2)) = %d\n", *(*(zippo + 2)));//��ӡ1

	getchar();
	return 0;
}
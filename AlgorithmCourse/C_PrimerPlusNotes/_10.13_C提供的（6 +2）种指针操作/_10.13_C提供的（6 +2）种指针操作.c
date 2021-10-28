#include <stdio.h>
#include <stdlib.h>

#define COLOR system("color 4E")

int main(void)
{
	COLOR;

	int urn[5] = { 100, 200, 300, 400, 500 };
	int * ptr1, *ptr2, *ptr3;

	ptr1 = urn;			//��һ����ַ����ָ��
	ptr2 = &urn[2];		//ͬ��
	//ȡ��ָ��ָ���ֵ
	//���ҵõ�ָ��ĵ�ַ
	printf("pointer value, dereferenced pointer, pointer address:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
		ptr1, *ptr1, &ptr1);

	ptr3 = ptr1 + 4;	/*ָ��ӷ�
						1.ָ���ָ���ͬ��һ��ļӷ�
						2.ָ�������ʱ������������ָ����ָ���͵��ֽ�����ˣ�Ȼ�����õĽ����ӵ���ʼ��ַ��
						��ָ��ָ�������Ԫ�س������鷶Χʱ������ǲ�ȷ���ģ����ǳ����������һ��Ԫ�صĵ�ַ�ܹ���֤����Ч�ģ�
						����Ч�ġ�Խ�硱ָ��ֻ�����������һ��Ԫ�ص���һ����Ԫ�ء���ַ��*/
	printf("\nadding an int to a pointer: \n");
	printf("ptr1 + 4 = %p, *(ptr1 + 3) = %d\n",
		ptr1 + 4, *(ptr1 + 3));

	ptr1++;				//����ָ��
	printf("\nvalues after ptr1++\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
		ptr1, *ptr1, &ptr1);

	ptr2--;				//�ݼ�ָ��
	printf("\nvalues after --ptr2\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
		ptr2, *ptr2, &ptr2);

	--ptr1;				//�ָ�Ϊ��ʼֵ
	++ptr2;				//�ָ�Ϊ��ʼֵ
	printf("\nPointers reset to original values:\n");
	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

	//һ��ָ���ȥ��һ��ָ�루�õ��Ĳ�ĵ�λ����ָ�����͵��ֽڴ�С��ͨ��������һ��������2��Ԫ��֮�������ٵ����ʹ�С��
	printf("\nsubstracting one pointer from another:\n");
	printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %d\n",		//ptr2 - ptr1�������Ԫ��֮��ľ���Ϊ(ptr2 - ptr1)��int��ֵ��С
		ptr2, ptr1, ptr2 - ptr1);

	//һ��ָ���ȥһ������(�ȼ���ָ���ȥָ�����ʹ�С��������)
	printf("\nsubstracting an int from a pointer;\n");
	printf("ptr3 = %p, ptr3 - 2 = %p\n",
		ptr3, ptr3 - 2);

	getchar();
	return 0;

}
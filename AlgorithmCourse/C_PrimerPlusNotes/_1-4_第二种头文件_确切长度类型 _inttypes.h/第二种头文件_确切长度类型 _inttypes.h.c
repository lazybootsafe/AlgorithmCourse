#include <stdio.h>
#include <inttypes.h>		//֧����������int16_t,int_least32_t��int_fast32_t

int main(void)
{
	int16_t me16 = 32767;		//16λ�з�������,Ҳ����short����(-32768,32767)
	int_least32_t le32 = 3423453;	//32λ�����������
	int_fast32_t fa32 = 3423453;	//32λ�����������

	printf("First,assume int16_t is short:\n");		//�ٶ���Jm, ������16λ��short���͵ġ���������
	printf("me16 = %hd\n\n", me16);

	printf("Next,let's not make any assumption\n\n");

	printf("Instead,let's use \"macro\" from inttypes.h:\n");
	printf("me16 = %"PRId16"\n", me16);		//PRId16="d"
	printf("me16 = %""d""\n", me16);
	printf("me16 = %d\n\n", me16);

	printf("le32= %"PRId32"\n", le32);
	printf("le32= %d\n\n", le32);

	printf("fa32= %"PRId32"\n", fa32);
	printf("fa32= %d\n", fa32);

	getchar();
	return 0;

}
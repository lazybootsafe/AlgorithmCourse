/*4.��дһ�����򣬽�������int���͵Ĳ�����һ����ֵ��һ����λ��λ
�á����ָ��λ��λ��Ϊ1���ú�������1�����򷵻�0����һ�������в���
�ú�����*/

#include <stdio.h>

int check_bit(int num,int b);

int main(void)
{
    int num,bit;

    puts("����һ��������λ�ã�");
    while( (scanf("%d%d",&num,&bit)) != 2)
    {
        printf("����������.");
        while(getchar() != '\n') continue;
    }
    while(getchar() != '\n') continue;
    printf("%d�Ķ����Ƶ�%dλ��%d.\n",num,bit,check_bit(num,bit));

	return 0;
}

int check_bit(int num,int b)
{
	for(int i=0;i<b;i++)
        num>>=1;//��ͬ��num/=2

	return num&1;//num&01����num���һλ��ֵ
}
